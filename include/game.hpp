#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "map.hpp"
#include "player.hpp"

namespace pacman
{
    class Game
    {
    public:
        Game(Player &player, Map &map);
        bool can_move(Direction next);
        void update_map();
        void update_player();

    private:
        Player &m_pakkuman;
        Map &m_map;
    };
}

#endif // _GAME_HPP_