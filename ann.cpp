// MZMTIN002

#include "ann.h"

/**
 * Default constructor.
 */
MZMTIN002::ann::ann() = default;

/**
 * Gets a random double between 0 and 1 for initialising weights.
 * @return random double [0..1].
 */
double MZMTIN002::ann::get_rand_weight() {
    uniform_real_distribution<double> unif(0, 1);
    default_random_engine re;
    re.seed(chrono::system_clock::now().time_since_epoch().count());
    return unif(re);
}

/**
 * Uses perceptron learning rule to determine the set of outputs for given inputs.
 * @param inputs inputs to be classified.
 * @param target outputs for given inputs.
 * @return output for given input.
 */
double
MZMTIN002::ann::perceptron(vector<vector<double>> inputs, unordered_map<vector<double>, double, VectorHasher> target) {
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

double MZMTIN002::ann::neuron(vector<double> inputs, double target) {
    double w11 = 0.1;
    double w12 = -0.4;
    double w21 = 0.2;
    double w22 = 1.0;
    double w31 = 0.5;
    double w32 = -0.6;
    double bias1 = 0.1;
    double bias2 = -0.3;
    double eta = 0.6;
    int count = 0;
    double linear_sum, n_output;


    return 0;
}

double MZMTIN002::ann::sigmoid(double x) {
    return 1.0 / (1.0 + exp(-1 * x));
}

double MZMTIN002::ann::sigmoid_der(double x) {
    return x * (1.0 - x);
}
