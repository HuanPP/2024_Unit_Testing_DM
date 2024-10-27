#include "Relation.h"
#include <cstring>

// 构造函数：创建一个空的关系矩阵
Relation::Relation(int d) {
    dimension = d;
    Matrix = new int[dimension * dimension];
    memset(Matrix, 0, sizeof(int) * dimension * dimension);
}

// 构造函数：根据给定的维度和关系矩阵的值创建关系
Relation::Relation(int d, const int *M) {
    dimension = d;
    Matrix = new int[dimension * dimension];
    memcpy(Matrix, M, sizeof(int) * dimension * dimension);
}

// 拷贝构造函数
Relation::Relation(const Relation &r) {
    dimension = r.dimension;
    Matrix = new int[dimension * dimension];
    memcpy(Matrix, r.Matrix, sizeof(int) * dimension * dimension);
}

// 赋值运算符重载
Relation &Relation::operator =(const Relation &r) {
    if (this != &r) {
        delete[] Matrix;
        dimension = r.dimension;
        Matrix = new int[dimension * dimension];
        memcpy(Matrix, r.Matrix, sizeof(int) * dimension * dimension);
    }
    return *this;
}

// 析构函数
Relation::~Relation() {
    delete[] Matrix;
}

int Relation::GetDimension() const {
    return dimension;
}

int Relation::GetatPosition(int row, int column) const {
    if (row >= 0 && row < dimension && column >= 0 && column < dimension)
        return Matrix[row * dimension + column];
    else
        return -1;
}

int Relation::operator()(int row, int column) const {
    if (row >= 0 && row < dimension && column >= 0 && column < dimension)
        return Matrix[row * dimension + column];
    else
        return -1;
}

bool Relation::GetMatrix(int *result) const {
    if (result != NULL) {
        memcpy(result, Matrix, sizeof(int) * dimension * dimension);
        return true;
    }
    return false;
}

void Relation::Output() const {
    cout << dimension << endl;
    for (int row = 0; row < dimension; row++) {
        for (int column = 0; column < dimension; column++) {
            cout << (*this)(row, column);
        }
        cout << "\n";
    }
}

ostream &operator <<(ostream &os, const Relation &r) {
    int row, column;
    os << r.GetDimension() << endl;
    for (row = 0; row < r.GetDimension(); row++) {
        for (column = 0; column < r.GetDimension(); column++) {
            os << r(row, column);
        }
        os << endl;
    }
    return os;
}

bool Relation::IsReflexive() const
{
    //ToDo：判断该关系的性质
    return true;
}

bool Relation::IsIrreflexive() const
{
    //ToDo：判断该关系的性质
    return true;
}

bool Relation::IsSymmetric() const
{
    //ToDo：判断该关系的性质
    return true;
}

bool Relation::IsAsymmetric() const
{
    //ToDo：判断该关系的性质
    return true;
}

bool Relation::IsAntisymmetric() const
{
    //ToDo：判断该关系的性质
    return true;
}

bool Relation::IsTransitive() const
{
    //ToDo：判断该关系的性质
    return true;
}

bool Relation::IsEquivalence() const
{
    //ToDo：判断该关系是否是一个等价关系
    return true;
}

Relation Relation::ReflexiveClosure() const
{
    int *m = new int[dimension * dimension];
    GetMatrix(m);

    /*
    ToDo: 修改*m，得到自反闭包的关系矩阵，由之构造对象r并返回
    */

    Relation r(dimension, m);
    delete []m;
    return r;
}

Relation Relation::SymmetricClosure() const
{
    int *m = new int[dimension * dimension];
    GetMatrix(m);

    /*
    ToDo: 修改*m，得到对称闭包的关系矩阵，由之构造对象r并返回
    */

    Relation r(dimension, m);
    delete []m;
    return r;
}

Relation Relation::TransitiveClosure() const
{
    int *m = new int[dimension * dimension];
    GetMatrix(m);

    /*
    ToDo: 修改*m，得到传递闭包的关系矩阵，由之构造对象r并返回
    */

    Relation r(dimension, m);
    delete []m;
    return r;
}

bool Relation::EquiClasses(int *result) const
{
    /*
    ToDo: result是一个大小为dimension的数组，如果当前关系是等价关系，则result中存放的是当前关系的各个元素
    所在等价类的编号（编号从0开始，且按照各个元素的值从小到大考虑其所在的等价类编号），并返回true；否则
    result数组中任一项的值都是-1，并返回false。
    */
    memset(result, 255, sizeof(int) * dimension);
    return false;
}
// 其他性质和闭包的函数实现按原代码放置在此处