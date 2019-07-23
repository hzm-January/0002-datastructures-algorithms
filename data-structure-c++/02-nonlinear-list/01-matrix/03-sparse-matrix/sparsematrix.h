//
// Created by asus on 2019/7/23.
//

#ifndef DATA_STRUCTURE_C___SPARSEMATRIX_H
#define DATA_STRUCTURE_C___SPARSEMATRIX_H
#define DefaultSize 100

#include <iostream>

using namespace std;


// 三元组类
template<class T>
struct Trituple {
    int row, col; // 记录矩阵中的行号和列号
    T value; // 记录值
    // 重载赋值运算符
    Trituple<T> &operator=(Trituple<T> &x) {
        row = x.row;
        col = x.col;
        value = x.value;
    }
};

template<class T>
class SparseMatrix {

    template<typename P> friend ostream &operator<<(ostream &out, SparseMatrix<P> &M); //友元函数：输出流操作符重载
    template<typename G> friend istream &operator>>(istream &input, SparseMatrix<G> &M); //友元函数：输入流操作符重载
private:
    int Rows, Cols, Terms; // 稀疏矩阵的行数和列数，Terms为稀疏矩阵的非零元素
    Trituple<T> *smArray;
    int maxTerms; // 三元组元素个数的最大值
public:
    SparseMatrix(int maxSz = DefaultSize); //构造函数
    SparseMatrix(SparseMatrix<T> &x); //复制构造函数
    ~SparseMatrix() { delete[] smArray; } //析构函数
    SparseMatrix &operator=(SparseMatrix &x); //赋值运算符重载
    SparseMatrix<T> transpose(); //矩阵转置
};

template<class T>
SparseMatrix<T>::SparseMatrix(int maxSz):maxTerms(maxSz) {
    if (maxSz < 1) {
        cerr << "initializing the matrix wrong ..., max size is illegal" << endl;
        exit(1);
    }
    smArray = new Trituple<T>[maxSz];
    if (smArray == NULL) {
        cerr << "initialize the matrix wrong..., malloc wrong" << endl;
    }
    Rows = Cols = Terms = 0;
}

template<class T>
SparseMatrix<T>::SparseMatrix(SparseMatrix<T> &x) {
    Rows = x.Rows;
    Cols = x.Cols;
    Terms = x.Terms;
    maxTerms = x.maxTerms;
    smArray = new Trituple<T>[maxTerms];
    if (smArray == NULL) {
        cerr << "initialize the matrix wrong..., malloc wrong" << endl;
    }
    // 逐个拷贝
    for (int i = 0; i < maxTerms; ++i) {
        smArray[i] = x.smArray[i]; //Triuple中的赋值运算符重载
    }
}

// 重载左移运算符 测试时发现必须定义到类内，不然会报错
template<typename P>
ostream &operator<<(ostream &out, SparseMatrix<P> &M) {
    out << "rows = " << M.Rows << endl;
    out << "cols = " << M.Cols << endl;
    out << "terms = " << M.Terms << endl;
    for (int i = 0; i < M.Terms; ++i) {
        out << "M[" << M.smArray[i].row << "][" << M.smArray[i].col << "]=" << M.smArray[i].value << endl;
    }
    return out;
}

// 重载左移运算符 测试时发现必须定义到类内，不然会报错
template<typename G>
istream &operator>> (istream &input, SparseMatrix<G> &M) {
    cout << "Enter number of rows, columns, and terms of Sparse Matrix" << endl;
    input >> M.Rows >> M.Cols >> M.Terms;
    if (M.Terms > M.maxTerms) {
        cerr << "Number of terms overflow!" << endl;
        exit(1);
    }
    for (int i = 0; i < M.Terms; ++i) {
        cout << "Enter number of row, column, and value of term of Trituple" << endl;
        input >> M.smArray[i].row >> M.smArray[i].col >> M.smArray[i].value;
    }
    return input;
}

#endif //DATA_STRUCTURE_C___SPARSEMATRIX_H
