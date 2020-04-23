//
// Created by vekarpov on 12/9/19.
//

#include <iostream>
#include <vector>
#include <string>

#include "Symmetric.h"

using namespace std;

#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H


class Basis {
public:
    friend ostream& operator <<(ostream &out, Basis &m);

    Basis(const vector<vector<int> >& v, int q)         // to be basis is not required
            : n(v.size())
            , m(v[0].size())
            , data(v)
        {
            if (n == 0)
                return;
            Gauss();
            if (n > m)
                data.resize(m);
            for (int i = v.size() - 1; i >= 0; --i) {
                bool f = true;
                for (const auto& x : v[i]) {
                    if (x != 0) {
                        f = false;
                        break;
                    }
                }
                if (f)
                    data.resize(data.size() - 1);
            }
            n = data.size();
            m = data[0].size();
        }

    Basis(const vector<vector<int> >& v)
        : n(v.size())
        , m(v[0].size())
        , data(v)
    {
        Gauss();
    }


    void Gauss() {
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (data[i][j] == 0) {
                for (int z = i + 1; z < n; ++z) {
                    if (data[z][j] != 0) {
                        swap(data[i], data[z]);
                        break;
                    }
                }
                if (data[i][j] == 0) {
                    for (int z = j + 1; z < m; ++z) {
                        if (data[i][z] != 0) {
                            for (int k = 0; k < n; ++k) {
                                swap(data[k][j], data[k][z]);
                            }
                        }
                    }
                }
            }
            /*for (int z = j + 1; z < m; ++z) {
                data[i][z] /= data[i][j];
            }*/
            data[i][j] = 1;
            for (int z = i + 1; z < n; ++z) {
                if (data[z][j] != 0) {
                    for (int q = m - 1; q >= j; --q) {
                        data[z][q] += data[z][j] * data[i][q];
                        data[z][q] %= 2;
                    }
                }
            }
            ++i;
            ++j;
        }

        // обратный гаусс

        for (int k = n - 1; k >= 0; --k) {
            for (int z = k - 1; z >= 0; --z) {
                if (data[z][k] != 0) {
                    for (int y = k; y < m; ++y) {
                        data[z][y] += data[k][y];
                        data[z][y] %= 2;
                    }
                }
            }
        }
    }

    bool Equiv(int n) {

    }

    vector<vector<int> > GetData() {
        return data;
    }

private:
    vector<vector<int> > data;
    int n;
    int m;
};

ostream& operator <<(ostream& out, Basis& m) {
    for (const auto& x : m.data) {
        for (auto y : x) {
            out << y << " ";
        }
        out << "\n";
    }
    return out;
}

#endif //UNTITLED_MATRIX_H
