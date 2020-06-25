//
// Created by rhythm on 24/06/20.
//

#include <Vector.h>
#include <Vector_Test.h>

void VectorTest::SetUpTestCase() {
    int data1[] = {1, 2, 3};
    int data2[] = {8, 9, 15};

    v1 = std::make_shared<Vector<int>>(3, data1);
    v2 = std::make_shared<Vector<int>>(3, data2);
    std::cout << "Vector1: "<< *v1 << std::endl;
    std::cout << "Vector2: "<< *v2 << std::endl;
}

void VectorTest::TearDownTestCase() {
    v1 = nullptr;
    v2 = nullptr;
}

TEST_F(VectorTest, Vector1) {
    EXPECT_NEAR(v1->getMagnitude(), 3.74166, 0.01);
    std::vector<double> cosines = v1->getCosines();
    EXPECT_NEAR(cosines[0], 0.267261, 0.01);
    EXPECT_NEAR(cosines[1], 0.534522, 0.01);
    EXPECT_NEAR(cosines[2], 0.801784, 0.01);
}

TEST_F(VectorTest, Vector2) {
    EXPECT_NEAR(v2->getMagnitude(), 19.2354, 0.01);
    std::vector<double> cosines = v2->getCosines();
    EXPECT_NEAR(cosines[0], 0.4159, 0.01);
    EXPECT_NEAR(cosines[1], 0.467888, 0.01);
    EXPECT_NEAR(cosines[2], 0.779813, 0.01);
}

TEST_F(VectorTest, Addition) {
    std::shared_ptr<Vector<int>> result = std::make_shared<Vector<int>>(*v1 + *v2);
    EXPECT_NEAR(result->getMagnitude(), 22.9347, 0.01);
    std::vector<double> cosines = result->getCosines();
    EXPECT_NEAR(cosines[0], 0.392419, 0.01);
    EXPECT_NEAR(cosines[1], 0.479623, 0.01);
    EXPECT_NEAR(cosines[2], 0.784837, 0.01);
}

TEST_F(VectorTest, ScalarProduct) {
    std::shared_ptr<Vector<int>> result = std::make_shared<Vector<int>>(*v1 * 6);
    EXPECT_NEAR(result->getMagnitude(), 22.4499, 0.01);
    std::vector<double> cosines = result->getCosines();
    EXPECT_NEAR(cosines[0], 0.267261, 0.01);
    EXPECT_NEAR(cosines[1], 0.534522, 0.01);
    EXPECT_NEAR(cosines[2], 0.801784, 0.01);
}

TEST_F(VectorTest, DotProduct) {
    EXPECT_NEAR(v1->dot(*v2), 71, 0.01);
}

TEST_F(VectorTest, CrossProduct) {
    std::shared_ptr<Vector<int>> result = std::make_shared<Vector<int>>(v1->cross(*v2));
    EXPECT_NEAR(result->getMagnitude(), 11.7898, 0.01);
    std::vector<double> cosines = result->getCosines();
    EXPECT_NEAR(cosines[0], 0.254457, 0.01);
    EXPECT_NEAR(cosines[1], 0.76337, 0.01);
    EXPECT_NEAR(cosines[2], -0.593732, 0.01);
}
