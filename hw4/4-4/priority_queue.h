#pragma once
#include "abstract_compare.h"

template<class T> class PriorityQueue {
private:
    AbstractCompare<T> *cmp;
    T* a[101]; // awful
    int cnt;
    void up(int pos);
    void dw(int pos);
public:
    PriorityQueue(AbstractCompare<T> *_cmp);
    ~PriorityQueue();
    bool empty();
    int size();
    void push(T element);
    void pop();
    T top();
};

#include "priority_queue.cpp" // awful