#include <iostream>
#include "tree.hpp"

using namespace std;

void createTree(TreeNode *root) {
    int n, charCounter, bitsCounter;
    string bits;
    char signature;
    TreeNode *pointer; //TODO: pojecie wskaznika wyabstrahować do pojęcia węzła ??

    cout << "Podaj ilość znaków: " << endl;
    cin >> n;

    cout << "Podaj " << n << " par - znak ciąg bitów do zakodowania" << endl;

    for (charCounter = 0; charCounter < n; charCounter++) {
        cin >> signature >> bits;
        pointer = root;

        for (bitsCounter = 0; bitsCounter < (int) bits.length(); bitsCounter++) {
            if (bits[bitsCounter] == '1') {
                if (!pointer->right) {
                    addRightNodeTo(pointer);
                }
                pointer = pointer->right;
            }

            if (bits[bitsCounter] == '0') {
                if (!pointer->left) {
                    addLeftNodeTo(pointer);
                }
                pointer = pointer->left;
            }
        }
        saveValueToLeft(pointer, signature);
    }
}

void decodeTree(TreeNode *root) {
    string bits;
    TreeNode *pointer;
    int bitsCounter;

    cout << "Podaj ciąg bitów do odkodowania: " << endl;
    cin >> bits;

    pointer = root;

    for (bitsCounter = 0; bitsCounter < (int) bits.length(); bitsCounter++) {
        if (bits[bitsCounter] == '0') {
            pointer = pointer->left;
        }

        if (bits[bitsCounter] == '1') {
            pointer = pointer->right;
        }

        if (!pointer->left) {
            cout << pointer->value;
            pointer = root;
        }
    }

}

int main() {
    TreeNode *root = createRoot();

    createTree(root);
    decodeTree(root);

    return 0;
}