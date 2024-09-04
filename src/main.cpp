
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <random>
#include "system.hpp"

using namespace std;
using namespace sf;


int main()
{
    System system(WIDTH, HEIGHT);
    system.run();
    return 0;
}