#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "attack.hpp"

using namespace std;
using namespace sf;

void checking_can_move_for_normal_zombies(NormalZombie* normal_zombie, vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies)
{
    FloatRect zombieBounds = normal_zombie->get_sprite().getGlobalBounds();
    for (int i = 0; i < normal_zombies.size(); i++) {
        FloatRect otherBounds = normal_zombies[i]->get_sprite().getGlobalBounds();
        if (zombieBounds.intersects(otherBounds) && normal_zombies[i]->get_pos().y == normal_zombie->get_pos().y)
            normal_zombies[i]->can_move = true;
    }
    for (int i = 0; i < giant_zombies.size(); i++) {
        FloatRect otherBounds = giant_zombies[i]->get_sprite().getGlobalBounds();
        if (zombieBounds.intersects(otherBounds) && giant_zombies[i]->get_pos().y == normal_zombie->get_pos().y)
            giant_zombies[i]->can_move = true;
    }
}

void normal_zombies_attack_to_sunFlowers(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <SunFlower *> &sun_flowers)
{
    for (auto normal_zombie : normal_zombies)
    {
        FloatRect zombieBounds = normal_zombie->get_sprite().getGlobalBounds();
        zombieBounds.left += 60;

        for (auto sun_flower : sun_flowers)
        {
            FloatRect flowerBounds = sun_flower->get_sprite().getGlobalBounds();
            if (zombieBounds.intersects(flowerBounds) && sun_flower->get_pos().y - normal_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && (sun_flower->get_pos().x - normal_zombie->get_pos().x) < DISTANCE_OF_X_ZOMBIES_AND_PLANTS_INLINE)
            {
                normal_zombie->can_move = false;
                if (normal_zombie->is_first_hit || normal_zombie->hit_timer.getElapsedTime().asSeconds() >= normal_zombie->get_hit_rate()) {
                    normal_zombie->is_first_hit = false;
                    normal_zombie->hit_timer.restart();
                    if (sun_flower->decrease_helath(normal_zombie->get_damage(), sun_flowers)) 
                       checking_can_move_for_normal_zombies(normal_zombie, normal_zombies, giant_zombies);
                }
            }
        }
    }
}

void normal_zombies_attack_to_wallNutts(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <WallNut *> &wall_nuts)
{
    for (auto normal_zombie : normal_zombies)
    {
        FloatRect zombieBounds = normal_zombie->get_sprite().getGlobalBounds();
        zombieBounds.left += 60;

        for (auto wall_nut : wall_nuts)
        {
            FloatRect flowerBounds = wall_nut->get_sprite().getGlobalBounds();
            if (zombieBounds.intersects(flowerBounds) && wall_nut->get_pos().y - normal_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && (wall_nut->get_pos().x - normal_zombie->get_pos().x) < DISTANCE_OF_X_ZOMBIES_AND_PLANTS_INLINE)
            {
                normal_zombie->can_move = false;
                if (normal_zombie->is_first_hit || normal_zombie->hit_timer.getElapsedTime().asSeconds() >= normal_zombie->get_hit_rate()) {
                    normal_zombie->is_first_hit = false;
                    normal_zombie->hit_timer.restart();
                    if (wall_nut->decrease_helath(normal_zombie->get_damage(), wall_nuts)) 
                       checking_can_move_for_normal_zombies(normal_zombie, normal_zombies, giant_zombies);
                }
            }
        }
    }
}

