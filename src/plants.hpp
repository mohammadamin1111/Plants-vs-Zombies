#ifndef PLANTS_HPP
#define PLANTS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "general_functions.hpp"
#include "sun.hpp"
#include "pea.hpp"
#include "zombie.hpp"

using namespace std;
using namespace sf;

enum LastCardClick
{   DEFAULT,
    SUNFLOWER,
    WALLNUT,
    PEASHOOTER,
    ICEPEASHOOTER,
    KERNELPULT
};

class SunFlower
{
public:
    SunFlower(Vector2f pos);
    Sprite get_sprite() { return sun_flower_spr; };
    Vector2f get_pos() { return position; };
    void render(RenderWindow &window);
    void update(vector <Sun *> &sun_of_flowers);
    bool decrease_helath(int damage, vector<SunFlower *> &sun_flowers);
     
private:
    Vector2f position;
    Texture sun_flower_tex;
    Sprite sun_flower_spr;
    int health;
    int generate_sun_rate;
    Clock clock;
    Sun *sun;
};

class WallNut
{
public:
    WallNut(Vector2f pos);
    Sprite get_sprite() { return wall_nut_spr_0; };
    Vector2f get_pos() { return position; };
    void render(RenderWindow &window);
    bool decrease_helath(int damage, vector<WallNut *> &wall_nuts);

private:
    Vector2f position;
    Texture wall_nut_tex_0;
    Sprite wall_nut_spr_0;
    Texture wall_nut_tex_1;
    Sprite wall_nut_spr_1;
    Texture wall_nut_tex_2;
    Sprite wall_nut_spr_2;
    int health;
};


class PeaShooter
{
public:
    PeaShooter(Vector2f pos);
    Vector2f get_pos() { return position; };
    void render(RenderWindow &window);
    void update(vector<NormalZombie *> normal_zombies, vector<GiantZombie *> giant_zombies);
    void handle_shot(vector<NormalZombie *> &normal_zombies, vector<GiantZombie *> &giant_zombies);
    bool decrease_helath(int damage, vector<PeaShooter *> &pea_shooters);
    Sprite get_sprite(){ return pea_shooter_spr;};

private:
    Vector2f position;
    Texture pea_shooter_tex;
    Sprite pea_shooter_spr;
    int health;
    vector <NormalPea*> peas;
    int hit_rate;
    bool is_zombie_in_line = false;
    Clock clock;
};

class IcePeaShooter
{
public:
    IcePeaShooter(Vector2f pos);
    Vector2f get_pos() { return position; };
    void render(RenderWindow &window);
    void update(vector<NormalZombie *> normal_zombies, vector<GiantZombie *> giant_zombies);
    void handle_shot(vector<NormalZombie *> &normal_zombies, vector<GiantZombie *> &giant_zombies);
    bool decrease_helath(int damage, vector<IcePeaShooter *> &ice_pea_shooters);
    Sprite get_sprite(){ return ice_pea_shooter_spr;};
private:
    Vector2f position;
    Texture ice_pea_shooter_tex;
    Sprite ice_pea_shooter_spr;
    int health;
    vector <IcePea*> ice_peas;
    int hit_rate;
    Clock clock;
    bool is_zombie_in_line = false;
};
class KernelPult
{
public:
    KernelPult(Vector2f pos);
    Vector2f get_pos() { return position; };
    void render(RenderWindow &window);
    void update(vector<NormalZombie *> &normal_zombies, vector<GiantZombie *> &giant_zombies);
   // void handle_shot(vector<NormalZombie *> &normal_zombies, vector<GiantZombie *> &giant_zombies);
    bool decrease_helath(int damage, vector<KernelPult *> & kernel_pults);
    void handle_watermelon_to_normal_zombie(NormalZombie* &normal_zombie);
    Sprite get_sprite(){ return kernel_pult_spr;};
    void handle_watermelon_to_giant_zombie( GiantZombie* &giant_zombie);

private:
    Vector2f position;
    Texture kernel_pult_tex;
    Sprite kernel_pult_spr;
    vector <Watermelon*> watermelons;
    int health;
    int hit_rate;
    bool is_zombie_in_line = false;
    Clock clock;
    bool is_first_shoot=true;
    int speed;
};

int specify_plants_line(int y);
int specify_plants_column(int x);
bool is_space_free(int column, int line, vector<SunFlower *> sun_flowers, vector<WallNut *> wall_nuts, vector<PeaShooter *> pea_shooters, vector<IcePeaShooter *> ice_pea_shooters,vector<KernelPult*> kernel_pults);
void addSunFlower(vector<SunFlower*> &sun_flowers, float x, float y);
void addWallNut(vector<WallNut*> &wall_nuts, float x, float y);
void addPeaShooter(vector<PeaShooter*> &pea_shooters, float x, float y);
void addIcePeaShooter(vector<IcePeaShooter*> &ice_pea_shooters, float x, float y);
void addKernelPult(vector<KernelPult *> &kernel_pults, float x, float y);


#endif