#ifndef ATTACK_HPP
#define ATTACK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "plants.hpp"

using namespace std;
using namespace sf;

void checking_can_move_for_normal_zombies(NormalZombie* normal_zombie, vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies);
void normal_zombies_attack_to_sunFlowers(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <SunFlower *> &sun_flowers);
void normal_zombies_attack_to_wallNutts(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <WallNut *> &wall_nuts);
void normal_zombies_attack_to_peaShooters(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <PeaShooter *> &pea_shooters);
void normal_zombies_attack_to_icePeaShooters(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <IcePeaShooter *> &ice_pea_shooters);
void normal_zombies_attack_to_kernelPults(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <KernelPult *> &kernel_pults);
void checking_can_move_for_giant_zombies(GiantZombie* giant_zombie, vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies);
void giant_zombies_attack_to_wallNutts(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <WallNut *> &wall_nuts);
void giant_zombies_attack_to_sunFlowers(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <SunFlower *> &sun_flowers);
void giant_zombies_attack_to_peaShooters(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <PeaShooter *> &pea_shooters);
void giant_zombies_attack_to_icePeaShooters(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <IcePeaShooter *> &ice_pea_shooters);
void giant_zombies_attack_to_kernelPults(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <KernelPult *> &kernel_pults);
void handle_attacks(vector <NormalZombie *> &normal_zombies, vector <GiantZombie *> &giant_zombies, vector <SunFlower *> &sun_flowers, vector <WallNut *> &wall_nuts, vector <PeaShooter *> &pea_shooters, vector <IcePeaShooter *> &ice_pea_shooters
, vector <KernelPult*> &kernel_pults);
#endif