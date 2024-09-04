#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "sun.hpp"

using namespace std;
using namespace sf;

bool Sun::is_clicked(float x, float y)
{
    return sun_spr.getGlobalBounds().contains(x, y);
}

Sun::Sun(Vector2f pos)
{
    position = pos;
    sun_tex.loadFromFile("files/images/sun.png");
    sun_spr.setTexture(sun_tex);
    vertical_speed = specify_numbers_in_each_line(5, 1);
    sun_spr.setPosition(position.x,position.y);
    sun_spr.setScale(0.8, 0.8);
}

void Sun::render(RenderWindow &window)
{
    window.draw(sun_spr);
}

void Sun::update()
{
    position.y += vertical_speed;
    sun_spr.setPosition(position.x, position.y);
}

void addSun ( vector<Sun *> & suns , int width)
{
    int random_x = rng(200, width- 80);
    Sun *new_sun = new Sun(Vector2f(random_x, 0));
    suns.push_back(new_sun);
}

int specify_the_entry_interval_of_suns()
{
    return specify_numbers_in_each_line(5, 2);
}