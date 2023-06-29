#include <iostream>
#include <string>
#include "engine.h"
#include "wheel.h"
#include "vehicle.h"
using namespace std;

Vehicle::Vehicle(int num, string name) : e(name), w(num){

}

void Vehicle::describe() {
    cout << "Finish building a vehicle with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
    cout << "A vehicle with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
}