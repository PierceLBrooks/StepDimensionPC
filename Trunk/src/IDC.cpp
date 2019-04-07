
// Author: Pierce Brooks

#include <IDC/IDC.hpp>
#include <map>
#include <string>

std::map<std::string, sf::Texture*>* idc::IDC::textures = nullptr;
std::map<std::string, std::pair<sf::SoundBuffer*, sf::Sound*>>* idc::IDC::sounds = nullptr;

idc::IDC::IDC()
{
    srand(time(NULL));
}

idc::IDC::~IDC()
{
}

sf::Texture* idc::IDC::loadTexture(const std::string& path)
{
    sf::Texture* texture = nullptr;
    if (textures == nullptr)
    {
        return texture;
    }
    std::map<std::string, sf::Texture*>::iterator iter = textures->find(path);
    if (iter != textures->end())
    {
        texture = iter->second;
    }
    else
    {
        texture = new sf::Texture();
        if (!texture->loadFromFile(path))
        {
            delete texture;
            texture = nullptr;
            return texture;
        }
        (*textures)[path] = texture;
    }
    return texture;
}

sf::Sound* idc::IDC::loadSound(const std::string& path)
{
    sf::Sound* sound = nullptr;
    if (sounds == nullptr)
    {
        return sound;
    }
    std::map<std::string, std::pair<sf::SoundBuffer*, sf::Sound*>>::iterator iter = sounds->find(path);
    if (iter != sounds->end())
    {
        sound = std::get<1>(iter->second);
    }
    else
    {
        sf::SoundBuffer* buffer = new sf::SoundBuffer();
        if (!buffer->loadFromFile(path))
        {
            delete buffer;
            return sound;
        }
        sound = new sf::Sound();
        sound->setBuffer(*buffer);
        //sound->setVolume(DEFAULT_VOLUME);
        (*sounds)[path] = std::pair<sf::SoundBuffer*, sf::Sound*>(buffer, sound);
    }
    return sound;
}

void idc::IDC::load()
{
    if (textures == nullptr)
    {
        textures = new std::map<std::string, sf::Texture*>();
    }
    if (sounds == nullptr)
    {
        sounds = new std::map<std::string, std::pair<sf::SoundBuffer*, sf::Sound*>>();
    }
}

void idc::IDC::unload()
{
    if (textures != nullptr)
    {
        for (std::map<std::string, sf::Texture*>::iterator iter = textures->begin(); iter != textures->end(); ++iter)
        {
            delete iter->second;
        }
        textures->clear();
        delete textures;
        textures = nullptr;
    }
    if (sounds != nullptr)
    {
        for (std::map<std::string, std::pair<sf::SoundBuffer*, sf::Sound*>>::iterator iter = sounds->begin(); iter != sounds->end(); ++iter)
        {
            delete std::get<0>(iter->second);
            delete std::get<1>(iter->second);
        }
        sounds->clear();
        delete sounds;
        sounds = nullptr;
    }
}
