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
	Node* grandparent(Node* node);  // ����� �������
	Node* uncle(Node* node);  // ����� ����
	void leftRotate(Node* parent); // ����� �������
	void rightRotate(Node* parent); // ������ �������
	void InsertFixUp(Node* temp);  // ����������� ��������� ������
	void RemoveFixUp(Node* node, Node* parent);

public:

	Node* getRoot() { return root; }

	RBTree();
	~RBTree();

	// ������� ����
	void Insert(int key);

	// ����� ����
	Node* Search(int key);

	// �������� ����
	void Remove(int key);
};
