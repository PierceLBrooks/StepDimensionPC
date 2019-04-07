
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
}

idc::Game::~Game()
{
    delete background;
    delete backgroundTexture;
}

void idc::Game::handle(sf::RenderWindow* window, float deltaTime)
{
    std::cout << deltaTime << std::endl;
    if (background != nullptr)
    {
        background->setOrigin(sf::Vector2f(backgroundTexture->getSize())*0.5f);
        background->setPosition(sf::Vector2f(window->getSize())*0.5f);
        window->draw(*background);
    }
}
