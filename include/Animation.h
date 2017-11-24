#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Animation
{
    public:
        Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
        virtual ~Animation();

        void update(int row, float deltaTime/*, bool faceRight*/);
        sf::IntRect getUvRect() { return uvRect; }

    private:
        sf::Vector2u m_imageCount;
        sf::Vector2u m_currentImage;
        sf::IntRect uvRect;

        float m_totalTime;
        float m_switchTime;

};

#endif // ANIMATION_H
