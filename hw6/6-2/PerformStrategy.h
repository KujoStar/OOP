#pragma once
#include <bits/stdc++.h>
using namespace std;

class PerformStrategy {
public:
    double perform;
    PerformStrategy() {
        perform = 0.0;
    }
    PerformStrategy(double _perform) : perform(_perform) {}
};

class sPerformStrategy : public PerformStrategy {
public:
    sPerformStrategy(double _perform) {
        perform = _perform;
    }
};

class mPerformStrategy : public PerformStrategy {
public:
    mPerformStrategy(double _perform) {
        perform = _perform;
    }
};

class lPerformStrategy : public PerformStrategy {
public:
    lPerformStrategy(double _perform) {
        perform = _perform;
    }
};