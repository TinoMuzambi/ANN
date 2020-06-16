#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <unordered_map>

using namespace std;
double get_rand_weight() {
    uniform_real_distribution<double> unif(0, 1);
    default_random_engine re;
    re.seed(chrono::system_clock::now().time_since_epoch().count());
    return unif(re);
}

struct VectorHasher {
    double operator()(const vector<double> &V) const {
        double hash = 0.0;
        for (int i : V) {
            hash += i;
        }
        return hash;
    }
};

double perceptron(vector<vector<double>> inputs, unordered_map<vector<double>, double, VectorHasher> target) {
    double eta = 0.6;   // Learning rate.
    double w1 = get_rand_weight();   // Initialising weights randomly.
    double w2 = get_rand_weight();
    double bias = 0.0;      // Bias term.
    int count = 0;
    double linear_sum, p_output;
    double delta_w1, delta_w2, delta_bias;

    while (true) {
        vector<int> ans;
        for (auto & input : inputs) {
            linear_sum = input[0] * w1 + input[1] * w2 + bias;
            if (linear_sum >= 0) { // Threshold activation function.
                p_output = 1.0;
            }
            else {
                p_output = 0.0;
            }
            if (target[input] == p_output) {    // Check if output is equivalent to target.
                count++;
                delta_w1 = 0.0;
                delta_w2 = 0.0;
                delta_bias = 0.0;
                ans.push_back(p_output);
            }
            else {  // If not, apply learning rule.
                delta_w1 = eta * (target[input] - p_output) * input[0];
                delta_w2 = eta * (target[input] - p_output) * input[1];
                delta_bias = eta * (target[input] - p_output);
            }
            w1 += delta_w1; // Computing new weights.
            w2 += delta_w2;
            bias += delta_bias;
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
    vector<vector<double>> inputs = {
                                  {0, 0},
    };

    // OR PERCEPTRON
    cout << "OR" << endl;
    unordered_map<vector<double>, double, VectorHasher> target;
    target[{0, 0}] = 0;
    target[{0, 1}] = 1;
    target[{1, 0}] = 1;
    target[{1, 1}] = 1;
    double or_out = perceptron(inputs, target);

    // NAND PERCEPTRON
    cout << "NAND" << endl;
    target[{0, 0}] = 1;
    target[{0, 1}] = 1;
    target[{1, 0}] = 1;
    target[{1, 1}] = 0;
    double nand_out = perceptron(inputs, target);

    // AND PERCEPTRON
    cout << "XOR" << endl;
    target[{0, 0}] = 0;
    target[{0, 1}] = 0;
    target[{1, 0}] = 0;
    target[{1, 1}] = 1;
    vector<vector<double>> xor_inputs = {{nand_out, or_out}};
    perceptron(xor_inputs, target);

    return 0;
}
