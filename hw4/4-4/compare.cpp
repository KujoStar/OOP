#include "compare.h"
#include <cassert>

bool operator < (const Point& x, const Point& y) {
  return x.x == y.x ? x.y < y.y : x.x < y.x;
}

class type1: public AbstractCompare<int> {
  public:
    bool compare(int x, int y) override {
      return x < y;
    }
};

int count(int x) {
  int sum = 0;
  while(x) sum += x % 10, x /= 10;
  return sum;
}

class type2: public AbstractCompare<int> {
  public:
    bool compare(int x, int y) override {
      return count(x) < count(y);
    }
};

class type3: public AbstractCompare<Point> {
  public:
    bool compare(Point x, Point y) override {
      return x < y;
    }
};

int dis(const Point& x) {
  return x.x * x.x + x.y * x.y;
}

class type4: public AbstractCompare<Point> {
  public:
    bool compare(Point x, Point y) override {
      int dx = dis(x), dy = dis(y);
      return dx == dy ? x < y : dx < dy;
    }
};

AbstractCompare<int>* get_compare_int(int type) {
  if (type == 1)
    return new type1;
  if (type == 2)
    return new type2;
  assert(false);
}

AbstractCompare<Point>* get_compare_point(int type) {
  if (type == 3)
    return new type3;
  if (type == 4)
    return new type4;
  assert(false);
}