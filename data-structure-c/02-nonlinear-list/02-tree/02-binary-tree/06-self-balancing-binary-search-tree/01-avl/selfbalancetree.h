//
// Created by asus on 2019/8/10.
//

#ifndef DATA_STRUCTURE_C_SELFBALANCETREE_H
#define DATA_STRUCTURE_C_SELFBALANCETREE_H

#include "stacktreenode.h"
// 单左旋
TreeNode* rotatel(TreeNode * root);

// 单右旋
TreeNode* rotater(TreeNode * root);

// 先左后右双旋
TreeNode* rotaterl(TreeNode * root);

// 先右后左双旋
TreeNode* rotatelr(TreeNode * root);

// 添加
bool insert(int value);
// 删除
bool delete(int value);
#endif //DATA_STRUCTURE_C_SELFBALANCETREE_H
