#include "Map.h"

Map::Map(sf::Texture* texture, sf::Vector2u tileCount) : m_Tile(texture, tileCount)
{
    m_Map.setSize(sf::Vector2f(320.0f, 320.0f));
    m_Map.setTexture(texture);
}

Map::~Map()
{
    //dtor
}

void Map::update(unsigned int tileNumber)
{
    m_Tile.getTile(tileNumber);
    m_Map.setTextureRect(m_Tile.getUvRect());
}
