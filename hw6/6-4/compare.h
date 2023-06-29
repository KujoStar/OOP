#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Compare {
public:
    Compare(vector<function<bool(T, T)>> v) {
        func_list = v;
    }
    ~Compare() {}
    Compare(const initializer_list<function<bool(T, T)>> &v) {
        for(auto i : v){
            func_list.push_back(i);
        }
    }
    bool operator()(const T &a, const T &b) {
        for(auto i : func_list) {
            if(i(a, b)) {
                return true;
            }
            if(i(b, a)) {
                return false;
            }
        }
        return true;
    }
private:
    vector<function<bool(T, T)>> func_list;
};