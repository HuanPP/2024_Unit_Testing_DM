#ifndef RELATION_H
#define RELATION_H

#include <iostream>
using namespace std;

class Relation {
protected:
    int dimension;
    int *Matrix;

public:
    Relation(int d = 1);                         // 构造一个维数为d（如不指定，默认为d=1）的空关系
    Relation(int d, const int *M);               // 由关系矩阵的维数和一个关系矩阵的值的数组构造关系
    Relation(const Relation &r);                 // 拷贝构造函数
    Relation &operator =(const Relation &r);     // 赋值运算符重载
    ~Relation();                                 // 析构函数

    int GetDimension() const;                    // 返回关系矩阵的维数
    int GetatPosition(int row, int column) const; // 得到关系矩阵的第row行第column列的值
    int operator() (int row, int column) const;   // 使用R(i,j)来得到关系矩阵的第row行第column列的值
    bool GetMatrix(int *result) const;           // 得到关系矩阵的值
    void Output() const;                         // 在屏幕显示该关系的关系矩阵
    friend ostream &operator <<(ostream &os, const Relation &t); // 以流的方式输出，类似于Output和OutputtoFile

    // 判断关系的性质
    bool IsReflexive() const;
    bool IsIrreflexive() const;
    bool IsSymmetric() const;
    bool IsAsymmetric() const;
    bool IsAntisymmetric() const;
    bool IsTransitive() const;

    // 闭包计算
    Relation ReflexiveClosure() const;
    Relation SymmetricClosure() const;
    Relation TransitiveClosure() const;

    // 判断是否是等价关系
    bool IsEquivalence() const;

    // 等价类计算
    bool EquiClasses(int *result) const;
};

#endif // RELATION_H