void normal_zombies_attack_to_peaShooters(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <PeaShooter *> &pea_shooters)
{
    for (auto normal_zombie : normal_zombies)
    {
        FloatRect zombieBounds = normal_zombie->get_sprite().getGlobalBounds();
        zombieBounds.left += 60;

        for (auto pea_shooter : pea_shooters)
        {
            FloatRect flowerBounds = pea_shooter->get_sprite().getGlobalBounds();
            if (zombieBounds.intersects(flowerBounds) && pea_shooter->get_pos().y - normal_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && (pea_shooter->get_pos().x - normal_zombie->get_pos().x) < DISTANCE_OF_X_ZOMBIES_AND_PLANTS_INLINE)
            {
                normal_zombie->can_move = false;
                if (normal_zombie->is_first_hit || normal_zombie->hit_timer.getElapsedTime().asSeconds() >= normal_zombie->get_hit_rate()) {
                    normal_zombie->is_first_hit = false;
                    normal_zombie->hit_timer.restart();
                    if (pea_shooter->decrease_helath(normal_zombie->get_damage(), pea_shooters)) 
                    checking_can_move_for_normal_zombies(normal_zombie, normal_zombies, giant_zombies);
                }
            }
        }
    }
}

void normal_zombies_attack_to_icePeaShooters(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <IcePeaShooter *> &ice_pea_shooters)
{
    for (auto normal_zombie : normal_zombies)
    {
        FloatRect zombieBounds = normal_zombie->get_sprite().getGlobalBounds();
        zombieBounds.left += 60;

        for (auto ice_pea_shooter : ice_pea_shooters)
        {
            FloatRect flowerBounds = ice_pea_shooter->get_sprite().getGlobalBounds();
            if (zombieBounds.intersects(flowerBounds) && ice_pea_shooter->get_pos().y - normal_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && (ice_pea_shooter->get_pos().x - normal_zombie->get_pos().x) < DISTANCE_OF_X_ZOMBIES_AND_PLANTS_INLINE)
            {
                normal_zombie->can_move = false;
                if (normal_zombie->is_first_hit || normal_zombie->hit_timer.getElapsedTime().asSeconds() >= normal_zombie->get_hit_rate()) {
                    normal_zombie->is_first_hit = false;
                    normal_zombie->hit_timer.restart();
                    if (ice_pea_shooter->decrease_helath(normal_zombie->get_damage(), ice_pea_shooters))
                       checking_can_move_for_normal_zombies(normal_zombie, normal_zombies, giant_zombies);
                }
            }
        }
    }
}

void checking_can_move_for_giant_zombies(GiantZombie* giant_zombie, vector <NormalZombie *> &normal_zombies,  vector <GiantZombie *> &giant_zombies)
{
    FloatRect zombieBounds = giant_zombie->get_sprite().getGlobalBounds();

    for (int i = 0; i < normal_zombies.size(); i++) {
        FloatRect otherBounds = normal_zombies[i]->get_sprite().getGlobalBounds();
        if (zombieBounds.intersects(otherBounds) && normal_zombies[i]->get_pos().y == giant_zombie->get_pos().y)
            normal_zombies[i]->can_move = true;
    }

    for (int i = 0; i < giant_zombies.size(); i++) {
        FloatRect otherBounds = giant_zombies[i]->get_sprite().getGlobalBounds();
        if (zombieBounds.intersects(otherBounds) && giant_zombies[i]->get_pos().y == giant_zombie->get_pos().y)
            giant_zombies[i]->can_move = true;
    }
}

void giant_zombies_attack_to_sunFlowers(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <SunFlower *> &sun_flowers)
{
    for (auto giant_zombie : giant_zombies)
    {
        FloatRect zombieBounds = giant_zombie->get_sprite().getGlobalBounds();
        zombieBounds.left += 60;

        for (auto sun_flower : sun_flowers)
        {
            FloatRect flowerBounds = sun_flower->get_sprite().getGlobalBounds();
            if (zombieBounds.intersects(flowerBounds) && sun_flower->get_pos().y - giant_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && (sun_flower->get_pos().x - giant_zombie->get_pos().x) < DISTANCE_OF_X_ZOMBIES_AND_PLANTS_INLINE)
            {
                giant_zombie->can_move = false;
                if (giant_zombie->is_first_hit || giant_zombie->hit_timer.getElapsedTime().asSeconds() >= giant_zombie->get_hit_rate()) {
                    giant_zombie->is_first_hit = false;
                    giant_zombie->hit_timer.restart();
                    if (sun_flower->decrease_helath(giant_zombie->get_damage(), sun_flowers)) 
                        checking_can_move_for_giant_zombies(giant_zombie, normal_zombies, giant_zombies);
                }
            }
        }
    }
}

