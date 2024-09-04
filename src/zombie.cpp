#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "zombie.hpp"

using namespace std;
using namespace sf;

Zombie::Zombie(Vector2f pos)
{
    position = pos;
}
bool Zombie::is_zombie_passed()
{

    return position.x < 100;
}
void Zombie::render(RenderWindow &window)
{
    if (is_iced)
    {
       
          window.draw(zombie_spr_iced);
    }
    else
    {
       window.draw(zombie_spr);
    }
}
void NormalZombie::decrease_helath(int damage, vector<NormalZombie *> &normal_zombies)
{

    health -= damage;
    if (health <= 0)
    {
        normal_zombies.erase(remove(normal_zombies.begin(), normal_zombies.end(), this), normal_zombies.end());
        delete this;
    }
}
NormalZombie::NormalZombie(Vector2f pos)
    : Zombie(pos)
{
    zombie_tex.loadFromFile("files/images/Zombie.png");
    zombie_spr.setTexture(zombie_tex);
    zombie_spr.scale(0.8, 0.8);
    zombie_tex_iced.loadFromFile("files/images/icednormalzombie.png");
    zombie_spr_iced.setTexture(zombie_tex_iced);
    zombie_spr_iced.scale(0.8, 0.8);
    zombie_spr_iced.setPosition(position.x,position.y);
    damage = specify_numbers_in_each_line(1, 1);
    health = specify_numbers_in_each_line(1, 2);
    hit_rate = specify_numbers_in_each_line(1, 3);
    speed = specify_numbers_in_each_line(1, 4);
}

GiantZombie::GiantZombie(Vector2f pos)
    : Zombie(pos)
{
    zombie_tex.loadFromFile("files/images/GiantZombie.png");
    zombie_spr.setTexture(zombie_tex);
    zombie_spr.scale(0.22, 0.22);
     zombie_tex_iced.loadFromFile("files/images/icedgiantzombie.png");
    zombie_spr_iced.setTexture(zombie_tex_iced);
    zombie_spr_iced.scale(0.22, 0.22);
    zombie_spr_iced.setPosition(pos.x, pos.y);
    damage = specify_numbers_in_each_line(1, 5);
    health = specify_numbers_in_each_line(1, 6);
    hit_rate = specify_numbers_in_each_line(1, 7);
    speed = specify_numbers_in_each_line(1, 8);
}

void GiantZombie::decrease_helath(int damage, vector<GiantZombie *> &giant_zombies)
{

    health -= damage;
    if (health <= 0)
    {
        giant_zombies.erase(remove(giant_zombies.begin(), giant_zombies.end(), this), giant_zombies.end());
        delete this;
    }
}
void NormalZombie::update()
{
    if (!can_move) {
        return;
    }
    if (is_iced == false)
    {
        position.x -= speed;
        zombie_spr.setPosition(position.x, position.y);
        zombie_spr_iced.setPosition(position.x, position.y);
    }
    else
    {
        position.x -= speed / 2;
        zombie_spr.setPosition(position.x, position.y);
        zombie_spr_iced.setPosition(position.x, position.y);
        if (clock.getElapsedTime().asSeconds() > 5)
        {

            is_iced = false;
        }
    }
     
}
void GiantZombie::update()
{

    if (!can_move)
        return;
    if (is_iced == false)
    {
        position.x -= speed;
        zombie_spr.setPosition(position.x, position.y);
        zombie_spr_iced.setPosition(position.x, position.y);
    }
    else
    {
        position.x -= speed / 2;
        zombie_spr.setPosition(position.x, position.y);
        zombie_spr_iced.setPosition(position.x, position.y);
        if (clock.getElapsedTime().asSeconds() > 5)
        {

            is_iced = false;
        }
    }
}
void addZombie(vector<NormalZombie *> &normal_zombies, vector<GiantZombie *> &giant_zombies, int height, int width)
{
    int random_y = rng(-40, height - 140);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    int random_line = specify_movement_line(random_y);

    int random_number = dis(gen);
    if (random_number % PROBABILITY_COME_GIANT_ZOMBIE == 0)
    {

        GiantZombie *new_zombie = new GiantZombie(Vector2f(width, random_line));
        giant_zombies.push_back(new_zombie);
    }
    else
    {
        NormalZombie *new_zombie = new NormalZombie(Vector2f(width, random_line));
        normal_zombies.push_back(new_zombie);
    }
}
int specify_range_of_time(int time)
{
    int range = 0;
    while (time >= 0)
    {
        time = time - specify_numbers_in_each_line(4, 2);
        range++;
    }
    return range;
}

int specify_the_entry_interval_of_zombies(Clock timer)
{
    int time_to_update = specify_numbers_in_each_line(4, 2);
    int first_number = specify_numbers_in_each_line(4, 3);
    int number_to_update = specify_numbers_in_each_line(4, 4);
    int time = floor(timer.getElapsedTime().asSeconds());
    int range = specify_range_of_time(time);
    return floor(time_to_update / (first_number + (range - 1) * number_to_update));
}

int specify_movement_line(int random_y)
{
    if (random_y >= -40 && random_y <= 60)
        return 60;
    if (random_y > 60 && random_y <= 160)
        return 160;
    if (random_y > 160 && random_y <= 260)
        return 260;
    if (random_y > 260 && random_y <= 360)
        return 360;
    if (random_y > 360 && random_y <= 460)
        return 460;
    return 0;
}