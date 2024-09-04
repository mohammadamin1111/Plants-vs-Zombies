#ifndef SUN_HPP
#define SUN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "general_functions.hpp"

using namespace std;
using namespace sf;

class Sun
{
public:
    Sun(Vector2f pos);
    void render(RenderWindow &window);
    void update();
    float get_the_y() { return position.y; };
    bool is_clicked(float x, float y);
private:
    Vector2f position;
    Texture sun_tex;
    Sprite sun_spr;
    int vertical_speed;
   
};
void addSun ( vector<Sun *> & suns , int width);
int specify_the_entry_interval_of_suns();
#endif