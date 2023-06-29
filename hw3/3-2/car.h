#pragma once
#include <iostream>
#include <string>
#include "wheel.h"
#include "engine.h"
#include "vehicle.h"
using namespace std;

class Car{
public:
    Engine e;
    Wheel w;
    Car(int num, string name);
    void describe();
};