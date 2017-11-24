#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
    public:

        bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
        {
            if (!m_tileset.loadFromFile(tileset))
                return false;

            // Redimentionnement du tableau de vertex pour contenir tout le niveau
            m_vertices.setPrimitiveType(sf::Quads);
            m_vertices.resize(width * height * 4);

            // Remplir le tableau de vertex avec un quads par tuile
            for (unsigned int i(0); i < width; ++i)
            {
                for (unsigned int j(0); j < height; ++j)
                {
                    // on récupère le numéro de tuile courant
                    int tileNumber = tiles[i + j * width];

                    // on en déduit sa position dans la texture du tilset
                    int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                    int tv = tileNumber / (m_tileset.getSize().y / tileSize.y);

                    // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                    sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                    // on définit ses quatres coins
                    quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                    quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                    quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                    quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                    // On définit ses quatre coordonnées de texture
                    quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                    quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                    quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                    quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
                }

            }

            return true;
        }

    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            // Application de la transformation
            states.transform *= getTransform();

            // Application de la Texture
            states.texture = &m_tileset;

            // Et on dessine enfin le tableau de vertex
            target.draw(m_vertices, states);
        }

        sf::VertexArray m_vertices;
        sf::Texture m_tileset;
};

#endif // TILEMAP_H
