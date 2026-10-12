#include <SFML/Graphics.hpp>
#include "map.hpp"
#include "sfml_render.hpp"
#include "player.hpp"
#include "game.hpp"

pacman::Direction direction_from_key(sf::Keyboard::Scancode key)
{
    switch (key)
    {
    case sf::Keyboard::Scancode::W:
        return pacman::Direction::Up;
    case sf::Keyboard::Scancode::A:
        return pacman::Direction::Left;
    case sf::Keyboard::Scancode::S:
        return pacman::Direction::Down;
    case sf::Keyboard::Scancode::D:
        return pacman::Direction::Right;
    }
    return pacman::Direction::Dummy;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "pacman");
    window.setFramerateLimit(120);

    pacman::Map map;
    pacman::Player pax(1, 1);
    map.set_map(pacman::map_1);
    pacman::Game game(pax, map);

    render::Player pax_render(pax);
    render::MapRenderer renderer(pax_render);

    sf::Clock clock;
    float t_accumulate{0.f};
    const float move_interval{0.15f};

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto key = event->getIf<sf::Event::KeyPressed>())
            {
                if (key->scancode == sf::Keyboard::Scancode::Q)
                {
                    window.close();
                }
                pax.set_req_direction(direction_from_key(key->scancode));
            }
        }
        float dt = clock.restart().asSeconds();
        t_accumulate += dt;
        while (t_accumulate >= move_interval)
        {
            t_accumulate -= move_interval;
            game.update_player();
        }
        game.update_map();
        pax_render.update(dt);
        window.clear(sf::Color::Black);
        renderer.draw_map(window, map);
        renderer.draw_player(window, pax);
        window.display();
    }
}
