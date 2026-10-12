#include "game.hpp"

namespace pacman
{
    Game::Game(Player &player, Map &map)
        : m_map(map), m_pakkuman(player) {}

    bool Game::can_move(Direction next)
    {
        int x = m_pakkuman.get_x_position();
        int y = m_pakkuman.get_y_position();

        switch (next)
        {
        case Direction::Up:
            y--;
            break;
        case Direction::Down:
            y++;
            break;
        case Direction::Left:
            x--;
            break;
        case Direction::Right:
            x++;
            break;
        default:
            break;
        }

        const auto &map_cells = m_map.get_map();
        return map_cells[y][x] != '#';
    }

    void Game::update_map()
    {
        int x = m_pakkuman.get_x_position();
        int y = m_pakkuman.get_y_position();
        auto &map_cells = m_map.get_map();
        map_cells[y][x] = ' ';
    }

    void Game::update_player()
    {
        if (m_pakkuman.get_req_direction() != pacman::Direction::Dummy && can_move(m_pakkuman.get_req_direction()))
        {
            m_pakkuman.set_curr_direction(m_pakkuman.get_req_direction());
        }
        if (can_move(m_pakkuman.get_curr_direction()))
        {
            m_pakkuman.move();
        }
    }
}