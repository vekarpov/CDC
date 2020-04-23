//
// Created by vekarpov on 3/4/20.
//


#include "vaidate.h"
#include "Matrix.h"
#include <algorithm>
#include <vector>
#include <iostream>

#include <set>
#include <map>

#include <string>

using namespace std;

map<string, bool> checker_result;

vector<vector<short> > var = {
        {1, 1, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 0, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 0}
};

set<string> res;

//vector<vector<short> > var = {
//        {0, 1, 1, 1, 1},
//        {0, 1, 1, 1, 0},
//        {0, 1, 1, 0, 1},
//        {0, 1, 0, 1, 1},
//        {0, 0, 1, 1, 1},
//        {0, 1, 1, 0, 0},
//        {0, 1, 0, 1, 0},
//        {0, 1, 0, 0, 1},
//        {0, 0, 0, 1, 1},
//        {0, 0, 1, 0, 1},
//        {0, 0, 1, 1, 0},
//        {1, 1, 1, 1, 1},
//        {1, 1, 1, 1, 0},
//        {1, 1, 1, 0, 1},
//        {1, 1, 0, 1, 1},
//        {1, 0, 1, 1, 1},
//        {1, 1, 1, 0, 0},
//        {1, 1, 0, 1, 0},
//        {1, 1, 0, 0, 1},
//        {1, 0, 0, 1, 1},
//        {1, 0, 1, 0, 1},
//        {1, 0, 1, 1, 0},
//        {1, 1, 0, 0, 0},
//        {1, 0, 1, 0, 0},
//        {1, 0, 0, 1, 0},
//        {1, 0, 0, 0, 1},
//};

//vector<vector<short> > var = {
//        {0, 0, 1, 1, 1, 1},
//        {0, 0, 1, 1, 1, 0},
//        {0, 0, 1, 1, 0, 1},
//        {0, 0, 1, 0, 1, 1},
//        {0, 0, 0, 1, 1, 1},
//        {0, 0, 1, 1, 0, 0},
//        {0, 0, 1, 0, 1, 0},
//        {0, 0, 1, 0, 0, 1},
//        {0, 0, 0, 0, 1, 1},
//        {0, 0, 0, 1, 0, 1},
//        {0, 0, 0, 1, 1, 0},
//        {0, 1, 1, 1, 1, 1},
//        {0, 1, 1, 1, 1, 0},
//        {0, 1, 1, 1, 0, 1},
//        {0, 1, 1, 0, 1, 1},
//        {0, 1, 0, 1, 1, 1},
//        {0, 1, 1, 1, 0, 0},
//        {0, 1, 1, 0, 1, 0},
//        {0, 1, 1, 0, 0, 1},
//        {0, 1, 0, 0, 1, 1},
//        {0, 1, 0, 1, 0, 1},
//        {0, 1, 0, 1, 1, 0},
//        {0, 1, 1, 0, 0, 0},
//        {0, 1, 0, 1, 0, 0},
//        {0, 1, 0, 0, 1, 0},
//        {0, 1, 0, 0, 0, 1},
//        {1, 0, 1, 1, 1, 1},
//        {1, 0, 1, 1, 1, 0},
//        {1, 0, 1, 1, 0, 1},
//        {1, 0, 1, 0, 1, 1},
//        {1, 0, 0, 1, 1, 1},
//        {1, 0, 1, 1, 0, 0},
//        {1, 0, 1, 0, 1, 0},
//        {1, 0, 1, 0, 0, 1},
//        {1, 0, 0, 0, 1, 1},
//        {1, 0, 0, 1, 0, 1},
//        {1, 0, 0, 1, 1, 0},
//        {1, 1, 1, 1, 1, 1},
//        {1, 1, 1, 1, 1, 0},
//        {1, 1, 1, 1, 0, 1},
//        {1, 1, 1, 0, 1, 1},
//        {1, 1, 0, 1, 1, 1},
//        {1, 1, 1, 1, 0, 0},
//        {1, 1, 1, 0, 1, 0},
//        {1, 1, 1, 0, 0, 1},
//        {1, 1, 0, 0, 1, 1},
//        {1, 1, 0, 1, 0, 1},
//        {1, 1, 0, 1, 1, 0},
//        {1, 1, 1, 0, 0, 0},
//        {1, 1, 0, 1, 0, 0},
//        {1, 1, 0, 0, 1, 0},
//        {1, 1, 0, 0, 0, 1},
//        {1, 1, 0, 0, 0, 0},
//        {1, 0, 1, 0, 0, 0},
//        {1, 0, 0, 1, 0, 0},
//        {1, 0, 0, 0, 1, 0},
//        {1, 0, 0, 0, 0, 1},
//};

