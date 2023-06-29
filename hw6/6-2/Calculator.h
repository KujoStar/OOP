#pragma once
#include <bits/stdc++.h>
#include "PerformStrategy.h"
#include "LevelStrategy.h"
using namespace std;

class Calculator {
public:
    string level;
    double perfrom;
    int base;
    Calculator(LevelStrategy *_level, PerformStrategy *_perform) {
        level = _level->level;
        perfrom = _perform->perform;
    }
    int get_base() {
        if(level == "P1") {
            return 2000;
        }
        if(level == "P2") {
            return 5000;
        }
        if(level == "P3") {
            return 10000;
        }
        return 0;
    }
    int get_total(int base) {
        int add = 0;
        if (perfrom >= 0 && perfrom < 0.5)
            add = 1000;
		if (perfrom >= 0.5 && perfrom < 0.8)
            add = int(perfrom * base);
		if (perfrom >= 0.8 && perfrom <= 1)
            add = int(2 * perfrom * base);
        return base + add;
    }
};