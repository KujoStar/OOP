#include <bits/stdc++.h>
#include "Rack.h"
using namespace std;

Rack::Rack() {}

Rack& Rack::operator+=(int x) {
    this->things.push_back(x);
    return *this;
}

Rack& Rack::operator+=(Rack x) {
    for(int i = 0; i < x.things.size(); i ++) {
        things.push_back(x.things[i]);
    }
    return *this;
}

ostream& operator<<(ostream& out, const Rack& x) {
    for(int i = 0; i < x.things.size(); i ++) {
        out << " " << x.things[i];
    }
    return out;
}

Rack operator,(Rack x, int y) {
    x += y;
    return x;
}

Rack operator,(int x, Rack y) {
    Rack ret;
    ret += x;
    ret += y;
    return ret;
}

Rack operator,(Rack x, Rack y) {
    x += y;
    return x;
}

bool Rack::operator<(Rack y) {
    return things.size() < y.things.size();
}

bool Rack::operator==(Rack y) {
    return things.size() == y.things.size();
}

bool Rack::operator>(Rack y) {
    return things.size() > y.things.size();
}

int Rack::operator()(int a) {
    return count(things.begin(), things.end(), a);
}

Rack operator&(Rack x, Rack y) {
    Rack res;
    for(auto i: x.things) {
        if(y(i) && !res(i)) {
            res.things.push_back(i);
        }
    }
    return res;
}

void Rack::operator~() {
    reverse(things.begin(), things.end());
}

void Rack::operator--() {
    things.erase(things.begin());
}

void Rack::operator--(int) {
    things.pop_back();
}