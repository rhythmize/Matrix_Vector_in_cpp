//
// Created by rhythm on 24/06/20.
//

#ifndef MATRIX_AND_VECTOR_VECTOR_H
#define MATRIX_AND_VECTOR_VECTOR_H

#include <iostream>
#include <vector>

// forward declare the Vector, as Matrix is a friend class of Vector
template<typename T>
class Matrix;


template<typename T>
class Vector {
public:
    Vector(int size, const T &val);

    double getMagnitude() const;

    int getSize() const;

    std::vector<double> getCosines() const;

    /*
     * Define overloaded friend function in here, because if defined in cpp file
     * compiler can't find the declaration for templated type
     */
    friend std::ostream &operator<<(std::ostream &output, const Vector<T> &v) {
        output << "< ";
        for (int i = 0; i < v.data.size(); i++) {
            output << v.data[i] << " ";
        }
        output << ">" << std::endl;
//        output << v.x << "i";
//        output << ((v.y >= 0) ? " + " : " - ") << abs(v.y) << "j";
//        output << ((v.z >= 0) ? " + " : " - ") << abs(v.z) << "k" << std::endl;
        output << "Magnitude: " << v.getMagnitude() << std::endl;
        if (v.data.size() < 4) {
            output << "Direction Cosines: < ";
            for (auto &val: v.getCosines())
                output << val << " ";
            output << ">" << std::endl;
        }
        return output;
    };

    Vector<T> operator+(const Vector<T> &v);

    Vector<T> operator*(double factor);

    double dot(const Vector<T> &v) const;

    Vector<T> cross(const Vector<T> &v) const;

    T &at(int i);

private:
    std::vector<T> data;
    friend class Matrix<T>;
};

#endif //MATRIX_AND_VECTOR_VECTOR_H
