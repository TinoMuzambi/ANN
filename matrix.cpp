// MZMTIN002

#include "matrix.h"

/**
 * Default constructor - Intialises a matrix of rows by cols with zeroes.
 * @param rows number of rows for the matrix.
 * @param cols number of columns for the matrix.
 */
MZMTIN002::matrix::matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;

    for (int i = 0; i < rows; ++i) {
        vector<double> col_values;
        for (int j = 0; j < cols; ++j) {
            col_values.push_back(0);
        }
        matrix_vector.push_back(col_values);
    }
}

/**
 * Constructor - Intialises a matrix of rows by cols with relevant weights..
 * @param rows number of rows for the matrix.
 * @param cols number of columns for the matrix.
 * @param init_weights weights for input layers.
 * @param first is this the first layer?
 * @param hidden_weights weights for hidden layers.
 */
MZMTIN002::matrix::matrix(int rows, int cols, vector<double> init_weights, bool first, vector<double> hidden_weights) {
    this->rows = rows;
    this->cols = cols;

    for (int i = 0; i < rows; ++i) {
        vector<double> col_values;
        for (int j = 0; j < cols; ++j) {
            double weight = first ? init_weights[j + (2 * i)] : hidden_weights[j + i];
            col_values.push_back(weight);
        }
        matrix_vector.push_back(col_values);
    }
}

/**
 * Getter method for the number of rows.
 * @return number of rows for this matrix.
 */
int MZMTIN002::matrix::get_rows() {
    return rows;
}

/**
 * Setter method for the number of columns.
 * @return number of columns for this matrix.
 */
int MZMTIN002::matrix::get_cols() {
    return cols;
}

/**
 * Set the value at row by col to x.
 * @param row coordinates for the value to be set.
 * @param col coordinates for the value to be set.
 * @param x the value to set.
 */
void MZMTIN002::matrix::set_x(int row, int col, double x) {
    this->matrix_vector.at(row).at(col) = x;
}

/**
 * Get the x value at row by col
 * @param row coordinates for the value to get.
 * @param col coordinates for the value to get.
 * @return the x value at coordinates row by col.
 */
double MZMTIN002::matrix::get_x(int row, int col) {
    return this->matrix_vector.at(row).at(col);
}

/**
 * Print the matrix to the console.
 */
void MZMTIN002::matrix::print_output() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << j + 1 << ": " << matrix_vector.at(i).at(j) << endl;
        cout << endl;
    }
}
