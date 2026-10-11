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
        void move(Direction next);
        int get_x_position() const;
        int get_y_position() const;
        Direction get_curr_direction() const { return current_direction; }

    private:
        Direction current_direction{Direction::Dummy};
        int x;
        int y;
    };
}
#endif // _PLAYER_HPP