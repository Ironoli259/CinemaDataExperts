#include "BSTree.h"
#include <iostream>
using std::cout;

template<typename T>
void BSTree<T>::InsertNode(Node*& current, const T& value) {
    if (current == nullptr) {
        current = new Node(value);
    }
    else if (value < current->value) {
        insertNode(current->left, value);
    }
    else if (value > current->value) {
        insertNode(current->right, value);
    }
}

template<typename T>
typename BSTree<T>::Node* BSTree<T>::FindNode(Node* current, const T& value) const {
    if (current == nullptr) {
        return nullptr;
    }
    else if (value < current->value) {
        return findNode(current->left, value);
    }
    else if (value > current->value) {
        return findNode(current->right, value);
    }
    else {
        return current;
    }
}

template<typename T>
void BSTree<T>::DeleteTree(Node*& current) {
    if (current != nullptr) {
        deleteTree(current->left);
        deleteTree(current->right);
        delete current;
        current = nullptr;
    }
}

template<typename T>
BSTree<T>::BSTree() : root(nullptr) {}

template<typename T>
BSTree<T>::~BSTree() {
    deleteTree(root);
}

template<typename T>
void BSTree<T>::Insert(const T& value) {
    insertNode(root, value);
}

template<typename T>
typename BSTree<T>::Node* BSTree<T>::Find(const T& value) const {
    return findNode(root, value);
}

template<typename T>
bool BSTree<T>::Contains(const T& value) const {
    return (findNode(root, value) != nullptr);
}

template<typename T>
typename BSTree<T>::Node* BSTree<T>::GetRoot() const {
    return root;
}
template<typename T>
void BSTree<T>::InorderTraversal(Node* current) const {
    if (current != nullptr) {
        InorderTraversal(current->left);
        std::cout << current->value << " ";
        InorderTraversal(current->right);
    }
}

template<typename T>
void BSTree<T>::PrintInorder() const {
    InorderTraversal(root);
}
