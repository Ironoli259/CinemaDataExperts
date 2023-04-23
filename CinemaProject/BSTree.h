#pragma once

template<typename T>
class BSTree {
public:
    struct Node {
        T value;
        Node* left;
        Node* right;

        Node(const T& val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void InsertNode(Node*& current, const T& value) {
        if (current == nullptr) {
            current = new Node(value);
        }
        else if (value < current->value) {
            InsertNode(current->left, value);
        }
        else if (!(value < current->value)) {
            InsertNode(current->right, value);
        }
    }

    Node* FindNode(Node* current, const T& value) const {
        if (current == nullptr) {
            return nullptr;
        }
        else if (value < current->value) {
            return FindNode(current->left, value);
        }
        else if ((!value < current->value)) {
            return FindNode(current->right, value);
        }
        else {
            return current;
        }
    }
    Node* FindNode(Node* current, const int index) const {
        if (current == nullptr) {
            return nullptr;
        }
        else if (index < current->value.number) {
            return FindNode(current->left, index);
        }
        else if (!(index < current->value.number)) {
            return FindNode(current->right, index);
        }
        else {
            return current;
        }
    }

    void DeleteTree(Node*& current) {
        if (current != nullptr) {
            DeleteTree(current->left);
            DeleteTree(current->right);
            delete current;
            current = nullptr;
        }
    }

public:
    BSTree() : root(nullptr) {}
    ~BSTree() { DeleteTree(root); }

    void Insert(const T& value) {
        InsertNode(root, value);
    }

    Node* Find(const T& value) const {
        return FindNode(root, value);
    }
    Node* Find(int value) const {
        return FindNode(root, value);
    }
    
    bool Contains(const T& value) const {
        return (FindNode(root, value) != nullptr);
    }

    Node* GetRoot() const {
        return root;
    }

    void InorderTraversal(Node* current) const {
        if (current != nullptr) {
            InorderTraversal(current->left);
            std::cout << current->value << " ";
            InorderTraversal(current->right);
        }
    }

    void PrintInorder() const {
        InorderTraversal(root);
    }
};