#include <iostream>
#include <vector>

using namespace std;

int or_tron(vector<vector<int>> inputs, vector<int> target) {
    double eta = 1;
    int w1 = 0, w2 = 0, b = 0, count = 0, yi, neuron_out;
    int delta_w1, delta_w2, delta_wb;

    while (true) {
        vector<int> ans;
        for (int i = 0; i < inputs.size(); i++) {
            yi = inputs[i][0] * w1 + inputs[i][1] * w2 + b;
            if (yi >= 0) {
                neuron_out = 1;
            }
            else {
                neuron_out = 0;
            }
            if (target[i] == neuron_out) {
                count++;
                delta_w1 = 0;
                delta_w2 = 0;
                delta_wb = 0;
                ans.push_back(neuron_out);
            }
            else {
                delta_w1 = eta * (target[i] - neuron_out) * inputs[i][0];
                delta_w2 = eta * (target[i] - neuron_out) * inputs[i][1];
                delta_wb = eta * (target[i] - neuron_out);
            }
            w1 += delta_w1;
            w2 += delta_w2;
            b += delta_wb;
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

int main() {
    vector<vector<int>> inputs = {{0, 0},
                                  {0, 1},
                                  {1, 0},
                                  {1, 1}
    };

    // OR PERCEPTRON
    cout << "OR" << endl;
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
