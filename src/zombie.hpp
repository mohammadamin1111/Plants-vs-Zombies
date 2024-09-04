#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>
#include "general_functions.hpp"

using namespace std;
using namespace sf;

const int PROBABILITY_COME_GIANT_ZOMBIE = 5;

class Zombie
{
public:
    Zombie(Vector2f pos);
    Vector2f get_pos() { return position; }
    void render(RenderWindow &window);
    virtual void update() = 0;
    Sprite get_sprite(){ return zombie_spr;}
    bool is_zombie_passed();
    bool is_iced;
    void to_freeze(){ is_iced=true;};
    void restart_clock(){ clock.restart();};
    

protected:
    Vector2f position;
    Texture zombie_tex;
    Sprite zombie_spr;
    Texture zombie_tex_iced;
    Sprite zombie_spr_iced;
    Clock clock;
};

class NormalZombie : public Zombie
{
public:
    NormalZombie(Vector2f position);
    int get_damage() { return damage; };
    int get_hit_rate() { return hit_rate; };
    void update();
    void decrease_helath(int damage,vector<NormalZombie *> &normal_zombies);
    bool is_first_hit = true;
    bool can_move = true;
    Clock hit_timer;
    int get_speed(){ return speed;};
private:
    int damage;
    int health;
    int hit_rate;
    int speed;
};

class GiantZombie : public Zombie
{

public:
    GiantZombie(Vector2f position);
    int get_damage() { return damage; };
    int get_hit_rate() { return hit_rate; };
    void update();
    void decrease_helath(int damage, vector<GiantZombie *> &giant_zombies);
    bool is_first_hit = true;
    bool can_move = true;
    Clock hit_timer;
    int get_speed(){ return speed;};
private:
    int damage;
    int health;
    int hit_rate;
    int speed;

};

void addZombie( vector<NormalZombie *> &normal_zombies, vector<GiantZombie *> &giant_zombies, int height, int width);
int specify_movement_line(int random_y);
int specify_range_of_time(int time);
int specify_the_entry_interval_of_zombies(Clock timer);
#endif