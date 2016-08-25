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

    //sortowanie
    int c;
    char v;
    bool end;

    do {
        end = true;
        pointer = root;

        while (pointer->next) {
            if(pointer->count > pointer->next->count) {
                c = pointer->count;
                v = pointer->value;

                pointer->count = pointer->next->count;
                pointer->value = pointer->next->value;

                pointer->next->value = v;
                pointer->next->count = c;

                end = false;
            }
            pointer = pointer->next;
        }
    } while (!end);


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