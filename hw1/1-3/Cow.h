#pragma once
#include <iostream>
#include <string>
class Cow {
public:
    std::string its_name;
    int eat_least;
    int eat_most;
    int produce_milk;
    int food_left = 0;
    Cow() {}
    Cow(std::string name, int l, int u, int m){
        its_name = name;
        eat_least = l;
        eat_most = u;
        produce_milk = m;
    }
};