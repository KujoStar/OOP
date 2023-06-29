#include <bits/stdc++.h>
using namespace std;

class Rack {
public:
    vector<int> things;
    Rack();
    Rack& operator+=(int x);
    Rack& operator+=(Rack x);
    friend ostream& operator<<(ostream& out, const Rack& x);
    friend Rack operator,(Rack x, int y);
    friend Rack operator,(int x, Rack y);
    friend Rack operator,(Rack x, Rack y);
    bool operator<(Rack y);
    bool operator==(Rack y);
    bool operator>(Rack y);
    int operator()(int a);
    friend Rack operator&(Rack x, Rack y);
    void operator~();
    void operator--();
    void operator--(int);
};