#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <random>
#include "system.hpp"

using namespace std;
using namespace sf;

void System::update_sun_tex()
{
    text.setString(std::to_string(sun_number));
}
System ::System(int width, int height)
{
    state = START;

    window.create(VideoMode(width, height), "Plants VS Zombies", Style::Close);
    window.setFramerateLimit(FRAME_LIMIT);
    if (back_ground_texture.loadFromFile("files/images/Background.png"))
        back_ground_sprite.setTexture(back_ground_texture);
    start_texture.loadFromFile("files/images/startingScreen.png");
    start_sprite.scale(1.1, 0.97);
    start_sprite.setPosition(0, -20);
    start_sprite.setTexture(start_texture);

    game_over_texture.loadFromFile("files/images/loosingScreen.png");
    game_over_sprite.scale(2, 2);
    game_over_sprite.setPosition(130, 0);
    game_over_sprite.setTexture(game_over_texture);

    victory_texture.loadFromFile("files/images/winningScreen.png");
    victory_sprite.scale(0.4, 0.4);
    victory_sprite.setPosition(400, 0);
    victory_sprite.setTexture(victory_texture);

    font.loadFromFile("files/fonts/Cute Dino.ttf");
    text.setFont(font);

    sun_number = FIRST_SUN_NUMBERS;
    text.setString(std::to_string(sun_number));
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    text.setPosition(100, 20);
    sun_tex.loadFromFile("files/images/sun.png");
    sun_spr.setTexture(sun_tex);
    sun_spr.setPosition(20, 20);

    sun_flower_card = new SunFlowerCard();
    wall_nut_card = new WallNutCard();
    pea_shooter_card = new PeaShooterCard();
    ice_pea_shooter_card = new IcePeaShooterCard();
    kernel_pult_card = new KernelPultCard();

    last_car_click = DEFAULT;
    rect.setSize(Vector2f(160, 430));
    rect.setPosition(20, 100);
    rect.setFillColor(Color::Cyan);

    game_music.openFromFile("files/musics/game_music.ogg");
    failure_music.openFromFile("files/musics/failure_music.ogg");
    victory_music.openFromFile("files/musics/victory_music.ogg");
}

void System::run()
{

    while (window.isOpen() && state != EXIT)
    {
        update();
        render();
        handle_events();
        game_over();
        victory();
    }
    abort();
}
void System::game_over()
{
    if (state != GAMEOVER)
    {
        for (auto zombie : normal_zombies)
        {
            if (zombie->is_zombie_passed())
            {
                state = GAMEOVER;
                game_music.stop();
                failure_music.play();
            }
        }
        for (auto zombie : giant_zombies)
        {
            if (zombie->is_zombie_passed())
            {
                state = GAMEOVER;
                game_music.stop();
                failure_music.play();
            }
        }
    }
}

