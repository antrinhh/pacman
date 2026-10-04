#include "sfml_render.hpp"
#include "map.hpp"
#include "player.hpp"

namespace render
{
    Tile::Tile(float tile_size, float wall_size)
        : sf::RectangleShape({tile_size, tile_size})
    {
        setOrigin({tile_size / 2.0f, tile_size / 2.0f});
        setFillColor(fill_color);
        setOutlineColor(wall_color);
        setOutlineThickness(wall_size);
    }

    Pellet::Pellet(float size)
        : sf::CircleShape(size, 20)
    {
        setOrigin({size, size});
        setFillColor(fill_color);
    }

    Player::Player(float size)
        : sf::CircleShape(size, 20)
    {
        setOrigin({size, size});
        setFillColor(fill_color);
    }

    MapRenderer::MapRenderer(float cell_size, float grid_space, float tile_outline)
        : cell_size(cell_size),
          tile(cell_size - grid_space, tile_outline),
          pellet(3.0f),
          player(7.0f)
    {
    }

    void MapRenderer::draw_map(sf::RenderWindow &target, const pacman::Map &map)
    {
        const auto &real_map = map.get_map();
        float y_track = cell_size / 2;

        for (std::size_t row{0}; row < real_map.size(); row++)
        {
            float x_track = cell_size / 2;
            for (std::size_t col{0}; col < real_map[row].size(); col++)
            {
                if (real_map[row][col] == '#')
                {
                    tile.setPosition({x_track, y_track});
                    target.draw(tile);
                }
                else if (real_map[row][col] == '.')
                {
                    pellet.setPosition({x_track, y_track});
                    target.draw(pellet);
                }
                x_track += cell_size;
            }
            y_track += cell_size;
        }
    }

    void MapRenderer::draw_player(sf::RenderWindow &window, const pacman::Player &pac)
    {
        float x_position = (pac.get_x_position() + 0.5f) * cell_size;
        float y_position = (pac.get_y_position() + 0.5f) * cell_size;
        player.setPosition({x_position, y_position});
        window.draw(player);
    }
}
