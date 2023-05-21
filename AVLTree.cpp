
#include <bits/stdc++.h> 
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};
 
int getHeight(Node* root) {
    if (root == NULL)
    return 0;
    return root->height;
}
 
Node* rightRotate(Node* root){
    Node* x = root->left;
    
    root->left = x->right;
    x->right = root;
    
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    
    return x;
}
 
Node* leftRotate(Node* root) {
    Node* y = root->right;

    root->right = y->left;
    y->left = root;
    
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}
// Insertion - AVL Tree
Node* Insert(Node* root, int value) {
    // Insert
    if (root == NULL)
        return new Node{ value, NULL, NULL, 1 }; // Trả về Node có height = 1
    if (value > root->data)
        root->right = Insert(root->right, value);
    else if (value < root->data)
        root->left = Insert(root->left, value);
    else 
        return root; // Neu bang thi khong them
    
    // Set height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    
    // Rotate
    int valBalance = getHeight(root->left) - getHeight(root->right);
    
    // Kiểm tra 4 TH xảy ra:
    // Left left
    if (valBalance > 1 && value < root->left->data)
        return rightRotate(root);
    
    // Right Right
    if (valBalance < -1 && value > root->right->data)
        return leftRotate(root);
    
    // Left Right
    if (valBalance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Left
    if (valBalance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}
 
int main() {
    string inputs[10] = {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt", "input6.txt", "input7.txt", "input8.txt", "input9.txt", "input10.txt"};
    ofstream fout("AVLTreeHeight.txt");
    for (int i = 0; i < 10; i++) {
        ifstream fin(inputs[i]);
        Node* tree = NULL;
        for (int j = 0; j < 1000000; j++) {
            int data;
            fin >> data;
            tree = Insert(tree, data);
        }
        fout << tree->height << " ";
        fin.close();
    }
    fout.close();
    return 0;
}