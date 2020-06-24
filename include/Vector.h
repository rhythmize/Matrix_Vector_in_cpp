//
// Created by rhythm on 24/06/20.
//

#ifndef MATRIX_AND_VECTOR_VECTOR_H
#define MATRIX_AND_VECTOR_VECTOR_H

#include <iostream>
#include <vector>

template<typename T>
class Vector {
public:
    Vector(const T &x, const T &y) : Vector(x, y, 0) {};

    Vector(const T &x, const T &y, const T &z) : x(x), y(y),z(z) {};

    double getMagnitude() const;

    std::vector<double> getCosines() const;

    /*
     * Define overloaded friend function in here, because if defined in cpp file
     * compiler can't find the declaration for templated type
     */
    friend std::ostream &operator<< (std::ostream &output, const Vector<T> &v) {
        output << v.x << "i";
        output << ((v.y >= 0) ? " + " : " - ") << abs(v.y) << "j";
        output << ((v.z >= 0) ? " + " : " - ") << abs(v.z) << "k" << std::endl;
        output << "Magnitude: " << v.getMagnitude() << std::endl;
        output << "Direction Cosines: < ";
        for (auto &val: v.getCosines())
            output << val << " ";
        output << ">" << std::endl;
        return output;
    };

    Vector<T> operator+(const Vector<T> &v);

    Vector<T> operator*(double factor);

    double dot(const Vector<T> &v) const;

    Vector<T> cross(const Vector<T> &v) const;

private:
    T x, y, z;
};

#endif //MATRIX_AND_VECTOR_VECTOR_H
