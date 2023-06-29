#pragma once
#include <bits/stdc++.h>

using namespace std;

class LevelStrategy {
public:
    string level;
    LevelStrategy() {
        level = "";
    }
};

class P1LStrategy : public LevelStrategy {
public:
    P1LStrategy() {
        level = "P1";
    }
};

class P2LStrategy : public LevelStrategy {
public:
    P2LStrategy() {
        level = "P2";
    }
};

class P3LStrategy : public LevelStrategy {
public:
    P3LStrategy() {
        level = "P3";
    }
};