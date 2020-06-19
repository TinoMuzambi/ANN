// MZMTIN002

#include "layer.h"

/**
 * Constructor - sets size and initialises vector of neurons.
 * @param size number of neurons in this layer.
 */
MZMTIN002::layer::layer(int size) {
    this->size = size;
    for (int i = 0; i < this->size; ++i) {
        neuron *n = new neuron(0.00);
        neurons.push_back(n);
    }
}

/**
 * Set value of the ith neuron in this layer to x.
 * @param i index of the neuron to be set.
 * @param x the value to set the neuron to.
 */
void MZMTIN002::layer::set_x(int i, double x) {
    neurons.at(i)->set_x(x);
}

/**
 * Get neuron as a matrix.
 * @return a matrix containing the neuron's attributes.
 */
MZMTIN002::matrix *MZMTIN002::layer::get_x_matrix() {
    matrix* curr_matrix = new matrix(1, neurons.size());
    for (int i = 0; i < neurons.size(); ++i)
        curr_matrix->set_x(0, i, neurons.at(i)->get_x());

    return curr_matrix;
}

/**
 * Get activated neuron as a matrix.
 * @return a matrix containing the neuron's activated attributes.
 */
MZMTIN002::matrix *MZMTIN002::layer::getX_active_matrix() {
    matrix* curr_matrix = new matrix(1, neurons.size());
    for (int i = 0; i < neurons.size(); ++i)
        curr_matrix->set_x(0, i, neurons.at(i)->get_x_active());

    return curr_matrix;
}