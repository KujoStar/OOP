#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MyQueriable {
public:
    vector<T> data;
    MyQueriable<T>() {}
    MyQueriable<T>(vector<T> _data) : data(_data) {}
    int size() {
        return data.size();
    }
    T& operator[](int i) {
        return data[i];
    }
    MyQueriable<T> where(function<T(T)> func) {
        MyQueriable<T> res;
        for(int i = 0; i < data.size(); i ++) {
            if(func(data[i])) {
                res.data.push_back(data[i]);
            }
        }
        return res;
    }
    MyQueriable<T> apply(function<T(T)> func) {
        MyQueriable<T> res;
        for(int i = 0; i < data.size(); i ++) {
            res.data.push_back(func(data[i]));
        }
        return res;
    }
    T sum() {
        T res = 0;
        for(int i = 0; i < data.size(); i ++) {
            res += data[i];
        }
        return res;
    }
};

template <typename T>
MyQueriable<T> from(vector<T> data) {
    MyQueriable<T> res;
    for(int i = 0; i < data.size(); i ++) {
        res.data.push_back(data[i]);
    }
    return res;
}