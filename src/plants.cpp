#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "plants.hpp"

using namespace std;
using namespace sf;

SunFlower::SunFlower(Vector2f pos)
{
    sun_flower_tex.loadFromFile("files/images/SunFlower.png");
    sun_flower_spr.setTexture(sun_flower_tex);
    health = specify_numbers_in_each_line(3, 8);
    generate_sun_rate = specify_numbers_in_each_line(3, 10);
    position = pos;
    sun_flower_spr.setPosition(position.x, position.y);
}

void SunFlower::render(RenderWindow &window)
{
    window.draw(sun_flower_spr);
}

void SunFlower::update(vector<Sun *> &sun_of_flowers)
{
    if (clock.getElapsedTime().asSeconds() >= generate_sun_rate)
    {
        sun = new Sun(Vector2f(position.x - 10, position.y + 20));
        sun_of_flowers.push_back(sun);
        clock.restart();
    }
}

bool SunFlower::decrease_helath(int damage, vector<SunFlower *> &sun_flowers)
{

    health -= damage;
    if (health <= 0)
    {
        sun_flowers.erase(remove(sun_flowers.begin(), sun_flowers.end(), this), sun_flowers.end());
        delete this;
        return true;
    }
    else
        return false;
}

WallNut::WallNut(Vector2f pos)
{
    position = pos;
    health = specify_numbers_in_each_line(3, 14);
    wall_nut_tex_0.loadFromFile("files/images/WallNut_0.png");
    wall_nut_spr_0.setTexture(wall_nut_tex_0);
    wall_nut_spr_0.setPosition(position.x, position.y);

    wall_nut_tex_1.loadFromFile("files/images/WallNut_1.png");
    wall_nut_spr_1.setTexture(wall_nut_tex_1);
    wall_nut_spr_1.setPosition(position.x, position.y);
    wall_nut_spr_1.setScale(0.7, 0.7);

    wall_nut_tex_2.loadFromFile("files/images/WallNut_2.png");
    wall_nut_spr_2.setTexture(wall_nut_tex_2);
    wall_nut_spr_2.setPosition(position.x, position.y);
    wall_nut_spr_2.setScale(0.7, 0.7);
}

void WallNut::render(RenderWindow &window)
{
    int first_health = specify_numbers_in_each_line(3, 14);

    if (health > (2 * first_health) / 3) {
        window.draw(wall_nut_spr_0);
        return;
    }
    if (health <= (2 * first_health) / 3 && health > (first_health) / 3) {
        window.draw(wall_nut_spr_1);
        return;
    }
    else {
       window.draw(wall_nut_spr_2);
       return;
    }
}


bool WallNut::decrease_helath(int damage, vector<WallNut *> &wall_nuts)
{
    health -= damage;
    if (health <= 0)
    {
        wall_nuts.erase(remove(wall_nuts.begin(), wall_nuts.end(), this), wall_nuts.end());
        delete this;
        return true;
    }
    else
        return false;
}

PeaShooter::PeaShooter(Vector2f pos)
{
    position = pos;
    pea_shooter_tex.loadFromFile("files/images/PeaShooter.png");
    pea_shooter_spr.setTexture(pea_shooter_tex);
    pea_shooter_spr.setPosition(position.x, position.y);
    health = specify_numbers_in_each_line(2, 2);
    hit_rate = specify_numbers_in_each_line(2, 4);
}
void PeaShooter::handle_shot(vector<NormalZombie *> &normal_zombies, vector<GiantZombie *> &giant_zombies)
{

    for (auto pea : peas)
    {
        FloatRect peaBounds = pea->get_sprite().getGlobalBounds();

        for (auto normal_zombie : normal_zombies)
        {
            FloatRect zombieBounds = normal_zombie->get_sprite().getGlobalBounds();
            zombieBounds.left += 70;
            if (peaBounds.intersects(zombieBounds) && pea->get_pos().y - normal_zombie->get_pos().y == 30)
            {
                peas.erase(remove(peas.begin(), peas.end(), pea), peas.end());
                delete pea;
                normal_zombie->decrease_helath(pea->get_damage(), normal_zombies);
                break;
            }
        }
        for (auto giant_zombie : giant_zombies)
        {
            FloatRect zombieBounds = giant_zombie->get_sprite().getGlobalBounds();
            zombieBounds.left += 70;
            if (peaBounds.intersects(zombieBounds) && pea->get_pos().y - giant_zombie->get_pos().y == 30)
            {
                peas.erase(remove(peas.begin(), peas.end(), pea), peas.end());
                delete pea;
                giant_zombie->decrease_helath(pea->get_damage(), giant_zombies);
                break;
            }
        }
    }
}

