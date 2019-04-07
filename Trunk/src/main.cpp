
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
    float deltaTime = 0.0f;
    sf::Clock* clock = new sf::Clock();
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "IDC");
	idc::Game* game;
	std::vector<std::string> arguments;
	for (int i = 0; i != argc; ++i)
	{
		arguments.push_back(std::string(argv[i]));
		std::cout << i << " = " << arguments.back() << std::endl;
	}
	if (arguments.size() < 2)
    {
        goto finish;
    }
	game = new idc::Game(atoi(arguments.back().c_str()));
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
        deltaTime = clock->restart().asSeconds();
        if (deltaTime > STEP)
        {
            int steps = 2;
            while (deltaTime/static_cast<float>(steps))
            {
                ++steps;
            }
            for (int i = 0; i != steps; ++i)
            {
                if (!game->handle(window, deltaTime/static_cast<float>(steps)))
                {
                    window->close();
                    continue;
                }
            }
        }
        else
        {
            if (!game->handle(window, deltaTime))
            {
                window->close();
                continue;
            }
        }
        window->display();
    }
	delete game;
	finish:
	delete window;
	delete clock;
	idc::IDC::unload();
	return 0;
}

