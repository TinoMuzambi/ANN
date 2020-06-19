// MZMTIN002

#include "matrix.h"
#include "ann.h"

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

MZMTIN002::matrix::matrix(int rows, int cols, vector<double> init_weights, bool first, vector<double> weights) {
    this->rows = rows;
    this->cols = cols;

    for (int i = 0; i < rows; ++i) {
        vector<double> col_values;
        for (int j = 0; j < cols; ++j) {
            double weight = first ? init_weights[j + (2 * i)] : weights[j + i];
            col_values.push_back(weight);
        }
        matrix_vector.push_back(col_values);
    }
}

int MZMTIN002::matrix::get_rows() {
    return rows;
}

int MZMTIN002::matrix::get_cols() {
    return cols;
}

void MZMTIN002::matrix::set_x(int row, int col, double x) {
    this->matrix_vector.at(row).at(col) = x;
}

double MZMTIN002::matrix::get_x(int row, int col) {
    return this->matrix_vector.at(row).at(col);
}

MZMTIN002::matrix *MZMTIN002::matrix::transpose() {
    matrix* transposed_matrix = new matrix(cols, rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed_matrix->set_x(j, i, get_x(i, j));
        }
    }
    return transposed_matrix;
}

void MZMTIN002::matrix::print_output() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << j + 1 << ": " << matrix_vector.at(i).at(j) << endl;
        }
        cout << endl;
    }
}
