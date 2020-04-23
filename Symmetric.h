//
// Created by vekarpov on 12/9/19.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#ifndef UNTITLED_SYMMETRIC_H
#define UNTITLED_SYMMETRIC_H
int sum(const vector<int>& v) {
    int res = 0;
    for (const auto& x : v) {
        res += x;
    }
    return res;
}

bool cmp(const vector<int>& a, const vector<int>& b) {
    return sum(a) > sum(b);
}

bool gr_cmp(const vector<int>& a, const vector<int>& b) {
    auto it1 = a.begin();
    auto it2 = b.begin();
    while (it1 != a.end()) {
        if (*(it1) > *(it2))
            return true;
        if (*(it1++) < *(it2++))
            return false;
    }
    return false;
}

vector<vector<int> > transpose(vector<vector<int> > v) {
    vector<vector<int> > y(v[0].size(), vector<int> (v.size(), 0));
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j < v[0].size(); ++j) {
            y[j][i] = v[i][j];
        }
    }
    return y;
}

vector<vector<int> > symmetric(vector<vector<int> > v) {         // TODO всё должно передаваться по ссылке
    v = transpose(v);
    sort(v.begin(), v.end(), cmp);
    v = transpose(v);
    sort(v.rbegin(), v.rend());
    v = transpose(v);
    auto it1 = v.begin();                         // TODO плохо написано
    auto it2 = v.begin();
    while (it2 != v.end()) {
        if (sum(*it2) != sum(*it1)) {
            sort(it1, it2, gr_cmp);
        }
        ++it2;
    }
    v = transpose(v);
    sort(v.rbegin(), v.rend());
    return v;
}




#endif //UNTITLED_SYMMETRIC_H
