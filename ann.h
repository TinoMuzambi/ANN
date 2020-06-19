// MZMTIN002

#ifndef ASSIGNMENT_7_ANN_H
#define ASSIGNMENT_7_ANN_H

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <unordered_map>
#include "matrix.h"
#include "layer.h"

using namespace std;

namespace MZMTIN002 {
    class ann {
    private:

        // Part 2

        int size;

        vector<int> layout;

        vector<layer *> layers;

        vector<matrix *> weights;

        vector<double> input;

        vector<double> initial_bias;

        double bias;

        vector<double> initial_weights;

        vector<double> hidden_weights;

    public:

        // Part 1

        struct VectorHasher {   // Struct used for enabling using vector as umap key.
            double operator()(const vector<double> &V) const {
                double hash = 0.0;
                for (int i : V) {
                    hash += i;
                }
                return hash;
            }
        };

        ann();  // Default constructor.

        static double get_rand_weight();    // Get random initial weight.

        static double perceptron(vector<vector<double>> inputs,
                unordered_map<vector<double>, double, VectorHasher> target);  // Perceptron model that processes values.

        // Part 2

        ann(vector<int> layout, vector<double> init_weights, vector<double> initial_bias, double bias,
            vector<double> hidden_weights);

        void set_input(vector<double> input);

        matrix *multiply_matrix(matrix *a, matrix *b, bool first);

        matrix* get_neuron_matrix(int i);

        matrix* get_derived_neuron_matrix(int i);

        matrix* get_activated_neuron_matrix(int i);

        matrix* get_weights(int i);

        void feed_forward();

        void set_neuron_x(int layer_index, int neuron_index, double x);

        void print_output();
    };
}

#endif //ASSIGNMENT_7_ANN_H
