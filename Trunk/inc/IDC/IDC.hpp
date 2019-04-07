
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

namespace idc
{
	class IDC
	{
		public:
			IDC();
			virtual ~IDC();
	};
}

#endif // IDC_HPP
