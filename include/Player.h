#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
    public:
        Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
        virtual ~Player();

        void update(float deltaTime);
        sf::RectangleShape getBody() { return m_body; }

    private:
        sf::RectangleShape m_body;
        Animation m_animation;
        unsigned int m_row;
        float m_speed;
        bool m_faceRight;
};

#endif // PLAYER_H
