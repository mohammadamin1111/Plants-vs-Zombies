#ifndef PEA_HPP
#define PEA_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "general_functions.hpp"
#include "zombie.hpp"

using namespace std;
using namespace sf;
 
 const float SPEED_Y_WATERMELON=10;

class NormalPea{
public:
    NormalPea(Vector2f pos);
    void render(RenderWindow &window);
    void update();
    bool is_out();
    Sprite get_sprite(){ return sprite;}
    Vector2f get_pos() { return position;}
    int get_damage(){ return damage;};
private:
    Texture texture;
    Sprite sprite;
    Vector2f position;
    int damage;
    int speed ;

};

class IcePea{
public:
    IcePea(Vector2f pos);
    void render(RenderWindow &window);
    void update();
    bool is_out(); 
    Sprite get_sprite(){ return sprite;}
     Vector2f get_pos() { return position;}
    int get_damage(){ return damage;};
private:
    Texture texture;
    Sprite sprite;
    Vector2f position;
     int damage;
     int speed ;
};
class Watermelon{
public:
    Watermelon(Vector2f pos, float dest_x);
    void render(RenderWindow &window);
    void update(); 
    Sprite get_sprite(){ return sprite;}
    Vector2f get_pos() { return position;}
    int get_damage(){ return damage;};
private:
    Texture texture;
    Sprite sprite;
    Vector2f position;
    Vector2f first_position;
    float destination_x;
    int damage;
    int speed ;
    Clock c;
    float shetab ;
    float time;
    float dx;
    float dy;
    float speed_y;
    NormalZombie * normal_zombie=NULL;
    GiantZombie * giant_zombie=NULL;
    
};

#endif