
// Author: Pierce Brooks

#include <IDC/IDC.hpp>
#include <IDC/Game.hpp>
#include <vector>
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
    new idc::IDC();
    idc::IDC::load();
    bool active = true;
    sf::Clock* clock = new sf::Clock();
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "IDC");
	idc::Game* game = new idc::Game();
	std::vector<std::string> arguments;
	for (int i = 0; i != argc; ++i)
	{
		arguments.push_back(std::string(argv[i]));
		std::cout << i << " = " << arguments.back() << std::endl;
	}
	clock->restart();
	while (window->isOpen())
    {
        sf::Event event;
        while (active ? window->pollEvent(event) : window->waitEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    active = false;
                    window->close();
                    break;
            }
        }
        if (!active)
        {
            continue;
        }
        window->clear(sf::Color::Black);
        game->handle(window, clock->restart().asSeconds());
        window->display();
    }
	delete game;
	delete window;
	delete clock;
	idc::IDC::unload();
	return 0;
}

