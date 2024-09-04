#include "pea.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

NormalPea::NormalPea(Vector2f pos)
{

    position = pos;
    texture.loadFromFile("files/images/NormalPea.png");
    sprite.setTexture(texture);
    damage = specify_numbers_in_each_line(2, 1);
    speed = specify_numbers_in_each_line(2, 5);
    sprite.setPosition(position.x, position.y);
}
void NormalPea::render(RenderWindow &window)
{
    window.draw(sprite);
}

void NormalPea::update()
{
    position.x += speed;
    sprite.setPosition(position.x, position.y);
}

bool NormalPea::is_out()
{
    return sprite.getPosition().x > WIDTH + 50;
}

IcePea::IcePea(Vector2f pos)
{

    position = pos;
    texture.loadFromFile("files/images/IcePea.png");
    sprite.setTexture(texture);
    damage = specify_numbers_in_each_line(2, 7);
    speed = specify_numbers_in_each_line(2, 11);
    sprite.setPosition(position.x, position.y);
}
void IcePea::render(RenderWindow &window)
{
    window.draw(sprite);
}

void IcePea::update()
{
    position.x += speed;
    sprite.setPosition(position);
}

bool IcePea::is_out()
{
    return sprite.getPosition().x > WIDTH + 50;
}

Watermelon::Watermelon(Vector2f pos, float dest_x)
{

    position = pos;
    first_position = pos;
    destination_x = dest_x;
    texture.loadFromFile("files/images/watermelon.png");
    sprite.scale(0.3, 0.3);
    sprite.setTexture(texture);
    damage = specify_numbers_in_each_line(3, 1);
    speed = specify_numbers_in_each_line(3, 5);
    sprite.setPosition(position.x, position.y);
    speed_y=SPEED_Y_WATERMELON;
    dx=destination_x-first_position.x;
    time= dx/speed;
    shetab=(+2*speed_y)/time;
}
void Watermelon::render(RenderWindow &window)
{
    window.draw(sprite);
}

void Watermelon::update()
{
    position.x += speed;
    position.y-=speed_y;
    speed_y-=shetab;
    sprite.setPosition(position);
}
