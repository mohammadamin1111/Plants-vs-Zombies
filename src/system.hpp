#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include "cards.hpp"
#include "attack.hpp"

using namespace std;
using namespace sf;

enum State
{
    START,
    IN_GAME,
    VICTORY,
    GAMEOVER,
    EXIT,
};

class System
{
public:
    System(int width, int height);
    void run();
    RenderWindow window;
    Text text;
    Font font;
    vector<NormalZombie *> normal_zombies;
    vector<GiantZombie *> giant_zombies;
    vector<Sun*> suns;
    vector<WallNut*> wall_nuts;
    vector<SunFlower*> sun_flowers;
    vector<PeaShooter*> pea_shooters;
    vector<IcePeaShooter*> ice_pea_shooters;
    vector <KernelPult*> kernel_pults;
    vector <Sun*> sun_of_flowers;
    Clock timer;
    Music failure_music;

private:
    State state;
    void update();
    void render();
    void handle_events();
    void update_sun_tex();
    void game_over();
    void victory();
    Texture back_ground_texture;
    Sprite back_ground_sprite;
    int sun_number;
    Texture sun_tex;
    Sprite sun_spr;
    Clock zombie_clock;
    Clock sun_clock;
    Clock victory_clock;
    SunFlowerCard *sun_flower_card;
    WallNutCard *wall_nut_card;
    PeaShooterCard *pea_shooter_card;
    IcePeaShooterCard *ice_pea_shooter_card;
    KernelPultCard *kernel_pult_card;
    LastCardClick last_car_click;
    RectangleShape rect;
    Texture game_over_texture;
    Sprite game_over_sprite;
    Texture victory_texture;
    Sprite victory_sprite;
    Texture start_texture;
    Sprite start_sprite;
    Music game_music;
    Music victory_music;
    Music eating_music;
};

#endif