#pragma once
#include "operation.h"
using namespace std;

class OperationMinus:public OperationNodeTwo{
    public:
        using OperationNodeTwo::OperationNodeTwo;
        void UpdateValue();
};