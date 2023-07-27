#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *left, *right;
};

Node* newNode(int key) {
  Node* node = new Node;
  node->key = key;
  node->left = node->right = NULL;
  return node;
}

Node* rightRotate(Node* x) {
  Node* y = x->left;
  x->left = y->right;
  y->right = x;
  return y;
}

Node* leftRotate(Node* x) {
  Node* y = x->right;
  x->right = y->left;
  y->left = x;
  return y;
}

Node* splay(Node* root, int key) {
  if (root == NULL || root->key == key) return root;

  if (root->key > key) {
    if (root->left == NULL) return root;

    if (root->left->key > key) {
      root->left->left = splay(root->left->left, key);
      root = rightRotate(root);
    } else if (root->left->key < key) {
      root->left->right = splay(root->left->right, key);
      if (root->left->right != NULL) root->left = leftRotate(root->left);
    }
    if (root->left == NULL) return root;
    else return rightRotate(root);
  } else {
    if (root->right == NULL) return root;

    if (root->right->key > key) {
      root->right->left = splay(root->right->left, key);
      if (root->right->left != NULL) root->right = rightRotate(root->right);
    } else if (root->right->key < key) {
      root->right->right = splay(root->right->right, key);
      root = leftRotate(root);
    }
    if (root->right == NULL) return root;
    else return leftRotate(root);
  }
}

Node* search(Node* root, int key) {
  return splay(root, key);
}

void inorder(Node* root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
  }
}

int main() {
  Node* root = newNode(100);
  root->left = newNode(50);
  root->right = newNode(200);
  root->left->left = newNode(40);
  root->left->left->left = newNode(30);
  root->left->left->left->left = newNode(20);

  root = search(root, 20);
  cout << "Arama sonrasi a�a�: ";
  inorder(root);

  return 0;
}

