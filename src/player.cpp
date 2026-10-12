#include "player.hpp"

namespace pacman
{
    Player::Player(int x_position, int y_position)
        : x(x_position), y(y_position)
    {
    }

    void Player::move()
    {
        switch (current_direction)
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

    void Player::set_req_direction(Direction dir)
    {
        requested_direction = dir;
    }
    void Player::set_curr_direction(Direction dir)
    {
        current_direction = dir;
    }
}
