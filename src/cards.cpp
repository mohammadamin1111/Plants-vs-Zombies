#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "cards.hpp"

using namespace std;
using namespace sf;

SunFlowerCard ::SunFlowerCard()
{
    card_tex.loadFromFile("files/images/SunFlower.png");
    card_spr.setTexture(card_tex);
    card_tex_gray.loadFromFile("files/images/sunfloweroff.png");
    card_spr_gray.setTexture(card_tex_gray);
    card_spr_gray.setPosition(30, 100);
    is_ready_to_plant = true;
    card_spr.setPosition(30, 100);
    price = specify_numbers_in_each_line(3, 12);
    cooldown = specify_numbers_in_each_line(3, 9);
};

void SunFlowerCard::render(RenderWindow &window)
{
    if (timer.getElapsedTime().asSeconds() >= cooldown)
    {

        is_ready_to_plant = true;
    }
    if (is_ready_to_plant)
        window.draw(card_spr);
    else
        window.draw(card_spr_gray);
}
void SunFlowerCard::to_off()
{
    is_ready_to_plant = false;
}
void PeaShooterCard::to_off()
{
    is_ready_to_plant = false;
}
void IcePeaShooterCard::to_off()
{
    is_ready_to_plant = false;
}
void WallNutCard::to_off()
{
    is_ready_to_plant = false;
}
WallNutCard::WallNutCard()
{

    card_tex.loadFromFile("files/images/WallNut.png");
    card_spr.setTexture(card_tex);
    card_spr.setPosition(30, 180);
    card_tex_gray.loadFromFile("files/images/wallnutoff.png");
    card_spr_gray.setTexture(card_tex_gray);
    card_spr_gray.setPosition(30, 180);
    is_ready_to_plant = true;
    price = specify_numbers_in_each_line(3, 18);
    cooldown = specify_numbers_in_each_line(3, 15);
}
void WallNutCard::render(RenderWindow &window)
{
    if (timer.getElapsedTime().asSeconds() >= cooldown)
    {

        is_ready_to_plant = true;
    }
    if (is_ready_to_plant)
        window.draw(card_spr);
    else
        window.draw(card_spr_gray);
}

PeaShooterCard::PeaShooterCard()
{
    card_tex.loadFromFile("files/images/PeaShooter.png");
    card_spr.setTexture(card_tex);
    card_spr.setPosition(30, 260);
    card_tex_gray.loadFromFile("files/images/peashooteroff.png");
    card_spr_gray.setTexture(card_tex_gray);
    card_spr_gray.setPosition(30, 260);
    is_ready_to_plant = true;
    price = specify_numbers_in_each_line(2, 6);
    cooldown = specify_numbers_in_each_line(2, 3);
}
void PeaShooterCard::render(RenderWindow &window)
{
    if (timer.getElapsedTime().asSeconds() >= cooldown)
    {

        is_ready_to_plant = true;
    }
    if (is_ready_to_plant)
        window.draw(card_spr);
    else
        window.draw(card_spr_gray);
}

