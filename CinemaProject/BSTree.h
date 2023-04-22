#pragma once

template<typename T>
class BSTree {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;

        Node(const T& val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insertNode(Node*& current, const T& value);
    Node* findNode(Node* current, const T& value) const;
    void deleteTree(Node*& current);

public:
    BSTree();
    ~BSTree();

    void insert(const T& value);
    Node* find(const T& value) const;
    bool contains(const T& value) const;
    Node* getRoot() const;
};


