//
// Created by rhythm on 24/06/20.
//
#include <iostream>
#include <Matrix.h>

Matrix::Matrix(int rows, int cols, int val) {
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < this->rows; i++) {
        std::vector<int> temp;
        for (int j = 0; j < this->cols; j++) {
            temp.emplace_back(val);
        }
        this->data.emplace_back(temp);
    }
}

int Matrix::getCols() const {
    return this->cols;
}

int Matrix::getRows() const {
    return this->rows;
}

std::ostream &operator<<(std::ostream &output, const Matrix &m) {
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            output << m.data[i][j] << "  ";
        }
        output << std::endl;
    }
    output << std::endl;
    return output;
}

Matrix Matrix::operator+(const Matrix &m) {
    if (this->rows != m.getRows() && this->cols != m.getCols())
        throw std::range_error("Dimensions mismatch for matrix addition !!!");
    Matrix result = Matrix(this->rows, this->cols, 0);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            result.data[i][j] = this->data[i][j] + m.data[i][j];
    return result;
}

Matrix Matrix::operator*(int factor) {
    Matrix result = Matrix(this->rows, this->cols, 0);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            result.data[i][j] = factor * this->data[i][j];
    return result;
}

Matrix Matrix::operator*(const Matrix &m) {
    if (this->cols != m.getRows())
        throw std::range_error("Dimensions mismatch for matrix multiplication !!!");
    Matrix result = Matrix(this->rows, m.getCols(), 0);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < m.getCols(); j++) {
            int temp = 0;
            for (int k = 0; k < this->cols; k++)
                temp += (this->data[i][k] * m.data[k][j]);
            result.data[i][j] = temp;
        }
    return result;
}