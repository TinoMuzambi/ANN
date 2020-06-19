// MZMTIN002

#include "ann.h"

/**
 * Default constructor.
 */
MZMTIN002::ann::ann() = default;

MZMTIN002::ann::ann(vector<int> layout, vector<double> init_weights, vector<double> initial_bias, double bias,
                    vector<double> hidden_weights) {
    this->layout = layout;
    this->initial_bias = initial_bias;
    this->bias = bias;
    this->initial_weights = init_weights;
    this->hidden_weights = hidden_weights;
    size = this->layout.size();

    for (int i = 0; i < size; ++i) {
        layer* curr_layer = new layer(this->layout.at(i));
        layers.push_back(curr_layer);
    }

    for (int i = 0; i < size - 1; ++i) {
        matrix* curr_matrix = new matrix(this->layout.at(i), this->layout.at(i + 1), this->initial_weights, false,
                                         this->hidden_weights);
        if (i == 0)
            curr_matrix = new matrix(this->layout.at(i), this->layout.at(i + 1), this->initial_weights, true, this->hidden_weights);

        weights.push_back(curr_matrix);
    }
}

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

void MZMTIN002::ann::set_input(vector<double> input) {
    this->input = input;

    for (int i = 0; i < input.size(); ++i) {
        this->layers.at(0)->set_x(i, input.at(i));
    }

}

MZMTIN002::matrix *MZMTIN002::ann::multiply_matrix(matrix *a, matrix *b, bool first) {
    matrix* result = new matrix(a->get_rows(), b->get_cols());
    for (int i = 0; i < a->get_rows(); ++i) {
        for (int j = 0; j < b->get_cols(); ++j) {
            for (int k = 0; k < b->get_rows(); ++k) {
                double curr = a->get_x(i, k) * b->get_x(k, j);
                double next = result->get_x(i, j) + curr;
                if (k == b->get_rows() - 1)
                    next += first ? initial_bias.at(i + j) : bias;
                result->set_x(i, j, next);
            }
        }
    }

    return result;
}

MZMTIN002::matrix *MZMTIN002::ann::get_neuron_matrix(int i) {
    return layers.at(i)->matrixify_x();
}

MZMTIN002::matrix *MZMTIN002::ann::get_derived_neuron_matrix(int i) {
    return layers.at(i)->matrixify_x_derived();
}

MZMTIN002::matrix *MZMTIN002::ann::get_activated_neuron_matrix(int i) {
    return layers.at(i)->matrixify_x_active();
}

MZMTIN002::matrix *MZMTIN002::ann::get_weights(int i) {
    return weights.at(i);
}

void MZMTIN002::ann::set_neuron_x(int layer_index, int neuron_index, double x) {
    layers.at(layer_index)->set_x(neuron_index, x);
}

void MZMTIN002::ann::feed_forward() {
    for (int i = 0; i < layers.size() - 1; ++i) {
        matrix* a = get_neuron_matrix(i);

        if (i != 0)
            a = get_activated_neuron_matrix(i);

        matrix* b = get_weights(i);
        matrix* c = multiply_matrix(a, b, true);

        if (i != 0)
            c = multiply_matrix(a, b, false);

        for (int j = 0; j < c->get_cols(); ++j) {
            set_neuron_x(i + 1, j, c->get_x(0, j));
        }
    }
}

void MZMTIN002::ann::print_output() {
    for (int i = 0; i < this->layers.size(); ++i) {
        cout << "Layer " << i << endl;
        if (i == 0)
            this->layers.at(i)->matrixify_x()->print_output();
        else
            this->layers.at(i)->matrixify_x_active()->print_output();

    }
}
