#pragma once //awful
// rename this file from *.cpp to *.tpp or *.hpp
#include "priority_queue.h"

template<class T>
void swap(T& x, T& y) {
  T z = x;
  x = y, y = z;
}

template<class T>
PriorityQueue<T>::PriorityQueue(AbstractCompare<T> *_cmp):
  cmp(_cmp), cnt(0) { }

template<class T>
PriorityQueue<T>::~PriorityQueue(){
  for (int i = 0; i < cnt; i++)
    delete a[i];
}

template<class T>
bool PriorityQueue<T>::empty() {
  return cnt == 0;
}

template<class T>
int PriorityQueue<T>::size() {
  return cnt;
}

#define fa(x) (x >> 1)
#define ls(x) (x << 1)
#define rs(x) (ls(x) | 1)

template<class T>
void PriorityQueue<T>::up(int pos) {
  if (pos == 1 || !cmp->compare(*a[pos], *a[fa(pos)]))
    return;
  swap(a[pos], a[fa(pos)]), up(fa(pos));
}

template<class T>
void PriorityQueue<T>::dw(int pos) {
  int o = pos;
  if (ls(pos) <= cnt && cmp->compare(*a[ls(pos)], *a[o]))
    o = ls(pos);
  if (rs(pos) <= cnt && cmp->compare(*a[rs(pos)], *a[o]))
    o = rs(pos);
  if (o != pos)
    swap(a[pos], a[o]), dw(o);
}

#undef fa
#undef ls
#undef rs

template<class T>
void PriorityQueue<T>::push(T element) {
  a[++cnt] = new T(element);
  up(cnt);
}

template<class T>
void PriorityQueue<T>::pop() {
  swap(a[1], a[cnt]);
  delete a[cnt];
  cnt--, dw(1);
}

template<class T>
T PriorityQueue<T>::top() {
  return *a[1];
}
