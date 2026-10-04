#include "map.hpp"

namespace pacman
{
    void Map::set_map(const std::vector<std::string> &map)
    {
        this->map_data = map;
    }

    std::vector<std::string> &Map::get_map()
    {
        return this->map_data;
    }

    const std::vector<std::string> &Map::get_map() const
    {
        return this->map_data;
    }
}
