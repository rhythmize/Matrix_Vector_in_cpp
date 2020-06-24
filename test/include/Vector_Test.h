//
// Created by rhythm on 24/06/20.
//

#ifndef MATRIX_AND_VECTOR_VECTOR_TEST_H
#define MATRIX_AND_VECTOR_VECTOR_TEST_H

#include <memory>
#include <gtest/gtest.h>

class VectorTest : public ::testing::Test {
protected:
    static void SetUpTestCase();

    static void TearDownTestCase();

    // inline to avoid linker error for undefined reference of m1
    // https://stackoverflow.com/questions/42756443/undefined-reference-with-gtest
    static inline std::shared_ptr<Vector <int>> v1, v2;
};

#endif //MATRIX_AND_VECTOR_VECTOR_TEST_H
