#ifndef _SFML_RENDER_HPP_
#define _SFML_RENDER_HPP_

#include <SFML/Graphics.hpp>

namespace pacman
{
    class Map;
    class Player;
}

namespace render
{
    class Tile : public sf::RectangleShape
    {
    public:
        Tile(float tile_size, float wall_size);

    private:
        sf::Color fill_color{20, 35, 110};
        sf::Color wall_color{33, 33, 222};
    };

    class Pellet : public sf::CircleShape
    {
    public:
        Pellet(float size);

    private:
        sf::Color fill_color{sf::Color::Yellow};
    };

    class Player : public sf::CircleShape
    {
    public:
        Player(float size);

    private:
        sf::Color fill_color{sf::Color::Yellow};
    };

    class MapRenderer
    {
    public:
        MapRenderer(float cell_size, float grid_space, float tile_outline);
        void draw_map(sf::RenderWindow &target, const pacman::Map &map);
        void draw_player(sf::RenderWindow &window, const pacman::Player &pac);

    private:
        float cell_size;
        Tile tile;
        Pellet pellet;
        Player player;
    };

}

#endif // _SFML_RENDER_HPP_
