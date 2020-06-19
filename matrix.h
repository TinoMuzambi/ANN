// MZMTIN002

#ifndef ASSIGNMENT_7_MATRIX_H
#define ASSIGNMENT_7_MATRIX_H
#include <vector>
#include <iostream>

using namespace std;

namespace MZMTIN002 {
    class matrix {
    private:
        vector<vector<double>> matrix_vector;

        int rows, cols;
    public:
        matrix(int rows, int cols);

        matrix(int rows, int cols, vector<double> init_weights, bool first, vector<double> weights);

        void set_x(int row, int col, double x);

        double get_x(int row, int col);

        int get_rows();

        int get_cols();

        void print_output();
    };
}

#endif //ASSIGNMENT_7_MATRIX_H
