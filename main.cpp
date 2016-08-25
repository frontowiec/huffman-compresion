#include <iostream>
#include "tree.hpp"

using namespace std;

void creteListNodes(TreeNode *&root) {
    int i;
    string inputData;
    getline(cin, inputData);
    TreeNode *pointer;

    root = NULL;

    for (i = 0; i < inputData.length(); i++) {
        pointer = root;

        while (pointer && pointer->value != inputData[i]) {
            pointer = pointer->next;
        }

        if (pointer) {
            pointer->count += 1;
        } else {
            pointer = new TreeNode;
            pointer->next = root;
            pointer->left = NULL;
            pointer->right = NULL;
            pointer->value = inputData[i];
            pointer->count = 0;

            root = pointer;
        }
    }

    int c;
    char v;

    //sortowanie
    while (pointer->next) {

        if(pointer->count > pointer->next->count) {
            c = pointer->count;
            v = pointer->value;

            pointer->count = pointer->next->count;
            pointer->value = pointer->next->value;

            pointer->next->value = v;
            pointer->next->count = c;
        }
        pointer = pointer->next;
    }

    cout << "Utworzona lista: " << endl;
    pointer = root;
    while (pointer) {
        cout << pointer->value << ":" << pointer->count << " | ";

        pointer = pointer->next;
    }

    cout << endl;
}

int main() {
    TreeNode *root;
    creteListNodes(root);
    return 0;
}