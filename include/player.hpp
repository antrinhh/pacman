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
    };
    class Player
    {
    public:
        Player(int x_position, int y_position);
        void move(Direction next);
        int get_x_position() const;
        int get_y_position() const;

    private:
        int x;
        int y;
    };
}
#endif // _PLAYER_HPP