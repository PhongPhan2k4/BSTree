#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* parent;
    Node* left;
    Node* right;
    bool color; // 1 -> 1 | 0 -> 0

    Node(int value) : data(value), color(1), parent(NULL), left(NULL), right(NULL) {}
};

class RedBlackTree {
private:
    Node* root;

    void leftRotate(Node* node) {
        Node* child = node->right;
        node->right = child->left;

        if (child->left != NULL)
            child->left->parent = node;

        child->parent = node->parent;

        if (node->parent == NULL)
            root = child;
        else if (node == node->parent->left)
            node->parent->left = child;
        else
            node->parent->right = child;

        child->left = node;
        node->parent = child;
    }

    void rightRotate(Node* node) {
        Node* child = node->left;
        node->left = child->right;

        if (child->right != NULL)
            child->right->parent = node;

        child->parent = node->parent;

        if (node->parent == NULL)
            root = child;
        else if (node == node->parent->right)
            node->parent->right = child;
        else
            node->parent->left = child;

        child->right = node;
        node->parent = child;
    }

    void fixInsert(Node* node) {
        while (node != root && node->parent->color == 1) {
            if (node->parent == node->parent->parent->left) {
                Node* uncle = node->parent->parent->right;

                if (uncle != NULL && uncle->color == 1) {
                    node->parent->color = 0;
                    uncle->color = 0;
                    node->parent->parent->color = 1;
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->right) {
                        node = node->parent;
                        leftRotate(node);
                    }

                    node->parent->color = 0;
                    node->parent->parent->color = 1;
                    rightRotate(node->parent->parent);
                }
            } else {
                Node* uncle = node->parent->parent->left;

                if (uncle != NULL && uncle->color == 1) {
                    node->parent->color = 0;
                    uncle->color = 0;
                    node->parent->parent->color = 1;
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->left) {
                        node = node->parent;
                        rightRotate(node);
                    }

                    node->parent->color = 0;
                    node->parent->parent->color = 1;
                    leftRotate(node->parent->parent);
                }
            }
        }

        root->color = 0;
    }

    void insertNode(Node* node, int value) {
        if (value < node->data) {
            if (node->left != NULL)
                insertNode(node->left, value);
            else {
                node->left = new Node(value);
                node->left->parent = node;
                fixInsert(node->left);
            }
        } else if (value > node->data) {
            if (node->right != NULL)
                insertNode(node->right, value);
            else {
                node->right = new Node(value);
                node->right->parent = node;
                fixInsert(node->right);
            }
        }
    }

public:
    RedBlackTree() : root(NULL) {}

    void insert(int value) {
        if (root == NULL) {
            root = new Node(value);
            root->color = 0;
        } else {
            insertNode(root, value);
        }
    }

    Node *getRoot() {
        return root;
    }
};

int getHeight(Node* root){
	if (root == NULL) return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int main() {
    string inputs[10] = {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt", "input6.txt", "input7.txt", "input8.txt", "input9.txt", "input10.txt"};
    ofstream fout("RBTreeHeight.txt");
    for (int i = 0; i < 10; i++) {
        ifstream fin(inputs[i]);
        RedBlackTree RBTree;
        for (int j = 0; j < 1000000; j++) {
            int data;
            fin >> data;
            RBTree.insert(data);
        }
        fout << getHeight(RBTree.getRoot()) << " ";
        fin.close();
    }
    fout.close();
    return 0;
}