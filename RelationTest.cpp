#include <gtest/gtest.h>
#include "Relation.h"

// 测试 Relation::IsReflexive
TEST(RelationTest, IsReflexive) {
    int M1[] = {1, 0, 0,  0, 1, 0,  0, 0, 1};
    Relation r1(3, M1);
    ASSERT_TRUE(r1.IsReflexive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M2[] = {0, 1, 0,  1, 1, 0,  0, 0, 1};
    Relation r2(3, M2);
    ASSERT_FALSE(r2.IsReflexive()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M3[] = {1, 1, 1,  1, 1, 1,  1, 1, 1};
    Relation r3(3, M3);
    ASSERT_TRUE(r3.IsReflexive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M4[] = {1, 0, 1,  1, 0, 1,  0, 0, 0};
    Relation r4(3, M4);
    ASSERT_FALSE(r4.IsReflexive()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M5[] = {1, 1, 0,  1, 0, 1,  0, 1, 1};
    Relation r5(3, M5);
    ASSERT_FALSE(r5.IsReflexive()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M_empty[] = {};
    Relation r_empty(0, M_empty);
    ASSERT_TRUE(r_empty.IsReflexive()) << "空矩阵应被视为自反的。";

    int M_high_dim[] = {1, 0, 0, 0,  0, 1, 0, 0,  0, 0, 1, 0,  0, 0, 0, 1};
    Relation r_high_dim(4, M_high_dim);
    ASSERT_TRUE(r_high_dim.IsReflexive()) << "4x4 矩阵应被视为自反的。";
}

// 测试 Relation::IsIrreflexive
TEST(RelationTest, IsIrreflexive) {
    int M1[] = {0, 1, 0,  1, 0, 1,  0, 1, 0};
    Relation r1(3, M1);
    ASSERT_TRUE(r1.IsIrreflexive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M2[] = {1, 0, 0,  0, 1, 0,  0, 0, 1};
    Relation r2(3, M2);
    ASSERT_FALSE(r2.IsIrreflexive()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M3[] = {0, 0, 0,  0, 0, 0,  0, 0, 0};
    Relation r3(3, M3);
    ASSERT_TRUE(r3.IsIrreflexive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M4[] = {0, 1, 0,  0, 0, 1,  1, 0, 0};
    Relation r4(3, M4);
    ASSERT_TRUE(r4.IsIrreflexive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M5[] = {0, 0, 0,  0, 1, 0,  0, 0, 0};
    Relation r5(3, M5);
    ASSERT_FALSE(r5.IsIrreflexive()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M_empty[] = {};
    Relation r_empty(0, M_empty);
    ASSERT_TRUE(r_empty.IsIrreflexive()) << "空矩阵应被视为反自反的。";

    int M_high_dim[] = {0, 1, 0, 1,  1, 0, 1, 0,  0, 1, 0, 1,  1, 0, 1, 0};
    Relation r_high_dim(4, M_high_dim);
    ASSERT_TRUE(r_high_dim.IsIrreflexive()) << "4x4 矩阵应被视为反自反的。";
}

// 测试 Relation::IsSymmetric
TEST(RelationTest, IsSymmetric) {
    int M1[] = {1, 1, 0,  1, 1, 0,  0, 0, 1};
    Relation r1(3, M1);
    ASSERT_TRUE(r1.IsSymmetric()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M2[] = {1, 1, 0,  0, 1, 0,  0, 0, 1};
    Relation r2(3, M2);
    ASSERT_FALSE(r2.IsSymmetric()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M3[] = {1, 0, 0,  0, 1, 0,  0, 0, 1};
    Relation r3(3, M3);
    ASSERT_TRUE(r3.IsSymmetric()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M4[] = {0, 1, 1,  1, 1, 1,  1, 1, 0};
    Relation r4(3, M4);
    ASSERT_TRUE(r4.IsSymmetric()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M5[] = {0, 1, 0,  1, 1, 0,  1, 0, 1};
    Relation r5(3, M5);
    ASSERT_FALSE(r5.IsSymmetric()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M_empty[] = {};
    Relation r_empty(0, M_empty);
    ASSERT_TRUE(r_empty.IsSymmetric()) << "空矩阵应被视为对称的。";

    int M_high_dim[] = {1, 1, 0, 1,  1, 1, 0, 1,  0, 0, 1, 0,  1, 0, 0, 1};
    Relation r_high_dim(4, M_high_dim);
    ASSERT_TRUE(r_high_dim.IsSymmetric()) << "4x4 矩阵应被视为对称的。";
}

// 测试 Relation::IsAsymmetric
TEST(RelationTest, IsAsymmetric) {
    int M1[] = {0, 1, 0,  0, 0, 1,  0, 0, 0};
    Relation r1(3, M1);
    ASSERT_TRUE(r1.IsAsymmetric()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M2[] = {0, 1, 0,  1, 0, 0,  0, 0, 0};
    Relation r2(3, M2);
    ASSERT_FALSE(r2.IsAsymmetric()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M3[] = {0, 0, 0,  0, 0, 0,  0, 0, 0};
    Relation r3(3, M3);
    ASSERT_TRUE(r3.IsAsymmetric()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M4[] = {0, 1, 1,  0, 0, 1,  0, 0, 0};
    Relation r4(3, M4);
    ASSERT_TRUE(r4.IsAsymmetric()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M5[] = {1, 0, 0,  0, 1, 1,  0, 0, 0};
    Relation r5(3, M5);
    ASSERT_FALSE(r5.IsAsymmetric()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M_empty[] = {};
    Relation r_empty(0, M_empty);
    ASSERT_TRUE(r_empty.IsAsymmetric()) << "空矩阵应被视为反对称的。";

    int M_high_dim[] = {0, 1, 0, 0,  0, 0, 1, 0,  0, 0, 0, 1,  0, 0, 0, 0};
    Relation r_high_dim(4, M_high_dim);
    ASSERT_TRUE(r_high_dim.IsAsymmetric()) << "4x4 矩阵应被视为反对称的。";
}

// 测试 Relation::IsAntisymmetric
TEST(RelationTest, IsAntisymmetric) {
    int M1[] = {1, 0, 0,  0, 1, 0,  0, 0, 1};
    Relation r1(3, M1);
    ASSERT_TRUE(r1.IsAntisymmetric()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M2[] = {0, 1, 0,  1, 1, 0,  0, 0, 1};
    Relation r2(3, M2);
    ASSERT_FALSE(r2.IsAntisymmetric()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M3[] = {1, 0, 0,  0, 1, 0,  0, 1, 1};
    Relation r3(3, M3);
    ASSERT_FALSE(r3.IsAntisymmetric()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M4[] = {0, 0, 1,  0, 1, 0,  1, 0, 1};
    Relation r4(3, M4);
    ASSERT_FALSE(r4.IsAntisymmetric()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M5[] = {1, 0, 0,  0, 1, 1,  0, 1, 1};
    Relation r5(3, M5);
    ASSERT_FALSE(r5.IsAntisymmetric()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M_empty[] = {};
    Relation r_empty(0, M_empty);
    ASSERT_TRUE(r_empty.IsAntisymmetric()) << "空矩阵应被视为反对称的。";

    int M_high_dim[] = {1, 1, 1, 0,  0, 1, 0, 1,  1, 0, 1, 0,  0, 1, 0, 1};
    Relation r_high_dim(4, M_high_dim);
    ASSERT_FALSE(r_high_dim.IsAntisymmetric()) << "4x4 矩阵不应被视为反对称的。";
}

// 测试 Relation::IsTransitive
TEST(RelationTest, IsTransitive) {
    int M1[] = {1, 1, 0,  0, 1, 1,  0, 0, 1};
    Relation r1(3, M1);
    ASSERT_TRUE(r1.IsTransitive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M2[] = {1, 1, 0,  0, 1, 1,  1, 0, 1};
    Relation r2(3, M2);
    ASSERT_FALSE(r2.IsTransitive()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M3[] = {1, 0, 0,  0, 1, 0,  0, 0, 1};
    Relation r3(3, M3);
    ASSERT_TRUE(r3.IsTransitive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M4[] = {1, 1, 1,  1, 1, 1,  1, 1, 1};
    Relation r4(3, M4);
    ASSERT_TRUE(r4.IsTransitive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M5[] = {1, 0, 1,  0, 1, 0, 1, 0, 1};
    Relation r5(3, M5);
    ASSERT_FALSE(r5.IsTransitive()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M_empty[] = {};
    Relation r_empty(0, M_empty);
    ASSERT_TRUE(r_empty.IsTransitive()) << "空矩阵应被视为传递的。";

    int M_high_dim[] = {1, 1, 1, 0,  0, 1, 0, 1,  1, 0, 1, 0,  0, 1, 0, 1};
    Relation r_high_dim(4, M_high_dim);
    ASSERT_FALSE(r_high_dim.IsTransitive()) << "4x4 矩阵不应被视为传递的。";
}

// 测试 Relation::ReflexiveClosure
TEST(RelationTest, ReflexiveClosure) {
    int M1[] = {0, 1, 0,  1, 0, 1,  0, 1, 0};
    Relation r1(3, M1);
    Relation rc1 = r1.ReflexiveClosure();
    ASSERT_TRUE(rc1.IsReflexive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M2[] = {1, 1, 0,  1, 0, 0,  0, 1, 1};
    Relation r2(3, M2);
    Relation rc2 = r2.ReflexiveClosure();
    ASSERT_TRUE(rc2.IsReflexive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M3[] = {1, 1, 1,  1, 0, 1,  1, 1, 1};
    Relation r3(3, M3);
    Relation rc3 = r3.ReflexiveClosure();
    ASSERT_TRUE(rc3.IsReflexive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M4[] = {0, 0, 0,  0, 0, 0,  0, 0, 0};
    Relation r4(3, M4);
    Relation rc4 = r4.ReflexiveClosure();
    ASSERT_TRUE(rc4.IsReflexive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M5[] = {1, 1, 1,  1, 1, 1,  1, 1, 1};
    Relation r5(3, M5);
    Relation rc5 = r5.ReflexiveClosure();
    ASSERT_TRUE(rc5.IsReflexive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M_empty[] = {};
    Relation r_empty(0, M_empty);
    Relation rc_empty = r_empty.ReflexiveClosure();
    ASSERT_TRUE(rc_empty.IsReflexive()) << "空矩阵的自反闭包应是自反的。";

    int M_high_dim[] = {0, 1, 0, 0,  1, 0, 1, 0,  0, 1, 0, 0,  0, 0, 0, 0};
    Relation r_high_dim(4, M_high_dim);
    Relation rc_high_dim = r_high_dim.ReflexiveClosure();
    ASSERT_TRUE(rc_high_dim.IsReflexive()) << "4x4 矩阵的自反闭包应是自反的。";
}

// 测试 Relation::SymmetricClosure
TEST(RelationTest, SymmetricClosure) {
    int M1[] = {1, 0, 1,  0, 1, 0,  0, 0, 1};
    Relation r1(3, M1);
    Relation sc1 = r1.SymmetricClosure();
    ASSERT_TRUE(sc1.IsSymmetric()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M2[] = {0, 1, 0,  1, 0, 1,  0, 1, 0};
    Relation r2(3, M2);
    Relation sc2 = r2.SymmetricClosure();
    ASSERT_TRUE(sc2.IsSymmetric()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M3[] = {1, 0, 0,  0, 1, 0,  0, 0, 1};
    Relation r3(3, M3);
    Relation sc3 = r3.SymmetricClosure();
    ASSERT_TRUE(sc3.IsSymmetric()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M4[] = {0, 0, 0,  0, 1, 1,  1, 1, 0};
    Relation r4(3, M4);
    Relation sc4 = r4.SymmetricClosure();
    ASSERT_TRUE(sc4.IsSymmetric()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M5[] = {1, 1, 1,  1, 1, 1,  1, 1, 1};
    Relation r5(3, M5);
    Relation sc5 = r5.SymmetricClosure();
    ASSERT_TRUE(sc5.IsSymmetric()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M_empty[] = {};
    Relation r_empty(0, M_empty);
    Relation sc_empty = r_empty.SymmetricClosure();
    ASSERT_TRUE(sc_empty.IsSymmetric()) << "空矩阵的对称闭包应是对称的。";

    int M_high_dim[] = {1, 0, 0, 1,  0, 1, 0, 1,  0, 0, 1, 0,  1, 0, 0, 1};
    Relation r_high_dim(4, M_high_dim);
    Relation sc_high_dim = r_high_dim.SymmetricClosure();
    ASSERT_TRUE(sc_high_dim.IsSymmetric()) << "4x4 矩阵的对称闭包应是对称的。";
}

// 测试 Relation::TransitiveClosure
TEST(RelationTest, TransitiveClosure) {
    int M1[] = {1, 1, 0,  0, 1, 1,  0, 0, 1};
    Relation r1(3, M1);
    Relation tc1 = r1.TransitiveClosure();
    ASSERT_TRUE(tc1.IsTransitive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M2[] = {1, 0, 1,  1, 1, 0,  0, 1, 1};
    Relation r2(3, M2);
    Relation tc2 = r2.TransitiveClosure();
    ASSERT_TRUE(tc2.IsTransitive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M3[] = {0, 1, 0,  0, 0, 1,  1, 0, 0};
    Relation r3(3, M3);
    Relation tc3 = r3.TransitiveClosure();
    ASSERT_TRUE(tc3.IsTransitive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M4[] = {0, 1, 0,  0, 1, 0,  0, 1, 1};
    Relation r4(3, M4);
    Relation tc4 = r4.TransitiveClosure();
    ASSERT_TRUE(tc4.IsTransitive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M5[] = {1, 1, 1,  1, 1, 1,  1, 1, 1};
    Relation r5(3, M5);
    Relation tc5 = r5.TransitiveClosure();
    ASSERT_TRUE(tc5.IsTransitive()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M_empty[] = {};
    Relation r_empty(0, M_empty);
    Relation tc_empty = r_empty.TransitiveClosure();
    ASSERT_TRUE(tc_empty.IsTransitive()) << "空矩阵的传递闭包应是传递的。";

    int M_high_dim[] = {1, 1, 0, 1,  0, 1, 1, 0,  0, 0, 1, 0,  1, 0, 0, 1};
    Relation r_high_dim(4, M_high_dim);
    Relation tc_high_dim = r_high_dim.TransitiveClosure();
    ASSERT_TRUE(tc_high_dim.IsTransitive()) << "4x4 矩阵的传递闭包应是传递的。";
}

// 测试 Relation::IsEquivalence
TEST(RelationTest, IsEquivalence) {
    int M1[] = {1, 1, 1,  1, 1, 1,  1, 1, 1};
    Relation r1(3, M1);
    ASSERT_TRUE(r1.IsEquivalence()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M2[] = {1, 0, 0,  0, 1, 1,  0, 0, 1};
    Relation r2(3, M2);
    ASSERT_FALSE(r2.IsEquivalence()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M3[] = {1, 1, 0,  1, 1, 1,  0, 1, 1};
    Relation r3(3, M3);
    ASSERT_TRUE(r3.IsEquivalence()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M4[] = {1, 0, 0,  1, 1, 0,  0, 1, 1};
    Relation r4(3, M4);
    ASSERT_FALSE(r4.IsEquivalence()) << "测试失败，期待结果为：false，你判断的结果为：true";

    int M5[] = {1, 1, 0,  1, 1, 0,  0, 1, 1};
    Relation r5(3, M5);
    ASSERT_TRUE(r5.IsEquivalence()) << "测试失败，期待结果为：true，你判断的结果为：false";

    int M_empty[] = {};
    Relation r_empty(0, M_empty);
    ASSERT_TRUE(r_empty.IsEquivalence()) << "空矩阵应被视为等价关系。";

    int M_high_dim[] = {1, 1, 0, 1,  1, 1, 0, 1,  0, 0, 1, 0,  1, 0, 0, 1};
    Relation r_high_dim(4, M_high_dim);
    ASSERT_FALSE(r_high_dim.IsEquivalence()) << "4x4 矩阵不应被视为等价关系。";
}

// 使用 Google Test 的默认 main 函数
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}