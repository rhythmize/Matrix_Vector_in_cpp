//
// Created by rhythm on 24/06/20.
//

#ifndef MATRIX_AND_VECTOR_MATRIX_H
#define MATRIX_AND_VECTOR_MATRIX_H

#include <iostream>
#include <vector>
#include <memory>
#include <Vector.h>

template<typename T>
class Matrix {
public:
    Matrix(const int &rows, const int &cols, T val);

    Matrix(const std::vector<std::vector<T>> &data);

    int getCols() const;

    int getRows() const;

    /*
     * Define overloaded friend function in here, because if defined in cpp file
     * compiler can't find the declaration for templated type
     */
    friend std::ostream &operator<<(std::ostream &output, const Matrix &m) {
        for (int i = 0; i < m.getRows(); i++) {
            for (int j = 0; j < m.getCols(); j++) {
                output << m.data[i][j] << "  ";
            }
            output << std::endl;
        }
        output << std::endl;
        return output;
    }

    Matrix<T> operator+(const Matrix<T> &m);

    T &at(int i, int j);

    Matrix<T> operator*(double factor);

    Matrix<T> operator*(const Matrix<T> &m);

    Matrix<T> operator*(const Vector<T> &v);

private:
    int rows, cols;
    std::vector<std::vector<T>> data;
};

#endif //MATRIX_AND_VECTOR_MATRIX_H
