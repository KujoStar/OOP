#pragma once

#include <cmath>

class Func{
public:
    Func() {}
    virtual double getPoint(double point) {};
    virtual ~Func () {}
    // Todo 补充完整Func类,防止在析构时子类出现内存泄露问题
};