void System::victory()
{
    if (state == IN_GAME && state != VICTORY)
    {
        if (victory_clock.getElapsedTime().asSeconds() >= specify_numbers_in_each_line(4, 1))
        {
            state = VICTORY;
            game_music.stop();
            victory_music.play();
        }
    }
}
void System::update()
{
    switch (state)
    {
    case (IN_GAME):
        if (zombie_clock.getElapsedTime().asSeconds() >= specify_the_entry_interval_of_zombies(timer))
        {
            addZombie(normal_zombies, giant_zombies, HEIGHT, WIDTH);
            zombie_clock.restart();
        }
        if (sun_clock.getElapsedTime().asSeconds() >= specify_the_entry_interval_of_suns())
        {
            addSun(suns, WIDTH);
            sun_clock.restart();
        }
        for (auto zombie : normal_zombies)
        {
            zombie->update();
        }
        for (auto zombie : giant_zombies)
        {
            zombie->update();
        }
        for (auto sun : suns)
        {
            sun->update();
            if (sun->get_the_y() > HEIGHT)
            {
                suns.erase(remove(suns.begin(), suns.end(), sun), suns.end());
                delete sun;
            }
        }
        for (auto sun_flower : sun_flowers)
        {
            sun_flower->update(sun_of_flowers);
        }

        for (auto pea_shooter : pea_shooters)
        {
            pea_shooter->update(normal_zombies, giant_zombies);
            pea_shooter->handle_shot(normal_zombies, giant_zombies);
        }
        for (auto ice_pea_shooter : ice_pea_shooters)
        {
            ice_pea_shooter->update(normal_zombies, giant_zombies);
            ice_pea_shooter->handle_shot(normal_zombies, giant_zombies);
        }
        for (auto kernel_pult : kernel_pults)
        {
            kernel_pult->update(normal_zombies, giant_zombies);
        }
        handle_attacks(normal_zombies, giant_zombies, sun_flowers, wall_nuts, pea_shooters, ice_pea_shooters, kernel_pults);
        update_sun_tex();
        break;
    case (START):
        break;
    case (VICTORY):
        break;
    case (GAMEOVER):
        break;
    }
}
void System::render()
{
    window.clear();
    switch (state)
    {
    case (IN_GAME):
        window.draw(back_ground_sprite);
        window.draw(text);
        window.draw(sun_spr);

        for (auto sun_flower : sun_flowers)
            sun_flower->render(window);

        for (auto wall_nut : wall_nuts)
            wall_nut->render(window);

        for (auto zombie : normal_zombies)

            zombie->render(window);

        for (auto zombie : giant_zombies)
            zombie->render(window);
            
        for (auto sun_of_flower : sun_of_flowers)
            sun_of_flower->render(window);

        for (auto pea_shooter : pea_shooters)
            pea_shooter->render(window);

        for (auto ice_pea_shooter : ice_pea_shooters)
            ice_pea_shooter->render(window);

        for (auto kernel_pult : kernel_pults)
            kernel_pult->render(window);

        for (auto sun : suns)
            sun->render(window);

        window.draw(rect);
        sun_flower_card->render(window);
        wall_nut_card->render(window);
        ice_pea_shooter_card->render(window);
        pea_shooter_card->render(window);
        kernel_pult_card->render(window);
        display_price_of_cards(window, sun_flower_card, wall_nut_card, pea_shooter_card, ice_pea_shooter_card, kernel_pult_card);
        break;
    case (START):
        window.draw(start_sprite);
        break;
    case (VICTORY):
        window.draw(victory_sprite);
        break;
    case (GAMEOVER):
        window.draw(game_over_sprite);
        break;
    }
    window.display();
}
void System::handle_events()
{
    switch (state)
    {
    case (IN_GAME):

        Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case (Event::Closed):
                window.close();
                state = EXIT;
                break;
            case (Event::MouseButtonPressed):
                if (event.mouseButton.button == Mouse::Left)
                {
                    float mouse_X = event.mouseButton.x;
                    float mouse_Y = event.mouseButton.y;
                    for (auto sun : suns)
                    {
                        if (sun->is_clicked(mouse_X, mouse_Y))
                        {

                            suns.erase(remove(suns.begin(), suns.end(), sun), suns.end());
                            delete sun;
                            sun_number += SCORE_PER_SUN;
                            break;
                        }
                    }
                    for (auto sun : sun_of_flowers)
                    {
                        if (sun->is_clicked(mouse_X, mouse_Y))
                        {
                            sun_of_flowers.erase(remove(sun_of_flowers.begin(), sun_of_flowers.end(), sun), sun_of_flowers.end());
                            delete sun;
                            sun_number += SCORE_PER_SUN;
                            break;
                        }
                    }

                    if (sun_flower_card->is_clicked(mouse_X, mouse_Y) && sun_number >= sun_flower_card->get_price())
                    {
                        last_car_click = SUNFLOWER;
                    }
                    if (wall_nut_card->is_clicked(mouse_X, mouse_Y) && sun_number >= wall_nut_card->get_price())
                    {
                        last_car_click = WALLNUT;
                    }
                    if (pea_shooter_card->is_clicked(mouse_X, mouse_Y) && sun_number >= pea_shooter_card->get_price())
                    {
                        last_car_click = PEASHOOTER;
                    }
                    if (ice_pea_shooter_card->is_clicked(mouse_X, mouse_Y) && sun_number >= ice_pea_shooter_card->get_price())
                    {
                        last_car_click = ICEPEASHOOTER;
                    }
                    if (kernel_pult_card->is_clicked(mouse_X, mouse_Y) && sun_number >= kernel_pult_card->get_price())
                    {
                        last_car_click = KERNELPULT;
                    }
                }

                break;
            case (Event::MouseButtonReleased):
                if (event.mouseButton.button == Mouse::Left)
                {
                    float x = event.mouseButton.x;
                    float y = event.mouseButton.y;
                    if (is_space_free(specify_plants_column(x - DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE), specify_plants_line(y), sun_flowers, wall_nuts, pea_shooters, ice_pea_shooters, kernel_pults))
                    {
                        switch (last_car_click)
                        {
                        case (SUNFLOWER):
                            addSunFlower(sun_flowers, x, y);
                            sun_number -= sun_flower_card->get_price();
                            sun_flower_card->to_off();
                            last_car_click = DEFAULT;
                            break;
                        case (WALLNUT):
                            addWallNut(wall_nuts, x, y);
                            sun_number -= wall_nut_card->get_price();
                            wall_nut_card->to_off();
                            last_car_click = DEFAULT;
                            break;
                        case (PEASHOOTER):
                            addPeaShooter(pea_shooters, x, y);
                            sun_number -= pea_shooter_card->get_price();
                            pea_shooter_card->to_off();
                            last_car_click = DEFAULT;
                            break;
                        case (ICEPEASHOOTER):
                            addIcePeaShooter(ice_pea_shooters, x, y);
                            sun_number -= ice_pea_shooter_card->get_price();
                            ice_pea_shooter_card->to_off();
                            last_car_click = DEFAULT;
                            break;
                        case (KERNELPULT):
                            addKernelPult(kernel_pults, x, y);
                            sun_number -= kernel_pult_card->get_price();
                            kernel_pult_card->to_off();
                            last_car_click = DEFAULT;

                            break;
                        default:
                            break;
                        }
                    }
                }

                break;
            default:
                break;
            }
        }
    case (START):

        Event event1;

        while (window.pollEvent(event1))
        {
            switch (event1.type)
            {
            case (Event::Closed):
                window.close();
                state = EXIT;
                break;
            case (Event::MouseButtonPressed):
                if (event1.mouseButton.button == Mouse::Left)
                {
                    float mouse_X = event.mouseButton.x;
                    float mouse_Y = event.mouseButton.y;
                    state = IN_GAME;
                    game_music.play();
                    victory_clock.restart();
                    zombie_clock.restart();
                    sun_clock.restart();
                }
                break;
            }
        }

    case (GAMEOVER):
        Event event2;
        while (window.pollEvent(event2))
        {
            if (event2.type == Event::Closed)
            {
                window.close();
                state = EXIT;
                break;
            }
        }
        break;

    case (VICTORY):
        Event event3;
        while (window.pollEvent(event3))
        {
            if (event3.type == Event::Closed)
            {
                window.close();
                state = EXIT;
                break;
            }
            break;
        }
    }
}