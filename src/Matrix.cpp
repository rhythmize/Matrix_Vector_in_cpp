//
// Created by rhythm on 24/06/20.
//
#include <Matrix.h>

template<typename T>
Matrix<T>::Matrix(const int &rows, const int &cols, T val) : rows(rows), cols(cols) {
    for (int i = 0; i < this->rows; i++) {
        std::vector<T> temp;
        for (int j = 0; j < this->cols; j++) {
            temp.emplace_back(val);
        }
        this->data.emplace_back(temp);
    }
}

template<typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>> &data) : rows(data.size()), cols(data[0].size()) {
    int len = data[0].size();
    for (int i = 0; i < data.size(); i++)
        if (data[i].size() != len)
            throw std::range_error("Data size varying per row. Can't create matrix !!!");

    this->data.insert(this->data.end(), data.begin(), data.end());
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
    Matrix<T> result = Matrix(this->rows, this->cols, 1);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            result.data[i][j] = this->data[i][j] + m.data[i][j];
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(double factor) {
    Matrix<T> result = Matrix(this->rows, this->cols, 1);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < this->cols; j++)
            result.data[i][j] = factor * this->data[i][j];
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &m) {
    if (this->cols != m.getRows())
        throw std::range_error("Dimensions mismatch for matrix multiplication !!!");
    Matrix<T> result = Matrix(this->rows, m.getCols(), 1);
    for (int i = 0; i < this->rows; i++)
        for (int j = 0; j < m.getCols(); j++) {
            T temp = 0;
            for (int k = 0; k < this->cols; k++)
                temp += (this->data[i][k] * m.data[k][j]);
            result.data[i][j] = temp;
        }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Vector<T> &v) {
    if (this->cols != v.getSize() && this->rows != v.getSize())
        throw std::range_error("Dimensions mismatch for matrix multiplication !!!");

    std::shared_ptr<Matrix<T>> m;
    if (this->cols == v.getSize()) {
        // create column matrix
        m = std::make_shared<Matrix<T>>(v.getSize(), 1, 1);
        for (int i = 0; i < v.getSize(); i++)
            m->data[i][0] = v.data[i];
        return *this * *m;
    } else {
        // create row matrix
        m = std::make_shared<Matrix<T>>(1, v.getSize(), 0);
        for (int i = 0; i < v.getSize(); i++)
            m->data[0][i] = v.data[i];
        return *m * *this;
    }
}

template<typename T>
T &Matrix<T>::at(int i, int j) {
    if (i >= this->getRows() || j >= this->getCols())
        throw std::overflow_error("Out of bounds access !!!");
    return this->data[i][j];
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
