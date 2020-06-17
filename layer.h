// MZMTIN002

#ifndef ASSIGNMENT_7_LAYER_H
#define ASSIGNMENT_7_LAYER_H
#include "neuron.h"
#include <vector>

using namespace std;

namespace MZMTIN002 {
    class layer {
    private:
        int size;

        vector<neuron *> neurons;
    public:
        layer(int size);
    };
}


#endif //ASSIGNMENT_7_LAYER_H
