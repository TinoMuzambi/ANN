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
        int size;

        vector<neuron *> neurons;
    public:
        layer(int size);

        void set_x(int i, double x);

        matrix* get_x_matrix();

        matrix* getX_active_matrix();
    };
}

#endif //ASSIGNMENT_7_LAYER_H