//vector<vector<int> > var = {
//        {1, 1, 1},
//        {1, 1, 0},
//        {1, 0, 1},
//        {0, 1, 1}
//};
void validator(vector<vector<short> > & x, int ind) {
    if (!checker(x)) {

        // ищем F7

        for (int i = 0; i < x[0].size(); ++i) {
            for (int j = i + 1; j < x[0].size(); ++j) {
                for (int z = j + 1; z < x[0].size(); ++z) {
                    vector<int> a = {0, 0, 0, 0};
                    for (int f = 0; f < x.size(); ++f) {
                        if (x[f][i] == 1 && x[f][j] == 1 && x[f][z] == 1) {
                            int t = 0;
                            for (int e : x[f]) {
                                t += e;
                            }
                            if (t == 3)
                                a[0] = 1;
                        }
                        if (x[f][i] == 0 && x[f][j] == 1 && x[f][z] == 1) {
                            int t = 0;
                            for (int e : x[f]) {
                                t += e;
                            }
                            if (t == 2)
                                a[1] = 1;
                        }
                        if (x[f][i] == 1 && x[f][j] == 0 && x[f][z] == 1) {
                            int t = 0;
                            for (int e : x[f]) {
                                t += e;
                            }
                            if (t == 2)
                                a[2] = 1;
                        }
                        if (x[f][i] == 1 && x[f][j] == 1 && x[f][z] == 0) {
                            int t = 0;
                            for (int e : x[f]) {
                                t += e;
                            }
                            if (t == 2)
                                a[3] = 1;
                        }
                    }
                    if (a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1) {
                        return;
                    }
                }
            }
        }

        // проверяем, что верхняя единица

        for (int i = 0; i < x.size(); ++i) {
            vector<vector<short> > y = x;
            y.erase(y.begin() + i);
            if (!checker(y))
                return;

        }

        // сортируем столбцы

        vector<vector<short> > u(x[0].size());
        for (int i = 0; i < x.size(); ++i) {
            for (int j = 0; j < x[0].size(); ++j) {
                u[j].push_back(x[i][j]);
            }
        }
        sort(u.begin(), u.end());

        vector<vector<short> > u2(x.size());
        for (int i = 0; i < x.size(); ++i) {
            for (int j = 0; j < x[0].size(); ++j) {
                u2[i].push_back(u[j][i]);
            }
        }
        sort(u2.begin(), u2.end());

        string r = "";
        for (int i = 0; i < x.size(); ++i) {
            for (int j = 0; j < x[0].size(); ++j) {
                r += to_string(u[j][i]) + " ";
            }
            r += "\n";
        }
        r += '\n';
//        for (auto &e : x) {
//            for (auto p : e) {
//                cout << p << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
        res.insert(r);
        return;
    }
    if (ind == var.size())
        return;
    for (int i = ind; i < var.size(); ++i) {
        x.push_back(var[i]);
        validator(x, i + 1);
        x.pop_back();
    }
}

vector<short> make_array(vector<short> a, vector<short> permutation) {
    vector<short> w(a.size());
    for (int i = 0; i < a.size(); ++i) {
        w[permutation[i]] = a[i];
    }
    return w;
}


