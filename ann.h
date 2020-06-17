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

        ann(vector<int> layout, vector<double> init_weights);

        double sigmoid(double x);

        double sigmoid_der(double x);

        void set_input(vector<double> input);

    };
}

#endif //ASSIGNMENT_7_ANN_H
