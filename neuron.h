// MZMTIN002

#ifndef ASSIGNMENT_7_NEURON_H
#define ASSIGNMENT_7_NEURON_H

#include <cmath>

namespace MZMTIN002 {
    class neuron {
    private:
        double x;
        double x_active;
        double x_derived;
    public:
        neuron(double x);

        void sigmoid();

        void sigmoid_der();

        double get_x();

        double get_x_active();

        double get_x_derived();

        void set_x(double x);
    };
}


#endif //ASSIGNMENT_7_NEURON_H
