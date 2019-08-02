//
// Created by asus on 2019/7/31.
//

#ifndef DATA_STRUCTURE_C___GENERATEDLIST_H
#define DATA_STRUCTURE_C___GENERATEDLIST_H

#include <stdlib.h>


// 广义表结点类
template<class T>
struct GenListNode {
public:
    GenListNode() : utype(0), tlink(NULL) { //构造函数
        info.ref = 0;
    };

    GenListNode(GenListNode<T> &RL) { //复制构造
        utype = RL.utype;
        tlink = RL.tlink;
        info = RL.info;
    }

private:
    int utype; //节点类型 0附加头节点 1原子节点 2子表结点
    GenListNode<T> *tlink; //指向同一层下一结点的指针
    union {
        /**
         *  utype=0 附加头结点，存放引用计数值
         */
        int ref;
        /**
         *  utype=1 原子结点，存放值
         */
        T value;
        /**
         * utype=2 子表结点，存放指向子表的指针
         */
        GenListNode<T> *hlink;
    } info;

};

// 返回值类
template<class T>
struct Items {
    int utype;
    union {
        int ref;
        T value;
        GenListNode<T> *hlink;
    } info;

    Items() : utype(0) {  //构造函数
        info.ref = 0;
    }

    Items(Items<T> &RL) { // 复制构造函数
        utype = RL.utype;
        info.ref = RL.info;
    }

};

template<class T>
class GenList {
public:
    GenList(); //构造函数
    ~GenList(); //析构函数
private:
    GenListNode<T> *first; //广义表表头指针
    GenListNode<T> *Copy(GenListNode<T> *ls); //复制一个ls指示的无共享非递归表
//    int length(GenListNode<T> *ls); //求由ls指示的广义表的长度
//    int depth(GenListNode<T> *ls);
};

template<class T>
GenList<T>::GenList() {
    first = new GenListNode<T>; //建立附加头结点
    assert(first != NULL);
}

#endif //DATA_STRUCTURE_C___GENERATEDLIST_H
