#ifndef AVLTREE_H
#define AVLTREE_H

#include <functional>
#include <algorithm>

template <typename T>
class AVLTree {
private:
	struct Node {
		T* value;
		Node* left;
		Node* right;
		int height;

		Node(const T* value)
			: value(const_cast<T*>(value)), left(nullptr), right(nullptr), height(1) {}
	};

	Node* root;
	std::function<bool(const T*, const T*)> comparator;

	int getHeight(Node* node) {
		return node ? node->height : 0;
	}

	int getBalance(Node* node) {
		return node ? getHeight(node->left) - getHeight(node->right) : 0;
	}

	void updateHeight(Node* node) {
		node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
	}

	Node* rotateRight(Node* node) {
		Node* leftChild = node->left;
		Node* leftRightChild = leftChild->right;

		leftChild->right = node;
		node->left = leftRightChild;

		updateHeight(node);
		updateHeight(leftChild);

		return leftChild;
	}

	Node* rotateLeft(Node* node) {
		Node* rightChild = node->right;
		Node* rightLeftChild = rightChild->left;

		rightChild->left = node;
		node->right = rightLeftChild;

		updateHeight(node);
		updateHeight(rightChild);

		return rightChild;
	}

	Node* insert(Node* node, const T* value) {
		if (!node) {
			return new Node(value);
		}

		if (comparator(value, node->value)) {
			node->left = insert(node->left, value);
		}
		else {
			node->right = insert(node->right, value);
		}

		updateHeight(node);

		int balance = getBalance(node);

		// Left-Left case
		if (balance > 1 && comparator(value, node->left->value)) {
			return rotateRight(node);
		}

		// Right-Right case
		if (balance < -1 && !comparator(value, node->right->value)) {
			return rotateLeft(node);
		}

		// Left-Right case
		if (balance > 1 && !comparator(value, node->left->value)) {
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}

		// Right-Left case
		if (balance < -1 && comparator(value, node->right->value)) {
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}

		return node;
	}

	Node* minValueNode(Node* node) {
		Node* current = node;
		while (current->left) {
			current = current->left;
		}
		return current;
	}

	Node* balance(Node* node) {
		updateHeight(node);
		int bf = balanceFactor(node);
		if (bf > 1) {
			if (balanceFactor(node->left) < 0) {
				node->left = rotateLeft(node->left);
			}
			return rotateRight(node);
		}
		else if (bf < -1) {
			if (balanceFactor(node->right) > 0) {
				node->right = rotateRight(node->right);
			}
			return rotateLeft(node);
		}
		return node;
	}

	Node* remove(Node* node, const T* value) {
		if (!node) {
			return node;
		}

		if (comparator(value, node->value)) {
			node->left = remove(node->left, value);
		}
		else if (comparator(node->value, value)) {
			node->right = remove(node->right, value);
		}
		else {
			if (!node->left || !node->right) {
				Node* temp = node->left ? node->left : node->right;

				if (!temp) {
					temp = node;
					node = nullptr;
				}
				else {
					*node = *temp;
				}

				delete temp;
			}
			else {
				Node* temp = minValueNode(node->right);
				node->value = temp->value;
				node->right = remove(node->right, temp->value);
			}
		}

		if (!node) {
			return node;
		}

		updateHeight(node);
		int balance = getBalance(node);

		// Left-Left case
		if (balance > 1 && getBalance(node->left) >= 0) {
			return rotateRight(node);
		}

		// Right-Right case
		if (balance < -1 && getBalance(node->right) <= 0) {
			return rotateLeft(node);
		}

		// Left-Right case
		if (balance > 1 && getBalance(node->left) < 0) {
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}

		// Right-Left case
		if (balance < -1 && getBalance(node->right) > 0) {
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}

		return node;
	}

	T* search(Node* node, const T* value) const {
		if (!node) {
			return nullptr;
		}

		if (comparator(value, node->value)) {
			return search(node->left, value);
		}
		else if (comparator(node->value, value)) {
			return search(node->right, value);
		}
		else {
			return (node->value);
		}
	}

	void traverseInOrder(Node* node, const std::function<bool(const T*)> visitor) const {
		if (!node) {
			return;
		}

		traverseInOrder(node->left, visitor);
		if (!visitor(node->value)) {
			return;
		}
		traverseInOrder(node->right, visitor);
	}

	void clear() {
		clearHelper(root);
		root = nullptr;
	}

	void clearHelper(Node* node) {
		if (!node) {
			return;
		}

		clearHelper(node->left);
		clearHelper(node->right);
		delete node;
	}

public:
	AVLTree(std::function<bool(const T*, const T*)> comparator) : root(nullptr), comparator(comparator) {}

	~AVLTree() { clear(); }

	void insert(const T* value) {
		root = insert(root, value);
	}

	void remove(const T* value) {
		root = remove(root, value);
	}

	T* search(const T* value) const {
		return search(root, value);
	}

	bool isEmpty() const {
		return root == nullptr;
	}

	void traverseInOrdermain(std::function<bool(const T*)> visit) const {
		traverseInOrder(root, visit);
	}
};
#endif // AVLTREE_H