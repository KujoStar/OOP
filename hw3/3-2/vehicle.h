#pragma once
#include <iostream>
#include <string>
#include "engine.h"
#include "wheel.h"
using namespace std;

class Vehicle {

public:
    Engine e;
    Wheel w;
    Vehicle(int num, string name);
    void describe();
};