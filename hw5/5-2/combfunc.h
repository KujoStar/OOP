#pragma once

#include "func.h"

class CombFunc : public Func{
private:
    // Todo
    // 声明成员变量
    Func *_func1;
    Func *_func2;
    double _coe1;
    double _coe2;
public:
    CombFunc(Func *fun_1, Func *fun_2, double coe_1, double coe_2) : _func1(fun_1), _func2(fun_2), _coe1(coe_1),  _coe2(coe_2) {};
    // compute a * f(x) + b * g(x)
    // Todo
    // 请参照指数函数类(ExpFunc)实现一个组合函数类
    // 并且要求，传入的参数的析构在该类被析构时同时析构
    double getPoint(double point) {
        return _coe1 * _func1->getPoint(point) + _coe2 * _func2->getPoint(point);
    }
    virtual ~CombFunc() {
        delete _func1;
        delete _func2;
    }
};