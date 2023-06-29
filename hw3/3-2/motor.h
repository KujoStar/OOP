#pragma once
#include <iostream>
#include <string>
#include "wheel.h"
#include "engine.h"
#include "vehicle.h"
using namespace std;

class Motor{
public:
    Engine e;
    Wheel w;
    Motor(int num, string name);
    void describe();
    void sell();
};