//
// Created by vekarpov on 3/4/20.
//

#ifndef UNTITLED_VAIDATE_H
#define UNTITLED_VAIDATE_H
#include <vector>
#include <iostream>
#include <cmath>
#include <set>

using namespace std;

void validator(vector<vector<short> > & x, int ind);

bool checker(vector<vector<short> >& x);

bool rchecker(vector<vector<short> >& x);

bool check(vector<vector<short> > y, int x2, int x1, int r);

void GetBasis(vector<vector<short> >& y);

vector<short> make_array(vector<short> a, vector<short> permutation);

int logn(int number);

int st2(int a, int b);

bool check_1(set<int>& x, int x1, int x2);

bool check_2(set<int>& x, int x1);

#endif //UNTITLED_VAIDATE_H
