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

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash=0;
        for (int i : V) {
            hash += i;
        }
        return hash;
    }
};

int perceptron(vector<vector<int>> inputs, unordered_map<vector<int>, int, VectorHasher> target) {
    int eta = 1;
    int w1 = 0, w2 = 0, bias = 0; 
    int count = 0, i, yi, yo;
    int delta_w1, delta_w2, delta_bias;

    while (true) {
        vector<int> ans;
        for (auto & input : inputs) {
            yi = input[0] * w1 + input[1] * w2 + bias;
            if (yi >= 0) {
                yo = 1;
            }
            else {
                yo = 0;
            }
            if (target[input] == yo) {
                count++;
                delta_w1 = 0;
                delta_w2 = 0;
                delta_bias = 0;
                ans.push_back(yo);
            }
            else {
                delta_w1 = eta * (target[input] - yo) * input[0];
                delta_w2 = eta * (target[input] - yo) * input[1];
                delta_bias = eta * (target[input] - yo);
            }
            w1 = w1 + delta_w1;
            w2 = w2 + delta_w2;
            bias = bias + delta_bias;
        }
        if (count == inputs.size()) {
            for (auto &&an : ans) {
                cout << an << endl;
            }
            return ans[0];
        }
        else {
            count = 0;
            ans.clear();
        }
    }
}

int main() {
    vector<vector<int>> inputs = {
                                  {0, 0}
    };

    // OR PERCEPTRON
    cout << "OR" << endl;
    unordered_map<vector<int>, int, VectorHasher> target;
    target[{0, 0}] = 0;
    target[{0, 1}] = 1;
    target[{1, 0}] = 1;
    target[{1, 1}] = 1;
    int or_out = perceptron(inputs, target);

    // NAND PERCEPTRON
    cout << "NAND" << endl;
    target[{0, 0}] = 1;
    target[{0, 1}] = 1;
    target[{1, 0}] = 1;
    target[{1, 1}] = 0;
    int nand_out = perceptron(inputs, target);

    // AND PERCEPTRON
    cout << "XOR" << endl;
    target[{0, 0}] = 0;
    target[{0, 1}] = 0;
    target[{1, 0}] = 0;
    target[{1, 1}] = 1;
    vector<vector<int>> xor_inputs = {{nand_out, or_out}};
    perceptron(xor_inputs, target);

    // XOR PERCEPTRON;
//    cout << "XOR" << endl;
//    target[{0, 0}] = 0;
//    target[{0, 1}] = 1;
//    target[{1, 0}] = 1;
//    target[{1, 1}] = 0;
//    vector<vector<int>> xor_inputs = {{nand_out, or_out}};
//    perceptron(xor_inputs, target);

    return 0;
}
