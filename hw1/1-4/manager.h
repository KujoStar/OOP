#pragma once
#include "chef.h"
#include <string>
#include <bits/stdc++.h>

class Manager {
private:
    std::vector<Chef> chefs;
    int cnt = 0;
public:
    Manager() { }
    void newChef(Chef chef);
    void order(std::string dish);
    void order(std::string dish, int id);
};