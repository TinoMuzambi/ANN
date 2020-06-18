// MZMTIN002

#include "layer.h"

MZMTIN002::layer::layer(int size) {
    this->size = size;
    for (int i = 0; i < size; ++i) {
        neuron *n = new neuron(0.00);
        neurons.push_back(n);
    }
}

void MZMTIN002::layer::set_x(int i, double x) {
    neurons.at(i)->set_x(x);
}

MZMTIN002::matrix *MZMTIN002::layer::matrixify_x() {
    matrix* curr_matrix = new matrix(1, neurons.size());
    for (int i = 0; i < neurons.size(); ++i) {
        curr_matrix->set_x(0, i, neurons.at(i)->get_x());
    }

    return curr_matrix;
}

MZMTIN002::matrix *MZMTIN002::layer::matrixify_x_active() {
    matrix* curr_matrix = new matrix(1, neurons.size());
    for (int i = 0; i < neurons.size(); ++i) {
        curr_matrix->set_x(0, i, neurons.at(i)->get_x_active());
    }

    return curr_matrix;
}

MZMTIN002::matrix *MZMTIN002::layer::matrixify_x_derived() {
    matrix* curr_matrix = new matrix(1, neurons.size());
    for (int i = 0; i < neurons.size(); ++i) {
        curr_matrix->set_x(0, i, neurons.at(i)->get_x_derived());
    }

    return curr_matrix;
}
