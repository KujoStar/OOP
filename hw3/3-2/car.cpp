#include <iostream>
#include <string>
#include "wheel.h"
#include "engine.h"
#include "vehicle.h"
#include "car.h"
using namespace std;

Car::Car(int num, string name) : e(name), w(num) {}

void Car::describe() {
    cout << "Finish building a car with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
    cout << "A car with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
}