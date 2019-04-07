
// Author: Pierce Brooks

#include <IDC/Stream.hpp>

idc::Stream::Stream(int offset, const std::string& type) :
    offset(offset),
    focus(false),
    score(0.0f)
{
    marker = new sf::Sprite();
    marker->setTexture(*idc::IDC::loadTexture(type));
    marker->setOrigin(sf::Vector2f(marker->getTexture()->getSize())*0.5f);
}

idc::Stream::~Stream()
{
    for (int i = 0; i != notes.size(); ++i)
    {
        delete notes[i];
    }
    notes.clear();
    delete marker;
}

void idc::Stream::stream(sf::Sprite* fret)
{
    notes.push_back(new sf::Sprite(*marker->getTexture()));
    notes.back()->setScale(notes.back()->getScale()*0.5f);
    notes.back()->setOrigin(marker->getOrigin());
    notes.back()->setPosition(marker->getPosition().x, fret->getPosition().y);
    notes.back()->move(0.0f, 0.0f);
}

void idc::Stream::handle(sf::Sprite* fret, sf::RenderWindow* window, float deltaTime)
{
    sf::FloatRect intersection;
    for (int i = 0; i != notes.size(); ++i)
    {
        notes[i]->move(0.0f, (static_cast<float>(fret->getTexture()->getSize().y)*deltaTime)/FLOW);
        intersection = sf::FloatRect();
        if ((notes[i]->getPosition().y > marker->getPosition().y) || ((focus) && (marker->getGlobalBounds().intersects(notes[i]->getGlobalBounds(), intersection))))
        {
            if (!focus)
            {
                score *= 0.5f;
            }
            score += intersection.width*intersection.height;
            delete notes[i];
            notes.erase(notes.begin()+i);
            --i;
            continue;
        }
        window->draw(*notes[i]);
    }
    marker->setPosition(fret->getPosition());
    marker->move(static_cast<float>(fret->getTexture()->getSize().x)*static_cast<float>(offset)*0.3f, static_cast<float>(fret->getTexture()->getSize().y)-marker->getOrigin().y);
    if (focus)
    {
        marker->setScale(fret->getScale()*1.125f);
        score -= 1.0f;
    }
    else
    {
        marker->setScale(fret->getScale());
    }
    //marker->rotate(static_cast<float>((rand()%50)-25)*deltaTime);
    window->draw(*marker);
}

void idc::Stream::setFocus(bool focus)
{
    this->focus = focus;
}

bool idc::Stream::getFocus() const
{
    return focus;
}

float idc::Stream::getScore() const
{
    return score;
}
