//
// Created by rhythm on 24/06/20.
//
#include <iostream>
#include <Matrix.h>

template<typename T>
Matrix<T>::Matrix(const T &rows, const T &cols, const T &val) {
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < this->rows; i++) {
        std::vector<T> temp;
        for (int j = 0; j < this->cols; j++) {
            temp.emplace_back(val);
        }
        this->data.emplace_back(temp);
    }
}

template<typename T>
int Matrix<T>::getCols() const {
    return this->cols;
}

template<typename T>
int Matrix<T>::getRows() const {
    return this->rows;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &m) {
    if (this->rows != m.getRows() || this->cols != m.getCols())
        throw std::range_error("Dimensions mismatch for matrix addition !!!");
    Matrix<T> result = Matrix(this->rows, this->cols, 0);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            result.data[i][j] = this->data[i][j] + m.data[i][j];
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(int factor) {
    Matrix<T> result = Matrix(this->rows, this->cols, 0);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            result.data[i][j] = factor * this->data[i][j];
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &m) {
    if (this->cols != m.getRows())
        throw std::range_error("Dimensions mismatch for matrix multiplication !!!");
    Matrix<T> result = Matrix(this->rows, m.getCols(), 0);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < m.getCols(); j++) {
            T temp = 0;
            for (int k = 0; k < this->cols; k++)
                temp += (this->data[i][k] * m.data[k][j]);
            result.data[i][j] = temp;
        }
    return result;
}

/*
 * Avoid linker error, which happen because compiler can't find the template
 * definitions because they are defined in separate cpp files.
 *
 * Declare all the expected types by the template below to avoid linker error in future.
 */
template class Matrix<int>;
template class Matrix<double>;
template class Matrix<float>;
