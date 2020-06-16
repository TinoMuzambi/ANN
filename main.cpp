#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <unordered_map>

using namespace std;
double get_weight() {
    uniform_real_distribution<double> unif(0, 1);
    default_random_engine re;
    re.seed(chrono::system_clock::now().time_since_epoch().count());
    return unif(re);
}

int or_tron(vector<vector<int>> inputs, vector<int> target) {
    int alp = 1;

    int w1 = 0, w2 = 0, b = 0, count = 0, i, yi, yo;
    int dw1, dw2, db;

    while (true) {
        vector<int> ans;
        for (int j = 0; j < inputs.size(); j++) {
            yi = inputs[j][0] * w1 + inputs[j][1] * w2 + b;
            if (yi >= 0) {
                yo = 1;
            }
            else {
                yo = 0;
            }
            if (target[j] == yo) {
                count++;
                dw1 = 0;
                dw2 = 0;
                db = 0;
                ans.push_back(yo);
            }
            else {
                dw1 = alp * (target[j] - yo) * inputs[j][0];
                dw2 = alp * (target[j] - yo) * inputs[j][1];
                db = alp*(target[j] - yo);
            }
            w1 = w1 + dw1;
            w2 = w2 + dw2;
            b = b + db;
        }
        if (count == inputs.size()) {
            for (auto &&an : ans) {
                cout << an << endl;
            }
            return 0;
        }
        else {
            count = 0;
            ans.clear();
        }
    }
}

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash=0;
        for (int i : V) {
            hash += i;
        }
        return hash;
    }
};

int main() {
    vector<vector<int>> inputs = {{0, 0},
                                  {0, 1},
                                  {1, 0},
                                  {1, 1}
    };

    // OR PERCEPTRON
    cout << "OR" << endl;
    unordered_map<vector<int>, int, VectorHasher> targets;
    targets[{0, 0}] = 0;
    vector<int> target = {0, 1, 1, 1};
    or_tron(inputs, target);

    // AND PERCEPTRON
    cout << "AND" << endl;
    target = {0, 0, 0, 1};
    or_tron(inputs, target);

    // NAND PERCEPTRON
    cout << "NAND" << endl;
    target = {1, 1, 1, 0};
    or_tron(inputs, target);

    return 0;
}
