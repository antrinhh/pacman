#ifndef _SFML_RENDER_HPP_
#define _SFML_RENDER_HPP_

#include <SFML/Graphics.hpp>
#include <cmath>

namespace pacman
{
    class Map;
    class Player;
}

namespace render
{
    class Tile : public sf::RectangleShape
    {
    public:
        Tile() : sf::RectangleShape({18.f, 18.f})
        {
            this->setOrigin(this->getGeometricCenter());
            this->setFillColor(m_fill_color);
            this->setOutlineThickness(m_outline_thickness);
            this->setOutlineColor(m_outline_color);
            sf::Vector2f size = this->getSize();
            m_size = size.x;
        };
        float get_size() { return m_size + fabs(m_outline_thickness); }

    private:
        float m_size;
        float m_outline_thickness{-2.f};
        sf::Color m_fill_color{20, 35, 110};
        sf::Color m_outline_color{33, 33, 222};
    };

    class Pellet : public sf::CircleShape
    {
    public:
        Pellet() : sf::CircleShape(3.f)
        {
            this->setOrigin(this->getGeometricCenter());
            this->setFillColor(m_fill_color);
        };

    private:
        sf::Color m_fill_color{sf::Color::Yellow};
    };

    class Player : public sf::Texture, public sf::Sprite
    {
    public:
        Player(const pacman::Player &player);
        void update(float time);

    private:
        float m_animation_dt{0.1f};
        float m_animation_elapsed{0.f};
        int m_frame{0};
        int x_pixels{64};
        int y_pixels{64};
        const pacman::Player &m_pac;
        sf::Color m_fill_color{sf::Color::Yellow};
    };

    class MapRenderer
    {
    public:
        MapRenderer(render::Player &player_render);
        void draw_map(sf::RenderWindow &target, const pacman::Map &map);
        void draw_player(sf::RenderWindow &window, const pacman::Player &pac);

    private:
        Tile tile;
        Pellet pellet;
        Player &player;
    };

}

#endif // _SFML_RENDER_HPP_
