#include <SFML/Graphics.hpp>
#include "map.hpp"
#include "sfml_render.hpp"
#include "player.hpp"
#include "game.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "pacman");
    pacman::Map map;
    pacman::Player pax(1, 1);
    map.set_map(pacman::map_1);
    pacman::Game game(pax, map);

    render::Player pax_render(pax);
    render::MapRenderer renderer(pax_render);

    sf::Clock clock;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

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
                if (key->scancode == sf::Keyboard::Scancode::W)
                {
                    if (game.can_move(pacman::Direction::Up))
                    {
                        pax.move(pacman::Direction::Up);
                    }
                }
                if (key->scancode == sf::Keyboard::Scancode::A)
                {
                    if (game.can_move(pacman::Direction::Left))
                    {
                        pax.move(pacman::Direction::Left);
                    }
                }
                if (key->scancode == sf::Keyboard::Scancode::S)
                {
                    if (game.can_move(pacman::Direction::Down))
                    {
                        pax.move(pacman::Direction::Down);
                    }
                }
                if (key->scancode == sf::Keyboard::Scancode::D)
                {
                    if (game.can_move(pacman::Direction::Right))
                    {
                        pax.move(pacman::Direction::Right);
                    }
                }
            }
        }
        game.update_map();
        pax_render.update(dt);
        window.clear(sf::Color::Black);
        renderer.draw_map(window, map);
        renderer.draw_player(window, pax);
        window.display();
    }
}
