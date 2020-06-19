// MZMTIN002

#include "neuron.h"

/**
 * Default constructor - sets x and activates it by calling sigmoid function.
 * @param x the value of this neuron.
 */
MZMTIN002::neuron::neuron(double x) {
    this->x = x;
    sigmoid();
}

/**
 * Sigmoid activation function. Sets the value of x_active.
 */
void MZMTIN002::neuron::sigmoid() {
    x_active = 1.0 / (1.0 + exp(-1 * x));
}

/**
 * Setter method for x.
 * @param x the value to be set.
 */
void MZMTIN002::neuron::set_x(double x) {
    this->x = x;
    sigmoid();
}

/**
 * Getter method for x.
 * @return the x value.
 */
double MZMTIN002::neuron::get_x() {
    return x;
}

/**
 * Getter method for x_active.
 * @return the x_active value.
 */
double MZMTIN002::neuron::get_x_active() {
    return x_active;
}
