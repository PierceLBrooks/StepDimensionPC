
// Author: Pierce Brooks

#ifndef GAME_HPP
#define GAME_HPP

#include <IDC/IDC.hpp>
#include <IDC/Stream.hpp>
#include <vector>

namespace idc
{
	class Game
	{
		public:
			Game(int target);
			virtual ~Game();
			void handle(sf::RenderWindow* window, float deltaTime);
        private:
            sf::Vector2f backgroundOffset;
            sf::Sprite* background;
            sf::Texture* backgroundTexture;
            sf::Sprite* fret;
            std::vector<Stream*> streams;
            idc::parser::Song* song;
            sf::Music* music;
	};
}

#endif // GAME_HPP
