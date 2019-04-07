
// Author: Pierce Brooks

#ifndef IDC_HPP
#define IDC_HPP

// SFML
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// IDCP
#include <Bpm.hpp>
#include <Note.hpp>
#include <Song.hpp>
#include <Sud.hpp>

#include <cstdlib>
#include <ctime>

#define TRIANGLE 1
#define SQUARE 0
#define CIRCLE -1

#define FLOW 5.0f
#define STEP 0.125f

namespace idc
{
	class IDC
	{
		public:
			IDC();
			virtual ~IDC();
            static sf::Texture* loadTexture(const std::string& path);
            static sf::Sound* loadSound(const std::string& path);
            static void load();
            static void unload();
            static IDC* getSelf();
            static sf::Font* getFont();
        private:
            static std::map<std::string, sf::Texture*>* textures;
            static std::map<std::string, std::pair<sf::SoundBuffer*, sf::Sound*>>* sounds;
            static IDC* self;
            sf::Font* font;
	};
}

#endif // IDC_HPP