bool checker(vector<vector<short> >& x) {    // yes, if we can draw this Graph
    if (x.size() == 0)
        return true;
//    return
//        rchecker(x);
    vector<vector<short> > u(int(x[0].size()), vector<short> (x.size(), 0));
    for (int i = 0; i < int(x.size()); ++i) {
        for (int j = 0; j < int(x[0].size()); ++j) {
            u[j][i] = x[i][j];
        }
    }
    sort(u.begin(), u.end());
    string r;
    for (int i = 0; i < x.size(); ++i) {
        for (int j = 0; j < x[0].size(); ++j) {
            r += to_string(u[j][i]) + " ";
        }
        r += "\n";
    }
    r += '\n';
    if (checker_result.find(r) == checker_result.end()) {
        checker_result[r] = rchecker(x);
    }
    return checker_result[r];
//    return rchecker(x);
}


bool rchecker(vector<vector<short> >& x) {

    // ищем F7

    for (int i = 0; i < x[0].size(); ++i) {
        for (int j = i + 1; j < x[0].size(); ++j) {
            for (int z = j + 1; z < x[0].size(); ++z) {
                vector<int> a = {0, 0, 0, 0};
                for (int f = 0; f < x.size(); ++f) {
                    if (x[f][i] == 1 && x[f][j] == 1 && x[f][z] == 1) {
                        int t = 0;
                        for (int e : x[f]) {
                            t += e;
                        }
                        if (t == 3)
                            a[0] = 1;
                    }
                    if (x[f][i] == 0 && x[f][j] == 1 && x[f][z] == 1) {
                        int t = 0;
                        for (int e : x[f]) {
                            t += e;
                        }
                        if (t == 2)
                            a[1] = 1;
                    }
                    if (x[f][i] == 1 && x[f][j] == 0 && x[f][z] == 1) {
                        int t = 0;
                        for (int e : x[f]) {
                            t += e;
                        }
                        if (t == 2)
                            a[2] = 1;
                    }
                    if (x[f][i] == 1 && x[f][j] == 1 && x[f][z] == 0) {
                        int t = 0;
                        for (int e : x[f]) {
                            t += e;
                        }
                        if (t == 2)
                            a[3] = 1;
                    }
                }
                if (a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1) {
//                    cout << i <<  " " << j << " " << z << endl;
//                    for (auto &q : x) {
//                        for (auto z1 : q) {
//                            cout << z1 << " ";
//                        }
//                        cout << endl;
//                    }
//                    cout << endl;
                    return false;
                }
            }
        }
    }

    // проверка, что не вложен в полный граф на 5ти

    if (x.size() == 6) {

        // случай 3
        vector<short> rq{0, 1, 2, 3};
        do {
            vector<vector<short> > z(6);
            z[0] = make_array({1, 1, 0, 0}, rq);
            z[1] = make_array({0, 1, 1, 0}, rq);
            z[2] = make_array({1, 0, 1, 0}, rq);
            z[3] = make_array({0, 0, 1, 1}, rq);
            z[4] = make_array({1, 0, 1, 1}, rq);
            z[5] = make_array({0, 1, 1, 1}, rq);
            sort(z.rbegin(), z.rend());
            if (z == x) {
                cout << 1 << endl;
                return true;
            }
        } while (next_permutation(rq.begin(), rq.end()));


        // случай 2
        vector<short> rq1{0, 1, 2, 3};
        do {
            vector<vector<short> > z(6);
            z[0] = make_array({1, 1, 0, 0}, rq1);
            z[1] = make_array({0, 1, 1, 0}, rq1);
            z[2] = make_array({0, 0, 1, 1}, rq1);
            z[3] = make_array({1, 1, 1, 0}, rq1);
            z[4] = make_array({0, 1, 1, 1}, rq1);
            z[5] = make_array({1, 1, 1, 1}, rq1);
            sort(z.rbegin(), z.rend());
            if (z == x) {
                return true;
            }
        } while (next_permutation(rq1.begin(), rq1.end()));

        // случай 1
        int t = 0;
        for (int i = 0; i < x.size(); ++i) {
            int q = 0;
            for (int j = 0; j < x[0].size(); ++j) {
                q += x[i][j];
            }
            if (q > 2)
                t = 1;
        }
        if (t == 0)
            return true;
    }


    // added headers
    int l1 = x.size();
    int l2 = x[0].size();

    for (int u1 = 0; u1 < l1 + l2; ++u1) {
        for (int u2 = 0; u2 < u1; ++u2) {
            if (check(x, u1, u2, 1)) {
                return true;
            }
        }
    }
    return false;
}

