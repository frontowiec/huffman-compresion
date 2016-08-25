#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    char value;
    int count;
};

TreeNode *createRoot();
void addRightNodeTo(TreeNode *pointer);
void addLeftNodeTo(TreeNode *pointer);
void saveValueToLeft(TreeNode *pointer, char value);
#endif //HUFFMAN_TREE_H
