#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <random>
#include "general_functions.hpp"

using namespace std;
using namespace sf;

int rng(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int specify_numbers_in_each_line(int line_num, int num)
{
    vector<string> lines;

    ifstream file("files/setting.txt");
    if (!file.is_open())
    {
        cerr << "error in file" << endl;
    }

    string line;
    while (getline(file, line))
    {
        lines.push_back(line);
    }

    file.close();

    vector<int> numbers;
    string requested_line = lines[line_num - 1];
    stringstream ss;
    ss << requested_line;
    char ch;
    int number;
    while (ss.get(ch))
    {
        if (isdigit(ch))
        {
            ss.unget();
            ss >> number;
            numbers.push_back(number);
        }
    }
    return numbers[num - 1];
}
