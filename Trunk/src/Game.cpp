
// Author: Pierce Brooks

#include <IDC/Game.hpp>
#include <iostream>
#include <fstream>

idc::Game::Game(int target) :
    background(nullptr),
    backgroundTexture(nullptr)
{
    bool error;
    unsigned int index = 0;
    std::string line = "";
    std::string data = "";
    std::ifstream file = std::ifstream();
    //file.open(std::string("./Assets/songs/song"+std::to_string(target)+"_ttt_nomark.txt").c_str());
    file.open("./Assets/songs/test.txt");
    while (std::getline(file, line).good())
    {
        std::cout << index << " = \"" << line << "\"" << std::endl;
        data += line;
        data.push_back('\n');
        ++index;
    }
    std::cout << "\"" << data << "\"" << std::endl;
    backgroundTexture = new sf::Texture();
    if (backgroundTexture->loadFromFile("./Assets/backgrounds/game_bkg_1.png"))
    {
        background = new sf::Sprite();
        background->setTexture(*backgroundTexture);
    }
    if ((backgroundTexture != nullptr) != (background != nullptr))
    {
        delete background;
        delete backgroundTexture;
        background = nullptr;
        backgroundTexture = nullptr;
    }
    fret = new sf::Sprite(*IDC::loadTexture("./Assets/fretboard/fret_board_bkg.png"));
    fret->setOrigin(static_cast<float>(fret->getTexture()->getSize().x)*0.5f, 0.0f);
    streams.push_back(new Stream(-1, "./Assets/buttons/circle/circle_1.png"));
    streams.push_back(new Stream(0, "./Assets/buttons/square/square_1.png"));
    streams.push_back(new Stream(1, "./Assets/buttons/triangle/triangle_1.png"));
    song = new idc::parser::Song();
    error = song->load_data(data);
    music = new sf::Music();
    music->openFromFile("./Assets/songs/rhythm0"+std::to_string(target)+".wav");
    music->play();
    std::cout << error << std::endl;
    if (error)
    {
        std::cout << song->get_error() << std::endl;
    }
	else
	{
		std::cout << song->to_string() << std::endl << std::endl;
		std::vector<idc::parser::Song::SeekResult> results = song->seek(8.f,12.f,60.f);
		std::cout << "found " << results.size() << std::endl;
		for (std::vector<idc::parser::Song::SeekResult>::iterator it = results.begin(); it != results.end(); ++it)
        {
            std::cout << (*it).to_string() << std::endl;
        }
	}
}

idc::Game::~Game()
{
    delete song;
    delete music;
    delete background;
    delete backgroundTexture;
    delete fret;
    for (int i = 0; i != streams.size(); ++i)
    {
        delete streams[i];
    }
    streams.clear();
}

void idc::Game::handle(sf::RenderWindow* window, float deltaTime)
{
    //std::cout << deltaTime << std::endl;
    auto seek = song->seek(deltaTime, deltaTime+5.0f, music->getDuration().asSeconds());
    for (int i = 0; i != seek.size(); ++i)
    {
        std::cout << seek[i].to_string() << std::endl;
    }
    //backgroundOffset += sf::Vector2f(static_cast<float>((rand()%50)-25), static_cast<float>((rand()%50)-25))*deltaTime;
    if (background != nullptr)
    {
        background->setOrigin(sf::Vector2f(backgroundTexture->getSize())*0.5f);
        background->setPosition(sf::Vector2f(window->getSize())*0.5f);
        //background->move(backgroundOffset);
        window->draw(*background);
        fret->setPosition(background->getPosition());
        fret->move(-fret->getOrigin().x*1.5f, -background->getPosition().y);
    }
    window->draw(*fret);
    for (int i = 0; i != streams.size(); ++i)
    {
        streams[i]->handle(fret, window, deltaTime);
    }
}