void PeaShooter::render(RenderWindow &window)
{
    window.draw(pea_shooter_spr);
    for (auto pea : peas)
    {
        pea->render(window);
    }
}

void PeaShooter::update(vector<NormalZombie *> normal_zombies, vector<GiantZombie *> giant_zombies)
{
    for (auto normal_zombie : normal_zombies)
    {
        if (position.y - normal_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && position.x <= normal_zombie->get_pos().x)
        {
            is_zombie_in_line = true;
            break;
        }
    }
    for (auto giant_zombie : giant_zombies)
    {
        if (position.y - giant_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && position.x <= giant_zombie->get_pos().x)
        {
            is_zombie_in_line = true;
            break;
        }
    }
    if (is_zombie_in_line)
    {
        if (clock.getElapsedTime().asSeconds() > hit_rate)
        {
            peas.push_back(new NormalPea(Vector2f(position.x, position.y)));
            clock.restart();
        }
        is_zombie_in_line = false;
    }
    for (auto pea : peas)
    {
        pea->update();
    }
}

bool PeaShooter::decrease_helath(int damage, vector<PeaShooter *> &pea_shooters)
{
    health -= damage;
    if (health <= 0)
    {
        pea_shooters.erase(remove(pea_shooters.begin(), pea_shooters.end(), this), pea_shooters.end());
        delete this;
        return true;
    }
    else
        return false;
}

IcePeaShooter::IcePeaShooter(Vector2f pos)
{
    position = pos;
    ice_pea_shooter_tex.loadFromFile("files/images/SnowPea.png");
    ice_pea_shooter_spr.setTexture(ice_pea_shooter_tex);
    ice_pea_shooter_spr.setPosition(position.x, position.y);
    health = specify_numbers_in_each_line(2, 8);
    hit_rate = specify_numbers_in_each_line(2, 10);
}

void IcePeaShooter::render(RenderWindow &window)
{
    window.draw(ice_pea_shooter_spr);
    for (auto ice_pea : ice_peas)
    {
        ice_pea->render(window);
    }
}
void IcePeaShooter::handle_shot(vector<NormalZombie *> &normal_zombies, vector<GiantZombie *> &giant_zombies)
{

    for (auto ice_pea : ice_peas)
    {
        FloatRect peaBounds = ice_pea->get_sprite().getGlobalBounds();

        for (auto normal_zombie : normal_zombies)
        {
            FloatRect zombieBounds = normal_zombie->get_sprite().getGlobalBounds();
            zombieBounds.left += 70;
            if (peaBounds.intersects(zombieBounds) && ice_pea->get_pos().y - normal_zombie->get_pos().y == 30)
            {

                ice_peas.erase(remove(ice_peas.begin(), ice_peas.end(), ice_pea), ice_peas.end());
                delete ice_pea;
                normal_zombie->to_freeze();
                normal_zombie->restart_clock();
                normal_zombie->decrease_helath(ice_pea->get_damage(), normal_zombies);
                break;
            }
        }
        for (auto giant_zombie : giant_zombies)
        {
            FloatRect zombieBounds = giant_zombie->get_sprite().getGlobalBounds();
            zombieBounds.left += 70;
            if (peaBounds.intersects(zombieBounds) && ice_pea->get_pos().y - giant_zombie->get_pos().y == 30)
            {

                ice_peas.erase(remove(ice_peas.begin(), ice_peas.end(), ice_pea), ice_peas.end());
                delete ice_pea;
                giant_zombie->to_freeze();
                giant_zombie->restart_clock();
                giant_zombie->decrease_helath(ice_pea->get_damage(), giant_zombies);
                break;
            }
        }
    }
}

void IcePeaShooter::update(vector<NormalZombie *> normal_zombies, vector<GiantZombie *> giant_zombies)
{
    for (auto normal_zombie : normal_zombies)
    {
        if (position.y - normal_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && position.x <= normal_zombie->get_pos().x)
        {
            is_zombie_in_line = true;
            break;
        }
    }
    for (auto giant_zombie : giant_zombies)
    {
        if (position.y - giant_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && position.x <= giant_zombie->get_pos().x)
        {
            is_zombie_in_line = true;
            break;
        }
    }
    if (is_zombie_in_line)
    {
        if (clock.getElapsedTime().asSeconds() > hit_rate)
        {
            ice_peas.push_back(new IcePea(Vector2f(position.x, position.y)));
            clock.restart();
        }
        is_zombie_in_line = false;
    }
    for (auto ice_pea : ice_peas)
    {
        ice_pea->update();
    }
}

