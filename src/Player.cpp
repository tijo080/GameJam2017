#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) : m_animation(texture, imageCount, switchTime)
{
    this->m_speed = speed;
    m_row = 0;
    //m_faceRight = true;

    m_body.setSize(sf::Vector2f(100.0f, 150.0f));
    m_body.setPosition(100.0f, 125.0f);
    m_body.setTexture(texture);
}

Player::~Player()
{
    //dtor
}

void Player::update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement.x -= m_speed * deltaTime;
        m_row = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += m_speed * deltaTime;
        m_row = 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        movement.y -= m_speed * deltaTime;
        m_row = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        movement.y += m_speed * deltaTime;
        m_row = 2;
    }
    /*
    if (movement.x == 0.0f)
        m_row = 0;
    else
    {
        m_row = 1;

        if (movement.x > 0.0f)
            m_faceRight = false;
        else
            m_faceRight = true;
    }
    */
    m_animation.update(m_row, deltaTime/*, m_faceRight*/);
    m_body.setTextureRect(m_animation.getUvRect());
    m_body.move(movement);
}






















