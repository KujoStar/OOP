#include "OperationPlus.h"
using namespace std;
void OperationPlus::UpdateValue(){
    this->value_=input1->value()+input2->value();
}