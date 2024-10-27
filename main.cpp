#include "Relation.h"
#include <iostream>

using namespace std;

int main() {
    int row, col, d;
    Relation r;
    Relation rr;

    cin >> d;
    int *M = new int[d * d];

    for (row = 0; row < d; row++)
        for (col = 0; col < d; col++)
            cin >> M[row * d + col];

    r = Relation(d, M);
    delete []M;

    cout << "Is it reflexive: " << (r.IsReflexive() ? "YES" : "NO") << endl;
    cout << "Is it irreflexive: " << (r.IsIrreflexive() ? "YES" : "NO") << endl;
    cout << "Is it symmetric: " << (r.IsSymmetric() ? "YES" : "NO") << endl;
    cout << "Is it asymmetric: " << (r.IsAsymmetric() ? "YES" : "NO") << endl;
    cout << "Is it antisymmetric: " << (r.IsAntisymmetric() ? "YES" : "NO") << endl;
    cout << "Is it transitive: " << (r.IsTransitive() ? "YES" : "NO") << endl;

    cout << endl;
    rr = r.ReflexiveClosure();
    cout << "Its reflexive closure is:" << endl;
    rr.Output();
    rr = r.SymmetricClosure();
    cout << "Its symmetric closure is:" << endl;
    rr.Output();
    rr = r.TransitiveClosure();
    cout << "Its transitive closure is:" << endl;
    rr.Output();

    cout << endl;
    cout << "Is it an equivalent relation: " << (r.IsEquivalence() ? "YES" : "NO") << endl;

    if (r.IsEquivalence()) {
        int i;
        int *EClass = new int[r.GetDimension()];
        r.EquiClasses(EClass);
        cout << "The equivalent classes are:" << endl;
        for (i = 0; i < r.GetDimension(); i++) {
            cout << i;
            if (i != r.GetDimension() - 1)
                cout << ' ';
        }
        cout << endl;
        for (i = 0; i < r.GetDimension(); i++) {
            cout << EClass[i];
            if (i != r.GetDimension() - 1)
                cout << ' ';
        }
        cout << endl;
        delete[] EClass;
    }

    return 0;
}