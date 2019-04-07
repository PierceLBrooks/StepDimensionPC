
// Author: Pierce Brooks

#include <IDC/Game.hpp>
#include <iostream>

idc::Game::Game() :
    background(nullptr),
    backgroundTexture(nullptr)
{
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
    fret = new sf::Sprite(*IDC::loadTexture("./Assets/fret.png"));
    fret->setOrigin(static_cast<float>(fret->getTexture()->getSize().x)*0.5f, 0.0f);
}

idc::Game::~Game()
{
    delete background;
    delete backgroundTexture;
}

void idc::Game::handle(sf::RenderWindow* window, float deltaTime)
{
    //std::cout << deltaTime << std::endl;
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
}
