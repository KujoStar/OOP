#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include "compare.h"
#include "sortlevel.h"
using namespace std;

Compare<vector<int>> make_comp(list<sort_level> sortlevels)
{
    // todo
    vector<function<bool(vector<int>, vector<int>)>> functions;
    for(auto i : sortlevels) {
        if(i.order == order_type::ASCEND) {
            functions.push_back([i](vector<int> a, vector<int> b) {return a[i.column - 1] < b[i.column - 1];});
        }
        else {
            functions.push_back([i](vector<int> a, vector<int> b) {return a[i.column - 1] > b[i.column - 1];});
        }
    }
    Compare<vector<int>> res = functions;
    return res;
}
