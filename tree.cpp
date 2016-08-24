#include <iostream>
#include "tree.hpp"

TreeNode * createRoot() {
    TreeNode *rootPointer;
    rootPointer = new TreeNode;
    rootPointer->left = NULL;
    rootPointer->right = NULL;

    return rootPointer;
}

void addRightNodeTo(TreeNode *pointer) {
    pointer->right = new TreeNode;
    pointer->right->left = NULL;
    pointer->right->right = NULL;
}

void addLeftNodeTo(TreeNode *pointer) {
    pointer->left = new TreeNode;
    pointer->left->left = NULL;
    pointer->left->right = NULL;
}

//TODO: rewrite for all types
void saveValueToLeft(TreeNode *pointer, char value) {
    pointer->value = value;
}