bool check(vector<vector<short> > x, int x2, int x1, int r) {      // x1 < x2
//    for (auto &t1 : x) {
//        for (auto t2 : t1) {
//            cout << t2 << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
    int l1 = x.size();
    int l2 = x[0].size();
    vector<vector<short> > y(l1, vector<short>(l1 + l2, 0));
    for (int i = 0; i < l1; ++i) {
        y[i][i] = 1;
        for (int j = 0; j < l2; ++j) {
            y[i][l1 + j] = x[i][j];
        }
    }
    for (int i = 0; i < y.size(); ++i) {
        y[i][x1] ^= y[i][x2];
        for (int j = x2 + 1; j < y[i].size(); ++j) {
            y[i][j - 1] = y[i][j];
        }
        y[i].pop_back();
    }

    // К ступенчатому виду
    GetBasis(y);
    if (x[0].size() == 5) {
        vector<vector<short> > z(y.size(), vector<short>(l2 - 1, 0));
        for (int i = 0; i < y.size(); ++i) {
            for (int j = 0; j < l2 - 1; ++j) {
                z[i][j] = y[i][j + l1];
            }
        }
        return checker(z);
    }
    // ищем F1
    for (int i = 0; i < y.size(); ++i) {
        int c = 0;
        for (int j = 0; j < y[i].size(); ++j) {
            c += y[i][j];
        }
        if (c == 1)
            return false;
    }

    // ищем F7
    for (int i = 0; i < y[0].size(); ++i) {
        for (int j = i + 1; j < y[0].size(); ++j) {
            for (int z = j + 1; z < y[0].size(); ++z) {
                vector<int> a = {0, 0, 0, 0};
                for (int f = 0; f < y.size(); ++f) {
                    if (y[f][i] == 1 && y[f][j] == 1 && y[f][z] == 1) {
                        a[0] = 1;
                    }
                    if (y[f][i] == 0 && y[f][j] == 1 && y[f][z] == 1) {
                        a[1] = 1;
                    }
                    if (y[f][i] == 1 && y[f][j] == 0 && y[f][z] == 1) {
                        a[2] = 1;
                    }
                    if (y[f][i] == 1 && y[f][j] == 1 && y[f][z] == 0) {
                        a[3] = 1;
                    }
                }
                if (a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1) {
                    return false;
                }
            }
        }
    }

    return true;
}

void GetBasis(vector<vector<short> >& y) {
    // прямой ход
    int i = 0;
    while (i < y.size()) {
        if (y[i][i] != 1) {
            for (int j = i + 1; j < y[i].size(); ++j) {
                if (y[i][j] == 1) {
                    for (auto &r : y)
                        swap(r[i], r[j]);
                    break;
                }
            }
        }
        if (y[i][i] == 0) {
            y.erase(y.begin() + i);
            continue;
        }
        for (int j = i + 1; j < y.size(); ++j) {
            if (y[j][i] == 1) {
                for (int k = 0; k < y[0].size(); ++k) {
                    y[j][k] ^= y[i][k];
                }
            }
        }
        i += 1;
    }
    // обратный ход
    for (int i = y.size() - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            if (y[j][i] == 1) {
                for (int k = 0; k < y[0].size(); ++k) {
                    y[j][k] ^= y[i][k];
                }
            }
        }
    }
}

signed main() {
    sort(var.rbegin(), var.rend());
    vector<vector<short> > t;
    vector<vector<short> > y = {
//            {1, 1, 1, 1},
            {1, 0, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 1},
            {0, 0, 1, 1}
    };


//    cout << checker(y);
    validator(t, 0);
    cout << res.size() << endl;
    for (auto x : res) {
        cout << x << endl;
    }
}