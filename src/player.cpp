#include "player.hpp"

namespace pacman
{
    Player::Player(int x_position, int y_position)
        : x(x_position), y(y_position)
    {
    }

    void Player::move(Direction next)
    {
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
    }

    int Player::get_x_position() const
    {
        return x;
    }
    int Player::get_y_position() const
    {
        return y;
    }
}
