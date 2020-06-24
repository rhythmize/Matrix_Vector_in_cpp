//
// Created by rhythm on 24/06/20.
//

#ifndef MATRIX_AND_VECTOR_MATRIX_H
#define MATRIX_AND_VECTOR_MATRIX_H

#include <vector>
#include <memory>

class Matrix {
public:
    Matrix(int rows, int cols, int val);

    int getCols() const;

    int getRows() const;

    friend std::ostream &operator<<(std::ostream &output, const Matrix &m);

    Matrix operator+(const Matrix &m);

    Matrix operator*(int factor);

    Matrix operator*(const Matrix &m);

private:
    int rows, cols;
    std::vector<std::vector<int>> data;
};

#endif //MATRIX_AND_VECTOR_MATRIX_H
