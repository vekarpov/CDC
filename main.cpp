#include <iostream>
#include <string>
#include <vector>

#include <unordered_set>

#include "Matrix.h"


using namespace std;



class HightZerous {
    public:
        HightZerous(int N)
            :n(N)
        {
            cout << "Starting to find hight zerous" << endl;
            for (int vertex_count = 2; vertex_count * (vertex_count - 1) <= 2 * n; ++vertex_count) {
                cout << "Vertex count = " << vertex_count << endl;

                /*
                 * Написать выделение базиса для полных графов
                 */

            }
        }
    private:
        int n;
        vector<Basis> variants;
};

class GoCheck{
public:
    GoCheck(vector<vector<int> >& start, vector<vector<vector<int> > > d)
        : start(start)
    {
        for (const auto& elem : d) {
            auto t = Basis(elem);
            verbotten.insert(t.toString());
            cout << t.toString() << endl;
        }
    }

    void Run() {
        bool f = true;
        for (int i = 0; i < start.size(); ++i) {
            vector<int> x = *start.begin();
            start.erase(start.begin());
            auto b = Basis(start, 1);
            cout << b.toString() << endl;
            if (verbotten.find(b.toString()) == verbotten.end()) {
                f = false;
            } else {
                start.push_back(x);
                continue;
            }
            if (was.find(b.toString() + "_" + to_string(start.size())) == was.end()) {
                was.insert(b.toString() + "_" + to_string(start.size()));
                cout << "UUUUUUUUUU" << endl;
                for (const auto& x : start) {
                    for (auto y : x) {
                        cout << y << " ";
                    }
                    cout << endl;
                }
                Run();
                start.push_back(x);
            }
        }
        if (f) {
            cout << "UUUUUUUUUU" << endl;
            for (const auto& x : start) {
                for (auto y : x) {
                    cout << y << " ";
                }
                cout << endl;
            }
        }
    }



private:
    vector<vector<int> > start;
    unordered_set<string> was;
    unordered_set<string> verbotten;

};




int main() {
    vector<vector<vector<int> > > basis_data = {
            // two vertex
            {
                    {1, 1, 0, 0, 0},
                    {1, 0, 1, 0, 0},
                    {1, 0, 0, 1, 0},
                    {1, 0, 0, 0, 1}
            },
            // tree vertex
            {
                    {1, 1, 0, 0, 0},
                    {0, 0, 1, 1, 0},
                    {1, 0, 1, 0, 1}
            },
            {
                    {1, 1, 1, 0, 0},
                    {1, 1, 0, 1, 0},
                    {1, 1, 0, 0, 1}
            }
    };

    vector<vector<int> > var_data = {
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0},
            {1, 1, 1, 0, 1},
            {1, 1, 0, 1, 1},
            {1, 0, 1, 1, 1},
            {1, 1, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {1, 0, 1, 1, 0},
            {1, 0, 1, 0, 1},
            {1, 0, 0, 1, 1},
            {1, 0, 1, 0, 1},
            {1, 0, 0, 0, 1},
            {1, 0, 0, 1, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 0, 0},
            //{1, 0, 0, 0, 0},
            {0, 1, 1, 1, 1},
            {0, 1, 1, 1, 0},
            {0, 1, 1, 0, 1},
            {0, 1, 0, 1, 1},
            {0, 0, 1, 1, 1},
            {0, 1, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 1, 0, 1},
            {0, 0, 0, 1, 1},
            {0, 0, 1, 0, 1}
            //{0, 0, 0, 0, 1},
            //{0, 0, 0, 1, 0},
            //{0, 0, 1, 0, 0},
            //{0, 1, 0, 0, 0},
            //{0, 0, 0, 0, 0},
    };

    auto y = GoCheck(var_data, basis_data);
    y.Run();

    return 0;
}
