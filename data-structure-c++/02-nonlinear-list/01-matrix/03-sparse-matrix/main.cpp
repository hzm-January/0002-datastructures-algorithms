//
// Created by asus on 2019/7/23.
//
#include "sparsematrix.h"

int main(int argc, char *argv[]) {

    SparseMatrix<int> sparseMatrix(100);
    cin >> sparseMatrix;
    cout << sparseMatrix;
    cout << "----- transpose simple -----" << endl;
    const SparseMatrix<int> &transposeSimple = sparseMatrix.transposeSimple();
    cout << transposeSimple;
    cout << "----- transpose -----" << endl;
    const SparseMatrix<int> &transpose = sparseMatrix.transpose();
    cout << transpose;
    cout << "----- transpose fast -----" << endl;
    const SparseMatrix<int> &transposeFast = sparseMatrix.transposeFast();
    cout << transposeFast;
    cout << "----- matrix add -----" << endl;
    const SparseMatrix<int> &addResult = sparseMatrix.add(transposeSimple);
    cout << addResult;
    cout << "----- matrix multiply -----" << endl;
    SparseMatrix<int> sparseMatrix2(100);
    cin >> sparseMatrix2;
    cout << sparseMatrix2;
    const SparseMatrix<int> &multiplyResult = sparseMatrix.multiply(sparseMatrix2);
    cout << multiplyResult;
    return 0;
}
