//
// Created by rhythm on 24/06/20.
//
#include <iostream>
#include <Matrix.h>
#include <Vector.h>
#include <memory>

void testMatrix() {
    std::cout << "Test Matrix\n========================================================" << std::endl;
    std::shared_ptr<Matrix<int>> m1 = std::make_shared<Matrix<int>>(3, 3, 5);
    std::cout << "Matrix1: " << std::endl << *m1 << std::endl;
    std::shared_ptr<Matrix<int>> m2 = std::make_shared<Matrix<int>>(3, 3, 7);
    std::cout << "Matrix2: " << std::endl << *m2 << std::endl;
    std::cout << "Sum: " << std::endl << *m1 + *m2 << std::endl;
    std::cout << "Scalar Product: " << std::endl << *m1 * 6 << std::endl;
    std::cout << "Matrix Product: " << std::endl << *m1 * *m2 << std::endl;
    m1->at(0, 0) = 8;
    m1->at(1, 1) = 18;
    m1->at(2, 2) = 28;
    std::cout << "Update Matrix1: " << std::endl << *m1;
    std::vector<int> v(5, 1);
}

void testVector() {
    std::cout << "Test Vector\n========================================================" << std::endl;
    std::shared_ptr<Vector<int>> v1 = std::make_shared<Vector<int>>(3, 0);
    v1->at(0) = 1;
    v1->at(1) = 2;
    v1->at(2) = 3;
    std::cout << "Vector1: " << *v1 << std::endl;
    std::shared_ptr<Vector<int>> v2 = std::make_shared<Vector<int>>(3, 0);
    v2->at(0) = 8;
    v2->at(1) = 9;
    v2->at(2) = 15;
    std::cout << "Vector2: " << *v2 << std::endl;
    std::cout << "Sum: " << *v1 + *v2 << std::endl;
    std::cout << "Scalar Product: " << *v1 * 6 << std::endl;
    if (v1->getSize() < 4)
        std::cout << "Cross Product: " << v1->cross(*v2) << std::endl;
    std::cout << "Dot Product: " << v1->dot(*v2) << std::endl;
}

int main() {
    testMatrix();
    testVector();
    return 0;
}
