#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <unordered_map>
#include "ann.h"

using namespace std;

int main() {
    MZMTIN002::ann ann;
//    vector<vector<double>> inputs = {{0, 0},};
//    vector<vector<double>> inputs = {{0, 1},};
//    vector<vector<double>> inputs = {{1, 0},};
    vector<vector<double>> inputs = {{1, 1}};

    // OR PERCEPTRON
    cout << "OR" << endl;
    unordered_map<vector<double>, double, MZMTIN002::ann::VectorHasher> target;
    target[{0, 0}] = 0;
    target[{0, 1}] = 1;
    target[{1, 0}] = 1;
    target[{1, 1}] = 1;
    double or_out = ann.perceptron(inputs, target);

    // NAND PERCEPTRON
    cout << "NAND" << endl;
    target[{0, 0}] = 1;
    target[{0, 1}] = 1;
    target[{1, 0}] = 1;
    target[{1, 1}] = 0;
    double nand_out = ann.perceptron(inputs, target);

    // AND PERCEPTRON
    cout << "XOR" << endl;
    target[{0, 0}] = 0;
    target[{0, 1}] = 0;
    target[{1, 0}] = 0;
    target[{1, 1}] = 1;
    vector<vector<double>> xor_inputs = {{nand_out, or_out}};
    ann.perceptron(xor_inputs, target);


    // Part 2

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
