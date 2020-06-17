// MZMTIN002

#include "neuron.h"

MZMTIN002::neuron::neuron(double x) {
    this->x = x;
    sigmoid();
    sigmoid_der();
}

void MZMTIN002::neuron::sigmoid() {
    x_active = 1.0 / (1.0 + exp(-1 * x));
}

void MZMTIN002::neuron::sigmoid_der() {
    x_derived = x * (1.0 - x);
}

void MZMTIN002::neuron::set_x(double x) {
    this->x = x;
    sigmoid();
    sigmoid_der();
}
