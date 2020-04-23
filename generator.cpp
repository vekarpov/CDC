//
// Created by vekarpov on 2/24/20.
//

#include "generator.h"

int logn(int number) {
    return int(log2l(static_cast<long double>(number)));
}

int st2(int a, int b) {
    if (b == 1) {
        return a;
    }
    if (b % 2 == 0) {
        return st2(a * a, b / 2);
    } else {
        return a * st2(a, b - 1);
    }
}

void generator(set<int>& v, int max_n, int count) {
    if (count == 0) {
        if (find_multiple_edges(v)) {
            for (auto x : v) {
                cout << endl;
                cout << x << " ";
                cout << endl;
            }
        }
        return;
    }
    if (max_n == 0)
        return;
    v.insert(max_n);
    generator(v, max_n - 1, count - 1);
    v.erase(max_n);
    generator(v, max_n - 1, count);
}

//Tree variants of multiple edges:
//
//1)  |   |
//    1 0 0 0 1 1 1 0
//    0 1 0 0 1 0 0 1
//    0 0 1 0 0 1 1 0
//    0 0 0 1 1 0 1 0
//
//2)  |           |
//    1 0 0 0 1 1 1 0
//    0 1 0 0 1 0 0 1
//    0 0 1 0 0 1 1 0
//    0 0 0 1 1 0 1 0
//
//3)            | |
//    1 0 0 0 1 1 1 0
//    0 1 0 0 1 0 0 1
//    0 0 1 0 0 1 1 0
//    0 0 0 1 1 0 1 0

bool find_multiple_edges(set<int>& v) {
    // first variant
    for (auto x : v) {
        for (auto y : v) {
            if (v.find(x ^ y) != v.end()) {
                return false;
            }
        }
    }

    //second variant
    int base2 = 1;
    for (auto x : v) {
        if (v.find(x ^ base2) != v.end()) {
            return false;
        }
        base2 *= 2;
    }

    // third variant
    int f_ind = logn(*v.rbegin());
    for (int ind1 = 1; ind1 <= f_ind; ++ind1) {
        for (int ind2 = 1; ind2 < ind1; ++ind2) {
            if (checker(v, st2(2, ind1), st2(2, ind2))) {
                return false;
            }
        }
    }
    return true;
}

bool checker(set<int>& v, int n1, int n2) {
    return true;
}

int main() {
    set<int> v;
    generator(v, 8, 5);
}
