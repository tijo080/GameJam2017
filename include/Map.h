#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include "Tile.h"

class Map
{
    public:
        Map(sf::Texture* texture, sf::Vector2u tileCount);
        virtual ~Map();

        void update(unsigned int tileNumber);
        sf::RectangleShape getMap() { return m_Map; }

    private:
        sf::RectangleShape m_Map;
        Tile m_Tile;
};

#endif // MAP_H
