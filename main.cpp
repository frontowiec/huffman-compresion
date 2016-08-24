#include <iostream>

using namespace std;

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    char value;
};

void createTree(TreeNode *&root) {
    int n, charCounter, bitsCounter;
    string bits;
    char signature;
    TreeNode *pointer;

    root = new TreeNode;
    root->left = NULL;
    root->right = NULL;

    cout << "Podaj ilość znaków: " << endl;
    cin >> n;

    cout << "Podaj " << n << " par - znak ciąg bitów do zakodowania" << endl;

    for (charCounter = 0; charCounter < n; charCounter++) {
        cin >> signature >> bits;
        pointer = root;

        for (bitsCounter = 0; bitsCounter < (int) bits.length(); bitsCounter++) {
            if (bits[bitsCounter] == '1') {
                if (!pointer->right) {
                    pointer->right = new TreeNode;
                    pointer->right->left = NULL;
                    pointer->right->right = NULL;
                }
                pointer = pointer->right;
            }

            if (bits[bitsCounter] == '0') {
                if (!pointer->left) {
                    pointer->left = new TreeNode;
                    pointer->left->left = NULL;
                    pointer->left->right = NULL;
                }
                pointer = pointer->left;
            }
        }
        pointer->value = signature;
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
    TreeNode *root;

    createTree(root);
    decodeTree(root);

    return 0;
}