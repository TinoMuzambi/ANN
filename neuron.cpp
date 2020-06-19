// MZMTIN002

#include "neuron.h"

MZMTIN002::neuron::neuron(double x) {
    this->x = x;
    sigmoid();
}

void MZMTIN002::neuron::sigmoid() {
    x_active = 1.0 / (1.0 + exp(-1 * x));
}

void MZMTIN002::neuron::set_x(double x) {
    this->x = x;
    sigmoid();
}

double MZMTIN002::neuron::get_x() {
    return x;
}

double MZMTIN002::neuron::get_x_active() {
    return x_active;
}