void giant_zombies_attack_to_wallNutts(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <WallNut *> &wall_nuts)
{
    for (auto giant_zombie : giant_zombies)
    {
        FloatRect zombieBounds = giant_zombie->get_sprite().getGlobalBounds();
        zombieBounds.left += 60;

        for (auto wall_nut : wall_nuts)
        {
            FloatRect flowerBounds = wall_nut->get_sprite().getGlobalBounds();
            if (zombieBounds.intersects(flowerBounds) && wall_nut->get_pos().y - giant_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && (wall_nut->get_pos().x - giant_zombie->get_pos().x) < DISTANCE_OF_X_ZOMBIES_AND_PLANTS_INLINE)
            {
                giant_zombie->can_move = false;
                if (giant_zombie->is_first_hit || giant_zombie->hit_timer.getElapsedTime().asSeconds() >= giant_zombie->get_hit_rate()) {
                    giant_zombie->is_first_hit = false;
                    giant_zombie->hit_timer.restart();
                    if (wall_nut->decrease_helath(giant_zombie->get_damage(), wall_nuts)) 
                        checking_can_move_for_giant_zombies(giant_zombie, normal_zombies, giant_zombies);
                }
            }
        }
    }
}

void giant_zombies_attack_to_peaShooters(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <PeaShooter *> &pea_shooters)
{
    for (auto giant_zombie : giant_zombies)
    {
        FloatRect zombieBounds = giant_zombie->get_sprite().getGlobalBounds();
        zombieBounds.left += 60;

        for (auto pea_shooter : pea_shooters)
        {
            FloatRect flowerBounds = pea_shooter->get_sprite().getGlobalBounds();
            if (zombieBounds.intersects(flowerBounds) && pea_shooter->get_pos().y - giant_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && (pea_shooter->get_pos().x - giant_zombie->get_pos().x) < DISTANCE_OF_X_ZOMBIES_AND_PLANTS_INLINE)
            {
                giant_zombie->can_move = false;
                if (giant_zombie->is_first_hit || giant_zombie->hit_timer.getElapsedTime().asSeconds() >= giant_zombie->get_hit_rate()) {
                    giant_zombie->is_first_hit = false;
                    giant_zombie->hit_timer.restart();
                    if (pea_shooter->decrease_helath(giant_zombie->get_damage(), pea_shooters)) 
                        checking_can_move_for_giant_zombies(giant_zombie, normal_zombies, giant_zombies);
                }
            }
        }
    }
}

