#ifndef GENERAL_FUNCTIONS_HPP
#define GENERAL_FUNCTIONS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

const int FIRST_SUN_NUMBERS = 100;
const int SCORE_PER_SUN = 25;
const int WIDTH = 1200;
const int HEIGHT = 600;
const int FRAME_LIMIT = 25;
const int DISTANCE_OF_Y_ZOMBIES_AND_PLANTS_INLINE = 30;
const int DISTANCE_OF_X_ZOMBIES_AND_PLANTS_INLINE = 40;

using namespace std;
using namespace sf;

int rng(int min, int max);
int specify_numbers_in_each_line(int line_num, int num);


#endif