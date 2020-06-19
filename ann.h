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

        vector<int> layout;     // Layout of this network.

        vector<layer *> layers;     // Layers in this network.

        vector<matrix *> weights;   // Weights for each layer.

        vector<double> input, initial_bias, initial_weights, hidden_weights;

        double hidden_bias;

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

        static vector<double>
        perceptron(vector<vector<double>> inputs, unordered_map<vector<double>, double, VectorHasher> target,
                   bool console);  // Perceptron model that processes values.

        // Part 2

        ann(vector<int> layout, vector<double> init_weights, vector<double> hidden_weights, double hidden_bias,
            vector<double> initial_bias);     // Constructor - sets and intialises values.

        void set_input(vector<double> input);   // Set input for network.

        matrix* multiply_matrices(matrix *a, matrix *b, bool first);    // Performs matrix multiplication.

        matrix* get_neuron_matrix(int i);   // Get matrix at index i.

        matrix* get_activated_neuron_matrix(int i);     // Get activated matric at index i.

        matrix* get_weights(int i);     // Get weights at index i.

        void feed_forward();    // Perform feed forward through network.

        void set_neuron_x(int layer_index, int neuron_index, double x);     // Set x value of neuron with neuron_index in layer layer_index.

        void print_output();    // Print out this network to the console.

        double compute_error(double target);    // Compute and return MSE.
    };
}

#endif //ASSIGNMENT_7_ANN_H
