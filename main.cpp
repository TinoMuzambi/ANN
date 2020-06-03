#include <iostream>

using namespace std;

double weights[2] = {0.0, 0.0};

double classify(double input) {
    double products[2];
    double curr_sum;
    double threshold;
    products[0] = input * weights[0];
    products[1] = 1.0 * weights[1];
    curr_sum = products[0] + products[1];
    if (curr_sum >= 0) {
        threshold = 1.0;
    }
    else {
        threshold = -1.0;
    }
    return threshold;
}

int main() {
    double inputs[2] = {1.0, 2.0};
    double outputs[2] = {1.0, -1.0};

    bool trained = false;
    while (!trained) {
        trained = true;
        // Output the current training state.
        cout << inputs[0] << " , " << outputs[0] << " Eval = " << classify(inputs[0]) << endl;
        cout << inputs[1] << " , " << outputs[1] << " Eval = " << classify(inputs[1]) << endl;
        cout << "Weights = " << weights[0] << " , " << weights[1] << endl << endl;
        int index = 0;
        // Run through the data and update for misclassifications
        while (index < 2) {
            double input = inputs[index];
            double output = outputs[index];
            double curr_class = classify(input);
            if (curr_class != output) {
                weights[0] = weights[0] + output * input;
                weights[1] = weights[1] + output * 1.0;
                trained = false;
            }
            ++index;
        }
    }
    return 0;
}
