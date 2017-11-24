#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Tile
{
    public:
        Tile(sf::Texture* texture, sf::Vector2u tileCount);
        virtual ~Tile();

        void getTile(unsigned int tileNumber);
        sf::IntRect getUvRect() { return m_UvRect; }

    private:
        sf::IntRect m_UvRect;
        sf::Vector2u m_TileCount;
        unsigned int m_Row;
        unsigned int m_Column;
};

#endif // TILE_H
