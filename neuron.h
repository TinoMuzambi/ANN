// MZMTIN002

#ifndef ASSIGNMENT_7_NEURON_H
#define ASSIGNMENT_7_NEURON_H

#include <cmath>

namespace MZMTIN002 {
    class neuron {
    private:
        double x, x_active;

    public:
        neuron(double x);    // Default constructor.

        void sigmoid();     // Activation function for this network.

        double get_x();     // Getter method for x.

        double get_x_active();      // Getter method for x_active.

        void set_x(double x);   // Setter method for x.
    };
}

#endif //ASSIGNMENT_7_NEURON_H
