# 树的存储表示
## 子女链表表示法
> 算法思想：每个结点都有一个链表保存子女结点，每一个结点作为其子女结点链表的头指针保存到数组中
+ 头结点向量数组：保存树中每个结点
+ 头结点向量数组的元素：datum域保存结点数据，link域保存后继结点的指针
+ 子女结点链表：保存头指针结点的所有子女节点结点
+ 子女结点：datum域保存该子女节点在向量数组中的索引，link域保存后继结点（同层同父的兄弟节点）的指针