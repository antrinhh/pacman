#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

namespace pacman
{
    enum class Direction
    {
        Up,
        Down,
        Left,
        Right,
        Dummy,
    };
    class Player
    {
    public:
        Player(int x_position, int y_position);
        void move();
        int get_x_position() const;
        int get_y_position() const;
        Direction get_curr_direction() const { return current_direction; }
        Direction get_req_direction() const { return requested_direction; }
        void set_req_direction(Direction dir);
        void set_curr_direction(Direction dir);

    private:
        Direction current_direction{Direction::Dummy};
        Direction requested_direction{Direction::Dummy};
        int x;
        int y;
    };
}
#endif // _PLAYER_HPP