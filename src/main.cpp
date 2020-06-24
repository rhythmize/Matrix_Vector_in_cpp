//
// Created by rhythm on 24/06/20.
//
#include <Matrix.h>
#include <Vector.h>
#include <memory>


int main() {
    std::unique_ptr<Vector> v = std::make_unique<Vector>();
    std::unique_ptr<Matrix> m = std::make_unique<Matrix>();
    return 0;
}
