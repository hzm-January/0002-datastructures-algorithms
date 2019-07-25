//
// Created by asus on 2019/7/23.
//

#ifndef DATA_STRUCTURE_C___SPARSEMATRIX_H
#define DATA_STRUCTURE_C___SPARSEMATRIX_H
#define DefaultSize 100

#include <iostream>
#include <memory.h>

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
        return *this;
    }
};

template<class T>
class SparseMatrix {
    template<typename P>
    friend ostream &operator<<(ostream &out, const SparseMatrix<P> &M); //友元函数：输出流操作符重载
    template<typename G>
    friend istream &operator>>(istream &input, SparseMatrix<G> &M); //友元函数：输入流操作符重载
private:
    int Rows, Cols, Terms; // 稀疏矩阵的行数和列数，Terms为稀疏矩阵的非零元素
    Trituple<T> *smArray;
    int maxTerms; // 三元组元素个数的最大值
public:
    SparseMatrix(int maxSz = DefaultSize); //构造函数
    SparseMatrix(SparseMatrix<T> &x); //复制构造函数
    ~SparseMatrix() { delete[] smArray; } //析构函数
    SparseMatrix &operator=(SparseMatrix &x); //赋值运算符重载
    SparseMatrix<T> transposeSimple(); //矩阵转置
    SparseMatrix<T> transpose(); //矩阵转置
    SparseMatrix<T> transposeFast(); //矩阵转置
    void sort(Trituple<T> *h, int size); //对矩阵中的三元组表按照行号进行排序
    SparseMatrix<T> add(const SparseMatrix<T> &x); //矩阵相加
    SparseMatrix<T> multiply(const SparseMatrix<T> &x); //矩阵相乘

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
ostream &operator<<(ostream &out, const SparseMatrix<P> &M) {
    out << "rows = " << M.Rows << endl;
    out << "cols = " << M.Cols << endl;
    out << "terms = " << M.Terms << endl;
    for (int i = 0; i < M.Terms; ++i) {
        out << "M[" << M.smArray[i].row << "][" << M.smArray[i].col << "]=" << M.smArray[i].value << endl;
    }
    return out;
}

//// 重载左移运算符 测试时发现必须定义到类内，不然会报错
template<typename G>
istream &operator>>(istream &input, SparseMatrix<G> &M) {
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
    M.sort(M.smArray, M.Terms);
    return input;
}

/**
 * 矩阵相加
 * 矩阵相加的必要条件：两个矩阵的Cols和Rows一致
 * @tparam T
 * @param x
 * @return
 */
template<class T>
SparseMatrix<T> SparseMatrix<T>::add(const SparseMatrix<T> &x) {
    SparseMatrix<T> result(maxTerms);
    result.Cols = Cols;
    result.Rows = Rows;
    result.Terms = 0;
    int i = 0, j = 0, index_a = 0, index_b = 0;
    while (i < Terms && j < x.Terms) {
        index_a = smArray[i].row * Cols + smArray[i].col;
        index_b = x.smArray[j].row * Cols + x.smArray[j].col;
        if (index_a < index_b) {
            result.smArray[result.Terms] = smArray[i++];
        } else if (index_a > index_b) {
            result.smArray[result.Terms] = x.smArray[j++];
        } else {
            result.smArray[result.Terms] = smArray[i];
            result.smArray[result.Terms].value = x.smArray[j++].value + smArray[i++].value;
        }
        result.Terms++;
    }
    for (; i < Terms; ++i) {
        result.smArray[result.Terms++] = smArray[i];
    }
    for (; j < x.Terms; ++j) {
        result.smArray[result.Terms++] = x.smArray[j];
    }
    return result;
}

/**
 * 矩阵转置
 * 复杂度为O(Terms)
 * @tparam T
 * @return
 */
template<class T>
SparseMatrix<T> SparseMatrix<T>::transposeSimple() { //矩阵转置
    SparseMatrix<T> sparseMatrix(maxTerms);
    sparseMatrix.Cols = Rows;
    sparseMatrix.Rows = Cols;
    sparseMatrix.Terms = Terms;
    // 算法主要思想：遍历获取每一个三元组，将行号和列号互换
    for (int i = 0; i < Terms; ++i) {
        Trituple<T> &trituple = smArray[i];
        sparseMatrix.smArray[i].row = trituple.col;
        sparseMatrix.smArray[i].col = trituple.row;
        sparseMatrix.smArray[i].value = trituple.value;
    }
    sort(sparseMatrix.smArray, sparseMatrix.Terms);
    return sparseMatrix;
}

/**
 * 矩阵转置
 * 复杂度O(Cols*Terms)
 * @tparam T
 * @return
 */
template<class T>
SparseMatrix<T> SparseMatrix<T>::transpose() {
    // 算法主要思想：对三元组表进行Cols趟扫描，第k趟扫描是寻找列号为k的三元组。找到并存放到转置后的第k行
    SparseMatrix<T> sparseMatrix(maxTerms);
    sparseMatrix.Cols = Rows;
    sparseMatrix.Rows = Cols;
    sparseMatrix.Terms = Terms;
    int currentIndex = 0;
    for (int i = 0; i < Cols; ++i) {
        for (int j = 0; j < Terms; ++j) {
            if (smArray[j].col == i) {
                sparseMatrix.smArray[currentIndex].col = smArray[j].row;
                sparseMatrix.smArray[currentIndex].row = smArray[j].col;
                sparseMatrix.smArray[currentIndex].value = smArray[j].value;
                currentIndex++;
            }
        }
    }
    return sparseMatrix;
}

/**
 * 矩阵转置
 * 时间复杂度O(Terms+Cols)
 */
template<class T>
SparseMatrix<T> SparseMatrix<T>::transposeFast() {
    // 算法主要思想：扫描Cols一趟，记录转置后每行的三元组数，统计转置后每行开始的三元组在新三元组表中的索引
    SparseMatrix<T> sparseMatrix(maxTerms);
    sparseMatrix.Cols = Rows;
    sparseMatrix.Rows = Cols;
    sparseMatrix.Terms = Terms;
    int *rowSize = new int[Cols];
    int *rowStart = new int[Cols];
    memset(rowSize, 0, sizeof(int) * Cols);
    memset(rowStart, 0, sizeof(int) * Cols);
    for (int i = 0; i < Terms; ++i) {
        rowSize[smArray[i].col]++;
    }
    for (int j = 1; j < Cols; ++j) {
        rowStart[j] = rowStart[j - 1] + rowSize[j - 1];
    }
    for (int k = 0; k < Terms; ++k) {
        int index = rowStart[smArray[k].col]++;
        sparseMatrix.smArray[index].row = smArray[k].col;
        sparseMatrix.smArray[index].col = smArray[k].row;
        sparseMatrix.smArray[index].value = smArray[k].value;
    }
    delete[]rowSize, delete[]rowStart;
    sort(sparseMatrix.smArray, sparseMatrix.Terms);
    return sparseMatrix;
}

/**
 * 插入排序
 * @tparam H
 * @param h
 * @param size
 */
template<class T>
void SparseMatrix<T>::sort(Trituple<T> *h, int size) {
    for (int i = 1; i < size; ++i) {
        Trituple<T> current = h[i];
        int j = i - 1;
        while (j >= 0 && h[j].row > current.row) {
            h[j + 1] = h[j];
            j--;
        }
        h[j + 1] = current;
    }
}

/**
 * 矩阵相乘
 *
 * @param x
 * @return
 */
template<class T>
SparseMatrix<T> SparseMatrix<T>::multiply(const SparseMatrix<T> &x) {
    SparseMatrix<T> result(maxTerms);
    //扫描乘数矩阵，统计被乘矩阵中的所有行元素个数
    int *rowSize = new int[x.Rows];
    memset(rowSize, 0, sizeof(int) * x.Rows);
    for (int i = 0; i < x.Terms; ++i) {
        rowSize[x.smArray[i].row]++;
    }
    //统计乘数矩阵每行开始元素在被乘矩阵的三元组表中的索引
    int *rowStart = new int[x.Rows];
    memset(rowStart, 0, sizeof(int) * x.Rows);
    for (int j = 1; j < x.Terms; ++j) {
        rowStart[j] = rowStart[j - 1] + rowSize[j - 1];
    }

    //遍历被乘矩阵，取出(a,b)坐标的元素，获取乘数矩阵中b行的每个元素(b,*)，依次相乘并累加到(a,*)上
    int current = 0, lastInResult = 0, RowA = 0, RowB = 0;

    while (current < Terms) {
        RowA = smArray[current].row; //A矩阵的当前行行号
        T *temp = new T[x.Cols]; //A矩阵当前行和B矩阵每一列每个元素相乘的叠加结果
        while (current < Terms && smArray[current].row == RowA) { //取A矩阵中RowA行每一个元素
            // 依次取出A矩阵中RowA行的元素(a,b)，并与对应的B矩阵中的(b,*)相乘
            RowB = smArray[current].col;
            for (int i = rowStart[RowB]; i < rowStart[RowB + 1]; ++i) { //取B矩阵中对应RowA矩阵当前元素列号相等行的每一个元素
                temp[x.smArray[i].col] += smArray[current].value * x.smArray[i].value;
            }
            current++; //取A矩阵中RowA行的下一个元素
            for (int j = 0; j < x.Cols; ++j) {
                if (temp[j] != 0) { //压缩存储
                    result.smArray[lastInResult].row = RowA;
                    result.smArray[lastInResult].col = j;
                    result.smArray[lastInResult].value = temp[j];
                    lastInResult++;
                }
            }
        }
        delete[]temp;
    }
    result.Rows = Rows;
    result.Cols = x.Cols;
    result.Terms = lastInResult;
    delete[]rowSize, delete[]rowStart;
    return result;
}

#endif //DATA_STRUCTURE_C___SPARSEMATRIX_H