bool IcePeaShooter::decrease_helath(int damage, vector<IcePeaShooter *> &ice_pea_shooters)
{
    health -= damage;
    if (health <= 0)
    {
        ice_pea_shooters.erase(remove(ice_pea_shooters.begin(), ice_pea_shooters.end(), this), ice_pea_shooters.end());
        delete this;
        return true;
    }
    else
        return false;
}
KernelPult::KernelPult(Vector2f pos)
{
    position = pos;
    kernel_pult_tex.loadFromFile("files/images/kernelpult.png");
    kernel_pult_spr.setTexture(kernel_pult_tex);
    kernel_pult_spr.setPosition(position.x, position.y);
    kernel_pult_spr.setScale(0.25, 0.35);
    health = specify_numbers_in_each_line(3, 2);
    hit_rate = specify_numbers_in_each_line(3, 4);
    speed = specify_numbers_in_each_line(3, 5);
}

void KernelPult::render(RenderWindow &window)
{
    window.draw(kernel_pult_spr);
    for (auto watermelon : watermelons)
        watermelon->render(window);
}
void KernelPult::handle_watermelon_to_normal_zombie(NormalZombie *&normal_zombie)
{
    float zombie_x = normal_zombie->get_pos().x;
    float dest = position.x + (zombie_x - position.x) * speed / (normal_zombie->get_speed() + speed);
    Watermelon *new_watermelon = new Watermelon(Vector2f(position.x, position.y), dest);
    watermelons.push_back(new_watermelon);
}
void KernelPult::handle_watermelon_to_giant_zombie(GiantZombie *&giant_zombie)
{
    float zombie_x = giant_zombie->get_pos().x;
    float dest = position.x + (zombie_x - position.x) * speed / (giant_zombie->get_speed() + speed);
    Watermelon *new_watermelon = new Watermelon(Vector2f(position.x, position.y), dest);
    watermelons.push_back(new_watermelon);
}

void KernelPult::update(vector<NormalZombie *> &normal_zombies, vector<GiantZombie *> &giant_zombies)
{
    for (auto watermelon : watermelons)
    {
        watermelon->update();
        FloatRect watermelon_bound = watermelon->get_sprite().getGlobalBounds();
        if (watermelon->get_pos().y > position.y)
        {
            for (auto normal_zombie :normal_zombies){
                FloatRect zombie_bound = normal_zombie->get_sprite().getGlobalBounds();
                if( position.y -normal_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && watermelon_bound.intersects(zombie_bound)){
                    normal_zombie -> decrease_helath(watermelon -> get_damage(), normal_zombies);

                }

            }
            for (auto giant_zombie :giant_zombies){
                FloatRect zombie_bound = giant_zombie->get_sprite().getGlobalBounds();
                if( position.y -giant_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && watermelon_bound.intersects(zombie_bound)){
                    giant_zombie -> decrease_helath(watermelon -> get_damage(), giant_zombies);

                }

            }

            watermelons.erase(remove(watermelons.begin(), watermelons.end(), watermelon), watermelons.end());
            delete watermelon;
        }
    }

    if (is_first_shoot || clock.getElapsedTime().asSeconds() > hit_rate)
    {
        clock.restart();
        is_first_shoot = false;
        GiantZombie *nearest_giant_zombie = NULL;
        NormalZombie *nearest_normal_zombie = NULL;
        int min_x = 2000;
        for (auto normal_zombie : normal_zombies)
        {
            if (position.y - normal_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && position.x <= normal_zombie->get_pos().x)
            {
                if (normal_zombie->get_pos().x < min_x)
                {
                    nearest_normal_zombie = normal_zombie;
                    min_x = nearest_normal_zombie->get_pos().x;
                }
            }
        }
        min_x = 2000;
        for (auto giant_zombie : giant_zombies)
        {
            if (position.y - giant_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && position.x <= giant_zombie->get_pos().x)
            {
                if (giant_zombie->get_pos().x < min_x)
                {
                    nearest_giant_zombie = giant_zombie;
                    min_x = nearest_giant_zombie->get_pos().x;
                }
            }
        }
        if (nearest_giant_zombie == NULL && nearest_normal_zombie == NULL)
        {
            return;
        }
        else if (nearest_giant_zombie == NULL)
        {
            handle_watermelon_to_normal_zombie(nearest_normal_zombie);
        }
        else if (nearest_normal_zombie == NULL)
        {
            handle_watermelon_to_giant_zombie(nearest_giant_zombie);
        }
        else
        {

            if (nearest_normal_zombie->get_pos().x < nearest_giant_zombie->get_pos().x)
            {
                handle_watermelon_to_normal_zombie(nearest_normal_zombie);
            }
            else
            {
                handle_watermelon_to_giant_zombie(nearest_giant_zombie);
            }
        }
    }
}

