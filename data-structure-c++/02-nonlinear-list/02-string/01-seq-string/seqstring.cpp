//
// Created by asus on 2019/7/28.
//

#include "seqstring.h"

SeqString::SeqString(int capacity) {
    maxSize = capacity;
    chararr = new char[maxSize + 1];
    if (chararr == NULL) {
        cerr << "allocation error\n" << endl;
        exit(1);
    }
    currentLen = 0;
    chararr[0] = '\0';
}

SeqString::SeqString(const char *init) {
    size_t len = strlen(init);
    maxSize = (len > defualtSize) ? len : defualtSize;
    chararr = new char[maxSize + 1];
    if (chararr == NULL) {
        cerr << "allocation error\n" << endl;
        exit(1);
    }
    memset(chararr, 0, sizeof(char) * maxSize);
    currentLen = len;
    strcpy(chararr, init);
}

SeqString::SeqString(const SeqString &str) {
    maxSize = str.maxSize;
    chararr = new char[maxSize + 1];
    if (chararr == NULL) {
        cerr << "allocation error\n" << endl;
        exit(1);
    }
    currentLen = str.currentLen;
    strcpy(chararr, str.chararr);
}

ostream &operator<<(ostream &os, const SeqString &str) {
    if (str.currentLen > 0) {
        for (int i = 0; i < str.currentLen; ++i) {
            os << str.chararr[i];
        }
    }
    return os;
}

int SeqString::length() const {
    return currentLen;
}

//将str赋值给当前串
SeqString &SeqString::operator=(SeqString &str) {
    if (*this != str) {
        delete[]chararr; //clear
        maxSize = str.maxSize;
        chararr = new char[maxSize];
        if (chararr == NULL) {
            cerr << "allocation error\n" << endl;
            exit(1);
        }
        currentLen = str.currentLen;
        strcpy(chararr, str.chararr);
    }
    return *this;
}

//将str拼接在当前串后面
SeqString &SeqString::operator+=(SeqString &str) {
    char *temp = chararr;
    int n = str.currentLen + currentLen + 1;
    int m = (maxSize >= n) ? maxSize : n;
    chararr = new char[m];
    currentLen = n;
    maxSize = m;
    strcpy(chararr, temp);
    strcat(chararr, str.chararr);
    delete[] temp;
    return *this;
}

SeqString SeqString::operator()(int pos, int len) {
    SeqString temp;
    if (pos < 0 || len < 0 || pos + len - 1 >= maxSize) {
        temp.currentLen = 0;
        temp.chararr[0] = '\0';
    } else {
        if (pos + len - 1 >= currentLen - 1) {
            len = currentLen - pos;
        }
        temp.currentLen = len;
        for (int i = 0, j = pos; i < len; ++i, ++j) {
            temp.chararr[i] = chararr[j];
        }
        temp.chararr[len] = '\0';
    }
    return temp;
}
//取*this的第i个字符
char &SeqString::operator[](int i) const{
    if (i < 0 || i >= currentLen) {
        cerr << "index out of bounds" << endl;
    }
    return chararr[i];
}
//int Find(SeqString &pat); //字符串匹配