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

int Matrix::getCols() {
    return this->cols;
}

int Matrix::getRows() {
    return this->rows;
}

std::ostream &operator<<(std::ostream &output, const Matrix &m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            output << m.data[i][j] << "  ";
        }
        output << std::endl;
    }
    output << std::endl;
    return output;
}
