#pragma once


enum RBColors { RED, BLACK };

struct Node {
	int data;
	RBColors color;
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
	Node(int data, Node* left, Node* right, Node* parent, RBColors clr);	
};


class RBTree
{
private:

	Node* root;
	void destroy(Node*& temp);
	Node* grandparent(Node* node);  // поиск дедушки
	Node* uncle(Node* node);  // поиск дяди
	void leftRotate(Node* parent); // левый поворот
	void rightRotate(Node* parent); // правый поворот
	void InsertFixUp(Node* temp);  // регулировка структуры дерева
	void RemoveFixUp(Node* node, Node* parent);

public:

	Node* getRoot() { return root; }

	RBTree();
	~RBTree();

	// вставка узла
	void Insert(int key);

	// поиск узла
	Node* Search(int key);

	// удаление узла
	void Remove(int key);
};
