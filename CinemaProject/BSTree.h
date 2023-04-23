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

    void InsertNode(Node*& current, const T& value);
    Node* FindNode(Node* current, const T& value) const;
    void DeleteTree(Node*& current);

public:
    BSTree();
    ~BSTree();

    void Insert(const T& value);
    Node* Find(const T& value) const;
    bool Contains(const T& value) const;
    Node* GetRoot() const;
    void InorderTraversal(Node* current) const;
    void PrintInorder() const;
};


