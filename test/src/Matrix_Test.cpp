//
// Created by rhythm on 24/06/20.
//

#include <Matrix.h>
#include <Matrix_Test.h>

void MatrixTest::SetUpTestCase() {
    m1 = std::make_shared<Matrix<int>>(3, 3, 5);
    m2 = std::make_shared<Matrix<int>>(3, 3, 7);
    std::cout << "Matrix1: "<< std::endl << *m1 << std::endl;
    std::cout << "Matrix2: "<< std::endl << *m2 << std::endl;
}

void MatrixTest::TearDownTestCase() {
    m1 = nullptr;
    m2 = nullptr;
}

TEST_F(MatrixTest, Matrix1) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(m1->at(i, j), 5);
        }
}

TEST_F(MatrixTest, Matrix2) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(m2->at(i, j), 7);
        }
}

TEST_F(MatrixTest, Addition) {
    std::shared_ptr<Matrix<int>> result = std::make_shared<Matrix<int>>(*m1 + *m2);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(result->at(i, j), 12);
        }
}

TEST_F(MatrixTest, ScalarProduct) {
    std::shared_ptr<Matrix<int>> result = std::make_shared<Matrix<int>>(*m1 * 6);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(result->at(i, j), 30);
        }
}

TEST_F(MatrixTest, Multiplication) {
    std::shared_ptr<Matrix<int>> result = std::make_shared<Matrix<int>>(*m1 * *m2);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(result->at(i, j), 105);
        }
}

TEST_F(MatrixTest, UpdateMatrix) {
    m1->at(0, 0) = 0;
    m1->at(1, 1) = 1;
    m1->at(2, 2) = 4;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (i == j)
                EXPECT_EQ(m1->at(i, j), i * j);
            else
                EXPECT_EQ(m1->at(i, j), 5);
        }
}
