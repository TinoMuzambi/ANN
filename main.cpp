#include <iostream>
#include <vector>
#include <unordered_map>
#include "ann.h"

using namespace std;

int main() {
    cout << "PART 1" << endl;
    MZMTIN002::ann ann;
//    vector<vector<double>> inputs = {{0, 0},};
//    vector<vector<double>> inputs = {{0, 1},};
//    vector<vector<double>> inputs = {{1, 0},};
    vector<vector<double>> inputs = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

    // OR PERCEPTRON
    unordered_map<vector<double>, double, MZMTIN002::ann::VectorHasher> target;
    target[{0, 0}] = 0;
    target[{0, 1}] = 1;
    target[{1, 0}] = 1;
    target[{1, 1}] = 1;
    vector<double> or_out = ann.perceptron(inputs, target, false);

    // NAND PERCEPTRON
    target[{0, 0}] = 1;
    target[{0, 1}] = 1;
    target[{1, 0}] = 1;
    target[{1, 1}] = 0;
    vector<double> nand_out = ann.perceptron(inputs, target, false);

    // AND PERCEPTRON
    cout << "XOR" << endl;
    target[{0, 0}] = 0;
    target[{0, 1}] = 0;
    target[{1, 0}] = 0;
    target[{1, 1}] = 1;
    vector<vector<double>> xor_inputs;
    for (int i = 0; i < or_out.size(); ++i) {
        xor_inputs.push_back({nand_out[i], or_out[i]});
    }
    ann.perceptron(xor_inputs, target, true);


    // Part 2

    cout << "\nPART 2" << endl;
    vector<double> input = {1.30, 2.70, 0.80};
    vector<int> layout = {3, 2, 1};
    vector<double> initial_weights = {0.1, -0.4, 0.2, 1.0, 0.5, -0.6};
    vector<double> hidden_weights = {0.8, 1.0};
    vector<double> initial_bias = {0.1, -0.3};
    double bias = -0.3;
    MZMTIN002::ann* nn = new MZMTIN002::ann(layout, initial_weights, initial_bias, bias, hidden_weights);
    nn->set_input(input);
    nn->feed_forward();
    nn->print_output();

    double error = nn->compute_error(0.36);
    cout << "MSE - " << error << endl;

    return 0;
}
