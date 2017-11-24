#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->m_imageCount = imageCount;
    this->m_switchTime = switchTime;
    m_totalTime = 0;
    m_currentImage.x = 0;

    uvRect.width  = texture->getSize().x / float(m_imageCount.x);
    uvRect.height = texture->getSize().y / float(m_imageCount.y);
    //std::cout << uvRect.width << " and " << uvRect.height << std::endl;
}

Animation::~Animation()
{

}

void Animation::update(int row, float deltaTime/*, bool faceRight*/)
{
    m_currentImage.y = row;
    m_totalTime += deltaTime;

    if (m_totalTime > m_switchTime)
    {
        m_totalTime -= m_switchTime;
        m_currentImage.x++;

        if (m_currentImage.x >= m_imageCount.x)
        {
            m_currentImage.x = 0;
        }
    }

    /*
    uvRect.top = m_currentImage.y * uvRect.height;

    if (faceRight)
    {
        uvRect.left = m_currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }
    else
    {
        uvRect.left = (m_currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
    */

    uvRect.left = m_currentImage.x * uvRect.width;
    uvRect.top  = m_currentImage.y * uvRect.height;
    //std::cout << uvRect.left << " and " << uvRect.top << std::endl;

}
