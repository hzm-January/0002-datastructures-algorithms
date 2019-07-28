//
// Created by asus on 2019/7/28.
//

#ifndef DATA_STRUCTURE_C___CUSTOMSTRING_H
#define DATA_STRUCTURE_C___CUSTOMSTRING_H

#define defualtSize 100

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class SeqString {
    friend ostream &operator<<(ostream &os, const SeqString &str);

public:
//    SeqString();
    SeqString(int capacity = defualtSize); // 带参构造
    SeqString(const char *init); // 带参构造，使用init字符串创建并初始化default size大小的数组
    SeqString(const SeqString &str); // 拷贝构造
    ~SeqString() { delete[] chararr; }; //析构
    int length() const; //获取字符串长度
    SeqString operator()(int pos, int len); //返回pos所指出的位置开始连续取len个字符组成子串返回
    int operator==(SeqString &strc) const { return strcmp(chararr, strc.chararr) == 0; } // 判断字符串是否相等
    int operator!=(SeqString &strc) const { return strcmp(chararr, strc.chararr) != 0; } // 判断字符串是否相等
    int operator!() const { return currentLen == 0; } //判断字符串是否为空
    SeqString &operator=(SeqString &str); //将str赋值给当前串
    SeqString &operator+=(SeqString &str); //将str拼接在当前串后面
    char &operator[](int i) const; //取*this的第i个字符
    int Find(SeqString &pat); //字符串匹配
private:
    char *chararr; //字符串存储数组
    int maxSize; //字符串存储数组的最大长度
    int currentLen; //当前数组的长度
};



#endif //DATA_STRUCTURE_C___CUSTOMSTRING_H
