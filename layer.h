// MZMTIN002

#ifndef ASSIGNMENT_7_LAYER_H
#define ASSIGNMENT_7_LAYER_H
#include "neuron.h"
#include <vector>
#include "matrix.h"

using namespace std;

namespace MZMTIN002 {
    class layer {
    private:
        int size;   // Number of neurons in this layer.

        vector<neuron *> neurons;   // Neurons in this layer.
    public:
        layer(int size);    // Default constructor.

        void set_x(int i, double x);    // Update the value of the neuron at index i.

        matrix* get_x_matrix();     // Get matrix version of layer.

        matrix* getX_active_matrix();   // Get matrix version of activated layer.
    };
}

#endif //ASSIGNMENT_7_LAYER_H
