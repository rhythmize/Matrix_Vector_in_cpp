//
// Created by rhythm on 24/06/20.
//
#include <iostream>
#include <Vector.h>
#include <cmath>

Vector::Vector(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(int x, int y) : Vector(x, y, 0) {

}

double Vector::getMagnitude() const {
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

std::ostream &operator<<(std::ostream &output, const Vector &v) {
    output << v.x << "i + " << v.y << "j + " << v.z << "k" << std::endl;
    output << "Magnitude: " << v.getMagnitude() << std::endl;
    output << "Direction Cosines: < ";
    for (auto &val: v.getCosines())
        output << val << " ";
    output << ">" << std::endl;
    return output;
}

std::vector<double> Vector::getCosines() const {
    std::vector<double> directions(3);
    directions[0] = this->x / this->getMagnitude();
    directions[1] = this->y / this->getMagnitude();
    directions[2] = this->z / this->getMagnitude();
    return directions;
}

Vector Vector::operator+(const Vector &v) {
    Vector result = Vector(0, 0, 0);
    result.x = this->x + v.x;
    result.y = this->y + v.y;
    result.z = this->z + v.z;
    return result;
}

Vector Vector::operator*(int factor) {
    Vector result = Vector(0, 0, 0);
    result.x = this->x * factor;
    result.y = this->y * factor;
    result.z = this->z * factor;
    return result;
}

double Vector::dot(const Vector &v) const {
    double result = 0;
    result += this->x * v.x;
    result += this->y * v.y;
    result += this->z * v.z;
    return result;
}

Vector Vector::cross(const Vector &v) const {
    Vector result = Vector(0, 0, 0);
    result.x = this->y * v.z - v.y * this->z;
    result.y = -1 * (this->x * v.z - v.x * this->z);
    result.z = this->x * v.y - v.x * this->y;
    return result;
}