IcePeaShooterCard::IcePeaShooterCard()
{
    card_tex.loadFromFile("files/images/SnowPea.png");
    card_spr.setTexture(card_tex);
    card_spr.setPosition(30, 340);
    card_tex_gray.loadFromFile("files/images/icepeashooteroff.png");
    card_spr_gray.setTexture(card_tex_gray);
    card_spr_gray.setPosition(30, 340);
    is_ready_to_plant = true;
    price = specify_numbers_in_each_line(2, 12);
    cooldown = specify_numbers_in_each_line(2, 9);
}
void IcePeaShooterCard::render(RenderWindow &window)
{
    if (timer.getElapsedTime().asSeconds() >= cooldown)
    {

        is_ready_to_plant = true;
    }
    if (is_ready_to_plant)
        window.draw(card_spr);
    else
        window.draw(card_spr_gray);
}
bool SunFlowerCard::is_clicked(float x, float y)
{
    if (is_first_card && card_spr.getGlobalBounds().contains(x, y))
    {
        is_first_card = false;
        timer.restart();
        return true;
    }
    if (card_spr.getGlobalBounds().contains(x, y) && timer.getElapsedTime().asSeconds() >= cooldown)
    {
        timer.restart();
        return true;
    }
    else
        return false;
}
bool WallNutCard::is_clicked(float x, float y)
{
    if (is_first_card && card_spr.getGlobalBounds().contains(x, y))
    {
        is_first_card = false;
        timer.restart();
        return true;
    }
    if (card_spr.getGlobalBounds().contains(x, y) && timer.getElapsedTime().asSeconds() >= cooldown)
    {
        timer.restart();
        return true;
    }
    else
        return false;
}
bool PeaShooterCard::is_clicked(float x, float y)
{
    if (is_first_card && card_spr.getGlobalBounds().contains(x, y))
    {
        is_first_card = false;
        timer.restart();
        return true;
    }
    if (card_spr.getGlobalBounds().contains(x, y) && timer.getElapsedTime().asSeconds() >= cooldown)
    {
        timer.restart();
        return true;
    }
    else
        return false;
}
bool IcePeaShooterCard::is_clicked(float x, float y)
{
    if (is_first_card && card_spr.getGlobalBounds().contains(x, y))
    {
        is_first_card = false;
        timer.restart();
        return true;
    }
    if (card_spr.getGlobalBounds().contains(x, y) && timer.getElapsedTime().asSeconds() >= cooldown)
    {
        timer.restart();
        return true;
    }
    else
        return false;
}
KernelPultCard::KernelPultCard()
{
    card_tex.loadFromFile("files/images/kernelpult.png");
    card_spr.setTexture(card_tex);
    card_spr.setPosition(10,420);
    card_spr.setScale(0.25, 0.35);
    card_tex_gray.loadFromFile("files/images/kernelpultoff.png");
    card_spr_gray.setTexture(card_tex_gray);
     card_spr_gray.setPosition(10,420);
    card_spr_gray.setScale(0.25, 0.35);
    is_ready_to_plant = true;
    price = specify_numbers_in_each_line(3, 6);
    cooldown = specify_numbers_in_each_line(3, 3);
}
void KernelPultCard::render(RenderWindow &window)
{
    if (timer.getElapsedTime().asSeconds() >= cooldown)
    {

        is_ready_to_plant = true;
    }
    if (is_ready_to_plant)
        window.draw(card_spr);
    else
        window.draw(card_spr_gray);
        
}
void KernelPultCard::to_off()
{
    is_ready_to_plant = false;
}
bool KernelPultCard::is_clicked(float x, float y)
{
    if (is_first_card && card_spr.getGlobalBounds().contains(x, y))
    {
        is_first_card = false;
        timer.restart();
        return true;
    }
    if (card_spr.getGlobalBounds().contains(x, y) && timer.getElapsedTime().asSeconds() >= cooldown)
    {
        timer.restart();
        return true;
    }
    else
        return false;
}


void display_price_of_cards(RenderWindow &window, SunFlowerCard *s, WallNutCard *w, PeaShooterCard *p, IcePeaShooterCard *i,KernelPultCard *k)
{
    Text text;
    Font font;
    font.loadFromFile("files/fonts/Cute Dino.ttf");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Blue);
    text.setFont(font);

    int price_sun_flower = s->get_price();
    text.setString(to_string(price_sun_flower));
    text.setPosition(100, 110);
    window.draw(text);
    int price_wallnut = w->get_price();
    text.setString(to_string(price_wallnut));

    text.setPosition(100, 190);
    window.draw(text);

    int price_pea_shooter = p->get_price();
    text.setString(to_string(price_pea_shooter));
    text.setPosition(100, 270);
    window.draw(text);

    int price_ice_pea_shooter = i->get_price();
    text.setString(to_string(price_ice_pea_shooter));
    text.setPosition(100, 350);
    window.draw(text);

    int price_kernel_pult = k->get_price();
    text.setString(to_string(price_kernel_pult));
    text.setPosition(100, 430);
    window.draw(text);
}