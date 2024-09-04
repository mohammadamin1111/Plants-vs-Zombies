#ifndef CARDS_HPP
#define CARDS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "sun.hpp"
#include "zombie.hpp"

using namespace std;
using namespace sf;

class SunFlowerCard
{
public:
    SunFlowerCard();
    void render(RenderWindow &window);
    bool is_clicked(float x, float y);
    int get_price() { return price; };
    void to_off();

private:
    int price;
    int cooldown;
    bool is_first_card = true;
    Texture card_tex;
    Texture card_tex_gray;
    Sprite card_spr_gray;
    bool is_ready_to_plant;
    Sprite card_spr;
    Clock timer;
};

class WallNutCard
{
public:
    WallNutCard();
    void render(RenderWindow &window);
    bool is_clicked(float x, float y);
    int get_price() { return price; };
    void to_off();

private:
    int price;
    int cooldown;
    bool is_first_card = true;
    Texture card_tex;
    Sprite card_spr;
     Texture card_tex_gray;
    Sprite card_spr_gray;
    bool is_ready_to_plant;
    Clock timer;
};

class PeaShooterCard
{
public:
    PeaShooterCard();
    void render(RenderWindow &window);
    bool is_clicked(float x, float y);
    int get_price() { return price; };
    void to_off();

private:
    int price;
    int cooldown;
    bool is_first_card = true;
    Texture card_tex_gray;
    Sprite card_spr_gray;
    bool is_ready_to_plant;
    Texture card_tex;
    Sprite card_spr;
    Clock timer;
};

class IcePeaShooterCard
{
public:
    IcePeaShooterCard();
    void render(RenderWindow &window);
    bool is_clicked(float x, float y);
    int get_price() { return price; };
    void to_off();

private:
    int price;
    int cooldown;
    bool is_first_card = true;
    Texture card_tex;
    Sprite card_spr;
     Texture card_tex_gray;
    Sprite card_spr_gray;
    bool is_ready_to_plant;
    Clock timer;
};
class KernelPultCard
{
public:
    KernelPultCard();
    void render(RenderWindow &window);
    bool is_clicked(float x, float y);
    int get_price() { return price; };
    void to_off();

private:
    int price;
    int cooldown;
    bool is_first_card = true;
    Texture card_tex_gray;
    Sprite card_spr_gray;
    bool is_ready_to_plant;
    Texture card_tex;
    Sprite card_spr;
    Clock timer;
};
void display_price_of_cards(RenderWindow &window, SunFlowerCard *s, WallNutCard *w, PeaShooterCard *p, IcePeaShooterCard *i,KernelPultCard *k);

#endif