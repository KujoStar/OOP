#pragma once
#include "operation.h"
using namespace std;

class OperationPlus:public OperationNodeTwo{
    public:
        using OperationNodeTwo::OperationNodeTwo;
        void UpdateValue();
};