bool KernelPult::decrease_helath(int damage, vector<KernelPult *> &kernel_pults)
{
    health -= damage;
    if (health <= 0)
    {
        kernel_pults.erase(remove(kernel_pults.begin(), kernel_pults.end(), this), kernel_pults.end());
        delete this;
        return true;
    }
    else
        return false;
}

int specify_plants_line(int y)
{
    if (y > 100 && y <= 190)
        return 90;
    if (y > 190 && y <= 280)
        return 190;
    if (y > 280 && y <= 370)
        return 290;
    if (y > 370 && y <= 450)
        return 390;
    if (y > 450 && y <= 550)
        return 490;
    return 0;
}

int specify_plants_column(int x)
{
    if (x > 230 && x <= 310)
        return 260;
    if (x > 310 && x <= 390)
        return 340;
    if (x > 390 && x <= 470)
        return 420;
    if (x > 470 && x <= 550)
        return 500;
    if (x > 550 && x <= 630)
        return 580;
    if (x > 630 && x <= 710)
        return 660;
    if (x > 710 && x <= 790)
        return 740;
    if (x > 790 && x <= 870)
        return 820;
    if (x > 870 && x <= 950)
        return 900;
    return 0;
}

bool is_space_free(int column, int line, vector<SunFlower *> sun_flowers, vector<WallNut *> wall_nuts, vector<PeaShooter *> pea_shooters, vector<IcePeaShooter *> ice_pea_shooters, vector<KernelPult *> kernel_pults)
{

    if (!(column >= 232 && column <= 1000 && line <= 550 && line >= 90))
        return false;

    for (auto plant : sun_flowers)
    {
        if (plant->get_pos().x == column && plant->get_pos().y == line)
            return false;
    }
    for (auto plant : wall_nuts)
    {

        if (plant->get_pos().x == column && plant->get_pos().y == line)
            return false;
    }
    for (auto plant : pea_shooters)
    {

        if (plant->get_pos().x == column && plant->get_pos().y == line)
            return false;
    }
    for (auto plant : ice_pea_shooters)
    {

        if (plant->get_pos().x == column && plant->get_pos().y == line)
            return false;
    }
    for (auto kernel_pult : kernel_pults)
    {

        if (kernel_pult->get_pos().x == column && kernel_pult->get_pos().y == line)
            return false;
    }
    return true;
}

void addSunFlower(vector<SunFlower *> &sun_flowers, float x, float y)
{
    y = specify_plants_line(y);
    x -= 30;
    x = specify_plants_column(x);

    if (y == 0)
        return;

    SunFlower *new_sun_flower = new SunFlower(Vector2f(x, y));
    for (auto sun_flower : sun_flowers)
        if (sun_flower->get_pos().x == new_sun_flower->get_pos().x && sun_flower->get_pos().y == new_sun_flower->get_pos().y)
            return;
    sun_flowers.push_back(new_sun_flower);
}

void addWallNut(vector<WallNut *> &wall_nuts, float x, float y)
{
    y = specify_plants_line(y);
    x -= 30;
    x = specify_plants_column(x);

    if (y == 0)
        return;

    WallNut *new_wall_nut = new WallNut(Vector2f(x, y));
    wall_nuts.push_back(new_wall_nut);
}

void addPeaShooter(vector<PeaShooter *> &pea_shooters, float x, float y)
{
    y = specify_plants_line(y);
    x -= 30;
    x = specify_plants_column(x);

    if (y == 0)
        return;

    PeaShooter *new_pea_shooter = new PeaShooter(Vector2f(x, y));
    pea_shooters.push_back(new_pea_shooter);
}

void addIcePeaShooter(vector<IcePeaShooter *> &ice_pea_shooters, float x, float y)
{
    y = specify_plants_line(y);
    x -= 30;
    x = specify_plants_column(x);

    if (y == 0)
        return;

    IcePeaShooter *ice_pea_shooter = new IcePeaShooter(Vector2f(x, y));
    ice_pea_shooters.push_back(ice_pea_shooter);
}
void addKernelPult(vector<KernelPult *> &kernel_pults, float x, float y)
{
    y = specify_plants_line(y);
    x -= 30;
    x = specify_plants_column(x);

    if (y == 0)
        return;

    KernelPult *kernel_pult = new KernelPult(Vector2f(x, y));
    kernel_pults.push_back(kernel_pult);
}