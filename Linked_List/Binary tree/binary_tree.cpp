#include <iostream>

using namespace std;

class BinaryTree {
private:
    int data;
    BinaryTree* left;
    BinaryTree* right;

public:
    BinaryTree(int value) : data(value), left(nullptr), right(nullptr) {}

    ~BinaryTree() {
        if (left != nullptr) {
            delete left;
        }
        if (right != nullptr) {
            delete right;
        }
    }

    void insert(int value) {
        if (value < data) {
            if (left == nullptr) {
                left = new BinaryTree(value);
            } else {
                left->insert(value);
            }
        } else {
            if (right == nullptr) {
                right = new BinaryTree(value);
            } else {
                right->insert(value);
            }
        }
    }

    bool isEmpty() {
        return (this == nullptr);
    }

    void inorderTraversal() {
        if (isEmpty()) {
            cout << "Tree is empty." << endl;
        } else {
            if (left != nullptr) {
                left->inorderTraversal();
            }
            cout << data << " ";
            if (right != nullptr) {
                right->inorderTraversal();
            }
        }
    }
};

int main() {
    BinaryTree* tree = new BinaryTree(4);

    tree->insert(2);
    tree->insert(6);
    tree->insert(1);
    tree->insert(3);
    tree->insert(5);
    tree->insert(7);

    cout << "Inorder traversal: ";
    tree->inorderTraversal();
    cout << endl;

    delete tree;

    return 0;
}
