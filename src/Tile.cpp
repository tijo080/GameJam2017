#include "Tile.h"

Tile::Tile(sf::Texture* texture, sf::Vector2u tileCount) : m_TileCount(tileCount), m_Row(tileCount.x), m_Column(tileCount.y)
{
    m_UvRect.width  = texture->getSize().x / int(m_TileCount.x);
    m_UvRect.height = texture->getSize().y / int(m_TileCount.y);
    std::cout << m_Row << " and " << m_Column << std::endl;
    //std::cout << m_UvRect.width << " and " << m_UvRect.height << std::endl;
}

Tile::~Tile()
{
    //dtor
}

void Tile::getTile(unsigned int tileNumber)
{
    int row(0);
    int column(0);
    //std::cout << m_Row * m_Column - 1 << std::endl;
    if (tileNumber <= (m_Row * m_Column - 1))
    {
        //m_Column = (m_Column * m_Row); //How I can get my Column :'(
        row = tileNumber % m_Row;
        column = (tileNumber - (tileNumber % m_Column)) / m_Column;
        //std::cout << row << std::endl;
        //std::cout << m_Row << " and " << m_Column << std::endl;

        m_UvRect.left = row * m_UvRect.width;
        m_UvRect.top = column * m_UvRect.height;
    }
    else
    {
        std::cout << "Tile number is too high" << std::endl;
    }
}
