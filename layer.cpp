// MZMTIN002

#include "layer.h"

MZMTIN002::layer::layer(int size) {
    this->size = size;
    for (int i = 0; i < size; ++i) {
        neuron *n = new neuron(0.00);
        neurons.push_back(n);
    }
}
