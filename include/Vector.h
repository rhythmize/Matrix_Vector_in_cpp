//
// Created by rhythm on 24/06/20.
//

#ifndef MATRIX_AND_VECTOR_VECTOR_H
#define MATRIX_AND_VECTOR_VECTOR_H

#include <vector>

class Vector {
public:
    Vector(int x, int y);

    Vector(int x, int y, int z);

    double getMagnitude() const;

    std::vector<double> getCosines() const;

    friend std::ostream &operator<<(std::ostream &output, const Vector &v);

    Vector operator+(const Vector &v);

    Vector operator*(int factor);

    double dot(const Vector &v) const;

    Vector cross(const Vector &v) const;

private:
    int x, y, z;
};

#endif //MATRIX_AND_VECTOR_VECTOR_H
