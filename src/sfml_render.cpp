#include "sfml_render.hpp"
#include "map.hpp"
#include "player.hpp"

namespace render
{
    Player::Player(const pacman::Player &player)
        : sf::Texture("assets/pacman_sheet_white_deeper.png"),
          sf::Sprite(static_cast<const sf::Texture &>(*this)),
          m_pac(player)
    {
        this->setSmooth(true);
        this->setTextureRect(sf::IntRect({0, 0}, {x_pixels, y_pixels}));
        this->setScale({0.25f, 0.25f});
        this->setColor(m_fill_color);
        this->setOrigin({static_cast<float>(x_pixels / 2), static_cast<float>(y_pixels / 2)});
    }

    void Player::update(float time)
    {
        m_animation_elapsed += time;

        while (m_animation_elapsed >= m_animation_dt)
        {
            m_animation_elapsed -= m_animation_dt;
            m_frame = (m_frame + 1) % 3; // 0 → 1 → 2 → 0
        }

        setTextureRect(sf::IntRect(
            {x_pixels * m_frame, 0},
            {x_pixels, y_pixels}));
        switch (m_pac.get_curr_direction())
        {
        case pacman::Direction::Up:
            this->setRotation(sf::degrees(270.f));
            break;
        case pacman::Direction::Down:
            this->setRotation(sf::degrees(90.f));
            break;
        case pacman::Direction::Left:
            this->setRotation(sf::degrees(180.f));
            break;
        case pacman::Direction::Right:
            this->setRotation(sf::degrees(0.f));
            break;
        default:
            break;
        }
    }

    MapRenderer::MapRenderer(render::Player &player_render)
        : tile(),
          pellet(),
          player(player_render)
    {
    }

    void MapRenderer::draw_map(sf::RenderWindow &target, const pacman::Map &map)
    {
        const auto &real_map = map.get_map();
        float cell_size = tile.get_size();
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

    void MapRenderer::draw_player(sf::RenderWindow &window, float x, float y)
    {
        float cell_size = tile.get_size();
        float x_position = (x + 0.5f) * cell_size;
        float y_position = (y + 0.5f) * cell_size;
        player.setPosition({x_position, y_position});
        window.draw(player);
    }
}
