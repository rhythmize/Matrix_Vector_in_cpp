//
// Created by rhythm on 24/06/20.
//
#include <Vector.h>
#include <cmath>

template<typename T>
double Vector<T>::getMagnitude() const {
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

template<typename T>
std::vector<double> Vector<T>::getCosines() const {
    std::vector<double> directions(3);
    directions[0] = this->x / this->getMagnitude();
    directions[1] = this->y / this->getMagnitude();
    directions[2] = this->z / this->getMagnitude();
    return directions;
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T> &v) {
    Vector<T> result = Vector<T>(0, 0, 0);
    result.x = this->x + v.x;
    result.y = this->y + v.y;
    result.z = this->z + v.z;
    return result;
}

template<typename T>
Vector<T> Vector<T>::operator*(double factor) {
    Vector<T> result = Vector<T>(0, 0, 0);
    result.x = this->x * factor;
    result.y = this->y * factor;
    result.z = this->z * factor;
    return result;
}

template<typename T>
double Vector<T>::dot(const Vector<T> &v) const {
    double result = 0;
    result += this->x * v.x;
    result += this->y * v.y;
    result += this->z * v.z;
    return result;
}

template<typename T>
Vector<T> Vector<T>::cross(const Vector<T> &v) const {
    Vector<T> result = Vector<T>(0, 0, 0);
    result.x = this->y * v.z - v.y * this->z;
    result.y = v.x * this->z - this->x * v.z;
    result.z = this->x * v.y - v.x * this->y;
    return result;
}

/*
 * Avoid linker error, which happen because compiler can't find the template
 * definitions because they are defined in separate cpp files.
 *
 * Declare all the expected types by the template below to avoid linker error in future.
 */
template class Vector<int>;
template class Vector<double>;
template class Vector<float>;
