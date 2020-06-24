//
// Created by rhythm on 24/06/20.
//
#include <iostream>
#include <Matrix.h>
#include <Vector.h>
#include <memory>

void testMatrix() {
    std::cout << "Test Matrix\n========================================================" << std::endl;
    std::shared_ptr<Matrix> m1 = std::make_shared<Matrix>(3, 3, 5);
    std::cout << "Matrix1: " << *m1 << std::endl;
    std::shared_ptr<Matrix> m2 = std::make_shared<Matrix>(3, 3, 7);
    std::cout << "Matrix2: " << *m2 << std::endl;
    std::cout << "Sum: " << *m1 + *m2 << std::endl;
    std::cout << "Scalar Product: " << *m1 * 6 << std::endl;
    std::cout << "Matrix Product: " << *m1 * *m2 << std::endl;
}

void testVector() {
    std::cout << "Test Vector\n========================================================" << std::endl;
    std::shared_ptr<Vector<int>> v1 = std::make_shared<Vector<int>>(1, 2, 3);
    std::cout << "Vector1: " << *v1 << std::endl;
    std::shared_ptr<Vector<int>> v2 = std::make_shared<Vector<int>>(8, 9, 15);
    std::cout << "Vector2: " << *v2 << std::endl;
    std::cout << "Sum: " << *v1 + *v2 << std::endl;
    std::cout << "Scalar Product: " << *v1 * 6 << std::endl;
    std::cout << "Cross Product: " << v1->cross(*v2) << std::endl;
    std::cout << "Dot Product: " << v1->dot(*v2) << std::endl;
}

int main() {
    testMatrix();
    testVector();
    return 0;
}
