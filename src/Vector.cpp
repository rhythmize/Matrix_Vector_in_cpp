//
// Created by rhythm on 24/06/20.
//
#include <Vector.h>
#include <cmath>

template<typename T>
Vector<T>::Vector(int size, const T &val) {
    for (int i = 0; i < size; i++)
        this->data.emplace_back(val);
}

template<typename T>
int Vector<T>::getSize() const {
    return this->data.size();
}

template<typename T>
double Vector<T>::getMagnitude() const {
    T sum = 0;
    for (int i = 0; i < this->getSize(); i++)
        sum += this->data[i] * this->data[i];
    return sqrt(sum);
}

template<typename T>
std::vector<double> Vector<T>::getCosines() const {
    if (this->getSize() > 3)
        throw std::length_error("Unable to calculate direction cosines for vectors of length >3");
    std::vector<double> directions(3);
    int count = 0, i = 0;
    for (; i < this->getSize(); i++)
        directions[i] = this->data[i] / this->getMagnitude();
    // set remaining direction cosines to 0, if any
    while (i < 3) {
        directions[i] = 0;
        i++;
    }
    return directions;
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &v) {
    if (this->getSize() != v.data.size())
        throw std::range_error("Dimensions mismatch for vector addition !!!");

    Vector<T> result = Vector<T>(this->getSize(), 0);
    for (int i = 0; i < this->getSize(); i++)
        result.data[i] = this->data[i] + v.data[i];
    return result;
}

template<typename T>
Vector<T> Vector<T>::operator*(double factor) {
    Vector<T> result = Vector<T>(this->getSize(), 0);
    for (int i = 0; i < this->getSize(); i++)
        result.data[i] = this->data[i] * factor;
    return result;
}

template<typename T>
double Vector<T>::dot(const Vector<T> &v) const {
    if (this->getSize() != v.data.size())
        throw std::range_error("Dimensions mismatch for vector dot product !!!");

    double result = 0;
    for (int i = 0; i < this->getSize(); i++)
        result += this->data[i] * v.data[i];
    return result;
}

template<typename T>
Vector<T> Vector<T>::cross(const Vector<T> &v) const {
    if (this->getSize() > 3)
        throw std::length_error("Unable to calculate cross product for vectors of length >3");

    if (this->getSize() != v.data.size())
        throw std::range_error("Dimensions mismatch for vector cross product !!!");

    Vector<T> result = Vector<T>(3, 0);
    // created 3d vector from both of existing vectors and then compute cross product
    std::vector<T> vec1(this->data);
    std::vector<T> vec2(v.data);
    while (vec1.size() < 3)
        vec1.push_back(0);
    while (vec2.size() < 3)
        vec2.push_back(0);

    result.data[0] = this->data[1] * v.data[2] - v.data[1] * this->data[2];
    result.data[1] = v.data[0] * this->data[2] - this->data[0] * v.data[2];
    result.data[2] = this->data[0] * v.data[1] - v.data[0] * this->data[1];
    return result;
}

template<typename T>
T &Vector<T>::at(int i) {
    if (i >= this->data.size())
        throw std::overflow_error("Out of bounds access !!!");
    return this->data[i];
}

/*
 * Avoid linker error, which happen because compiler can't find the template
 * definitions because they are defined in separate cpp files.
 *
 * Declare all the expected types by the template below to avoid linker error in future.
 */
template
class Vector<int>;

template
class Vector<double>;

template
class Vector<float>;
