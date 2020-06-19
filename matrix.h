// MZMTIN002

#ifndef ASSIGNMENT_7_MATRIX_H
#define ASSIGNMENT_7_MATRIX_H
#include <vector>
#include <iostream>

using namespace std;

namespace MZMTIN002 {
    class matrix {
    private:
        vector<vector<double>> matrix_vector;   // Holds all matrix values.

        int rows, cols;     // Dimensions of matrix.
    public:
        matrix(int rows, int cols);     // Default oonstructor.

        matrix(int rows, int cols, vector<double> init_weights, bool first, vector<double> hidden_weights);    // Constructor, sets and initialises some values.

        void set_x(int row, int col, double x);     // Set the row, col value to x.

        double get_x(int row, int col);     // Get the x value of row, col.

        int get_rows();     // Getter method for rows.

        int get_cols();     // Getter method for cols.

        void print_output();    // Print out the matrix to the console.
    };
}

#endif //ASSIGNMENT_7_MATRIX_H
