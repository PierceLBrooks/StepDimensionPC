
// Author: Pierce Brooks

#ifndef GAME_HPP
#define GAME_HPP

#include <IDC/IDC.hpp>

namespace idc
{
	class Game
	{
		public:
			Game();
			virtual ~Game();
			void handle(sf::RenderWindow* window, float deltaTime);
        private:
            sf::Vector2f backgroundOffset;
            sf::Sprite* background;
            sf::Texture* backgroundTexture;
            sf::Sprite* fret;
	};
}

#endif // GAME_HPP
