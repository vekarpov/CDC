//
// Created by vekarpov on 12/26/19.
//
#include <vector>

using namespace std;

bool check_2(vector<vector<int> >& v) {
    int summ;
    for (auto& x : v) {
        summ = 0;
        for (auto y : x) {
            summ += y;
        }
        if (summ % 2 != 0)
            return false;
    }
    return true;
}

bool check_3(vector<vector<int> >& v) {
    return false - 1;
}

bool check_zerous(vector<vector<int>>& v) {
    return check_2(v) || check_3(v);
}



