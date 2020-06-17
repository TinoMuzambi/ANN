// MZMTIN002

#ifndef ASSIGNMENT_7_ANN_H
#define ASSIGNMENT_7_ANN_H

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <unordered_map>
using namespace std;

namespace MZMTIN002 {
    class ann {
    private:

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

        double sigmoid(double x);

        double sigmoid_der(double x);

        static double neuron(vector<double> inputs, double target);  // Neuron model that processes values.

        // Part 2


    };
}

#endif //ASSIGNMENT_7_ANN_H
