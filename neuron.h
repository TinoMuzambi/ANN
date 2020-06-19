// MZMTIN002

#ifndef ASSIGNMENT_7_NEURON_H
#define ASSIGNMENT_7_NEURON_H

#include <cmath>

namespace MZMTIN002 {
    class neuron {
    private:
        double x, x_active;

    public:
        neuron(double x);

        void sigmoid();

        double get_x();

        double get_x_active();

        void set_x(double x);
    };
}

#endif //ASSIGNMENT_7_NEURON_H
