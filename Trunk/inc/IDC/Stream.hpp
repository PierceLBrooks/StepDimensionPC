
// Author: Pierce Brooks

#ifndef STREAM_HPP
#define STREAM_HPP

#include <IDC/IDC.hpp>

namespace idc
{
    class Stream
    {
        public:
            Stream(int offset, const std::string& type);
            ~Stream();
            void stream(sf::Sprite* fret);
            void handle(sf::Sprite* fret, sf::RenderWindow* window, float deltaTime);
            void setFocus(bool focus);
            bool getFocus() const;
            float getScore() const;
        private:
            sf::Sprite* marker;
            std::vector<sf::Sprite*> notes;
            bool focus;
            float score;
            int offset;
    };
}

#endif // STREAM_HPP