void giant_zombies_attack_to_icePeaShooters(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <IcePeaShooter *> &ice_pea_shooters)
{
    for (auto giant_zombie : giant_zombies)
    {
        FloatRect zombieBounds = giant_zombie->get_sprite().getGlobalBounds();
        zombieBounds.left += 60;

        for (auto ice_pea_shooter : ice_pea_shooters)
        {
            FloatRect flowerBounds = ice_pea_shooter->get_sprite().getGlobalBounds();
            if (zombieBounds.intersects(flowerBounds) && ice_pea_shooter->get_pos().y - giant_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && (ice_pea_shooter->get_pos().x - giant_zombie->get_pos().x) < DISTANCE_OF_X_ZOMBIES_AND_PLANTS_INLINE)
            {
                giant_zombie->can_move = false;
                if (giant_zombie->is_first_hit || giant_zombie->hit_timer.getElapsedTime().asSeconds() >= giant_zombie->get_hit_rate()) {
                    giant_zombie->is_first_hit = false;
                    giant_zombie->hit_timer.restart();
                    if (ice_pea_shooter->decrease_helath(giant_zombie->get_damage(), ice_pea_shooters))
                        checking_can_move_for_giant_zombies(giant_zombie, normal_zombies, giant_zombies);
                }
            }
        }
    }
}
//////////////////////////////////////////////////////////////////////
void normal_zombies_attack_to_kernelPults(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <KernelPult *> &kernel_pults)
{
    for (auto normal_zombie : normal_zombies)
    {
        FloatRect zombieBounds = normal_zombie->get_sprite().getGlobalBounds();
        zombieBounds.left += 60;

        for (auto kernel_pult : kernel_pults)
        {
            FloatRect flowerBounds = kernel_pult->get_sprite().getGlobalBounds();
            if (zombieBounds.intersects(flowerBounds) && kernel_pult->get_pos().y - normal_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && (kernel_pult->get_pos().x - normal_zombie->get_pos().x) < DISTANCE_OF_X_ZOMBIES_AND_PLANTS_INLINE)
            {
                normal_zombie->can_move = false;
                if (normal_zombie->is_first_hit || normal_zombie->hit_timer.getElapsedTime().asSeconds() >= normal_zombie->get_hit_rate()) {
                    normal_zombie->is_first_hit = false;
                    normal_zombie->hit_timer.restart();
                    if (kernel_pult->decrease_helath(normal_zombie->get_damage(), kernel_pults))
                       checking_can_move_for_normal_zombies(normal_zombie, normal_zombies, giant_zombies);
                }
            }
        }
    }
}
void giant_zombies_attack_to_kernelPults(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies,  vector <KernelPult *> &kernel_pults)
{
    for (auto giant_zombie : giant_zombies)
    {
        FloatRect zombieBounds = giant_zombie->get_sprite().getGlobalBounds();
        zombieBounds.left += 60;

        for (auto kernel_pult : kernel_pults)
        {
            FloatRect flowerBounds = kernel_pult->get_sprite().getGlobalBounds();
            if (zombieBounds.intersects(flowerBounds) && kernel_pult->get_pos().y - giant_zombie->get_pos().y == DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE && (kernel_pult->get_pos().x - giant_zombie->get_pos().x) < DISTANCE_OF_X_ZOMBIES_AND_PLANTS_INLINE)
            {
                giant_zombie->can_move = false;
                if (giant_zombie->is_first_hit || giant_zombie->hit_timer.getElapsedTime().asSeconds() >= giant_zombie->get_hit_rate()) {
                    giant_zombie->is_first_hit = false;
                    giant_zombie->hit_timer.restart();
                    if (kernel_pult->decrease_helath(giant_zombie->get_damage(), kernel_pults))
                        checking_can_move_for_giant_zombies(giant_zombie, normal_zombies, giant_zombies);
                }
            }
        }
    }
}
void handle_attacks(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <SunFlower *> &sun_flowers, vector <WallNut *> &wall_nuts, vector <PeaShooter *> &pea_shooters, vector <IcePeaShooter *> &ice_pea_shooters
, vector <KernelPult*> &kernel_pults)
{
    normal_zombies_attack_to_sunFlowers(normal_zombies, giant_zombies, sun_flowers);
    normal_zombies_attack_to_wallNutts(normal_zombies, giant_zombies, wall_nuts);
    normal_zombies_attack_to_peaShooters(normal_zombies, giant_zombies, pea_shooters);
    normal_zombies_attack_to_icePeaShooters(normal_zombies, giant_zombies, ice_pea_shooters);
    normal_zombies_attack_to_kernelPults(normal_zombies, giant_zombies, kernel_pults);
    giant_zombies_attack_to_wallNutts(normal_zombies, giant_zombies, wall_nuts);
    giant_zombies_attack_to_sunFlowers(normal_zombies, giant_zombies, sun_flowers);
    giant_zombies_attack_to_peaShooters(normal_zombies, giant_zombies, pea_shooters);
    giant_zombies_attack_to_icePeaShooters(normal_zombies, giant_zombies, ice_pea_shooters);
    giant_zombies_attack_to_kernelPults(normal_zombies, giant_zombies, kernel_pults);
}