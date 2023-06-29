#pragma once
#include "Cow.h"
#include <iostream>
#include <string>
class Farm {
    Cow *cows;
    int cnt = 0;
    double milk_production = 0;
public:
    Farm(int n) {
        cows = new Cow[n];
    }
    void addCow(Cow cow) {
        cows[cnt].its_name = cow.its_name;
        cows[cnt].eat_least = cow.eat_least;
        cows[cnt].eat_most = cow.eat_most;
        cows[cnt].produce_milk = cow.produce_milk;
        cnt += 1;
    }
    void supply(std::string name, int a) {
        for(int i = 0; i < cnt; i ++) {
            if(cows[i].its_name == name) {
                cows[i].food_left += a;
            }
        }
    }
    void startMeal() {
        for(int i = 0; i < cnt; i ++) {
            if(cows[i].food_left == 0) {
                cows[i].food_left = 0;
                milk_production += 0;
            }
            if(cows[i].food_left < cows[i].eat_least && cows[i].food_left > 0) {
                cows[i].food_left = 0;
                milk_production += (1.0 * cows[i].produce_milk / 2);
            }
            if(cows[i].food_left >= cows[i].eat_least && cows[i].food_left <= cows[i].eat_most) {
                cows[i].food_left = 0;
                milk_production += 1.0 * cows[i].produce_milk;
            }
            if(cows[i].food_left > cows[i].eat_most) {
                cows[i].food_left -= cows[i].eat_most;
                milk_production += 1.0 * cows[i].produce_milk;
            }
        }
    }
    void produceMilk() {
        
    }
    double getMilkProduction() {
        return milk_production;
    }
};