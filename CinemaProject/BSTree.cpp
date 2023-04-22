#include "BSTree.h"

template<typename T>
void BSTree<T>::insertNode(Node*& current, const T& value) {
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
typename BSTree<T>::Node* BSTree<T>::findNode(Node* current, const T& value) const {
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
void BSTree<T>::deleteTree(Node*& current) {
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
void BSTree<T>::insert(const T& value) {
    insertNode(root, value);
}

template<typename T>
typename BSTree<T>::Node* BSTree<T>::find(const T& value) const {
    return findNode(root, value);
}

template<typename T>
bool BSTree<T>::contains(const T& value) const {
    return (findNode(root, value) != nullptr);
}

template<typename T>
typename BSTree<T>::Node* BSTree<T>::getRoot() const {
    return root;
}
