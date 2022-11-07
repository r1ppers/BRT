#include <iostream>
#include <utility> 
#include "RBTree.h"

using namespace std;


Node::Node(int data, Node* left, Node* right, Node* parent, RBColors clr)
{
	this->data = data;
	this->color = clr;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}
	
	
RBTree::RBTree()
{
	root = nullptr;
};


RBTree::~RBTree()
{
	destroy(root);
};


void RBTree::Insert(int key)
{
	Node* temp = new Node(key, NULL, NULL, NULL, RED);
	Node* newParent = NULL;
	Node* rtNode = root;

	while (rtNode != NULL)  // ���� �������������� ����
	{
		newParent = rtNode;
		if (temp->data > newParent->data)  // ���� ���� ������ ��������
			rtNode = rtNode->right;
		else
			rtNode = rtNode->left;
	}

	temp->parent = newParent;

	// ��������� ����
	if (newParent != NULL)
	{
		if (temp->data > newParent->data)
			newParent->right = temp;
		else
			newParent->left = temp;
	}

	else
		root = temp;

	temp->color = RED;
	InsertFixUp(temp); // ���������� ����
};


void RBTree::InsertFixUp(Node* temp)
{
	Node* parent = temp->parent;

	while (temp != root && parent->color == RED) // ���� ���� �� ������ � �������� �������
	{
		Node* gparent = parent->parent;

		if (gparent->left == parent) // ���� �������� ����� ��������� �������
		{
			Node* uncle = gparent->right;

			// ����� ���� parent �������, ���� ���� uncle ���������� � �������, ������� ���� uncle �� ������� 
			// � ������� ���� ���� parent � ���� uncle �� ������
			if (uncle != NULL && uncle->color == RED) {
				parent->color = BLACK;
				uncle->color = BLACK;
				gparent->color = RED;
				temp = gparent;
				parent = temp->parent;
			}
			else
			{
				// ���� ���� temp �������� ������ ����� parent, � ���� parent �������, � ���� uncle ������ ��� �� 
				// ����������, ������� ������, � ����� �������
				if (parent->right == temp) {  // ���� ������� ������ ��������� 
					leftRotate(parent);
					swap(temp, parent);   // ����� ������
				}
				//���� ���� temp �������� ����� ����� parent, � ���� parent �������, � ���� uncle ������ 
				//  ��� �� ����������, ������� �������
				rightRotate(gparent);
				gparent->color = RED;
				parent->color = BLACK;
				break;
			}
		}

		else
		{
			Node* uncle = gparent->left;

			if (uncle != NULL && uncle->color == RED)
			{
				gparent->color = RED;
				uncle->color = BLACK;
				parent->color = BLACK;
				temp = gparent;
				parent = temp->parent;
			}
			else
			{
				if (parent->left == temp) // ���� ������� ����� ���������
				{
					rightRotate(parent);
					swap(parent, temp);
				}

				leftRotate(gparent);
				parent->color = BLACK;
				gparent->color = RED;
				break;
			}
		}
	}

	root->color = BLACK;
}


Node* RBTree::Search(int key)
{
	Node* temp = root;

	while (temp && temp->data != key) {
		if (key > temp->data)
			temp = temp->right;
		else
			temp = temp->left;
	}

	return temp;
};


void RBTree::Remove(int key)
{
	Node* delNode = Search(key);

	if (!delNode) {
		cout << "������ ���� ���!" << endl;
		return;
	}
	else
	{
		Node* child, * parent;
		RBColors color;

		// ���� ���� ����� � ������ �������� ����
		if (delNode->left != NULL && delNode->right != NULL) {
			Node* replace = delNode->right;

			// ����� ����-�������� (����� ������ ����� ���� ������� ��������� �������� ����)
			while (replace->left != NULL)
			{
				replace = replace->left;
			}

			// ������, ����� ��������� ���� �� �������� �������� �����
			if (delNode->parent != NULL) {

				if (delNode->parent->left == delNode) // ���� ����� ��������� ��������
					delNode->parent->left = replace;
				else
					delNode->parent->right = replace;
			}
			else
				root = replace;

			// child - ��� ���������� ����, ������� �������� ���� � �������� �����, ������� ������� 
			// ����������� �������������. ��������� ������ �������� ����������, �� ��
			//  ����� ����� ������ ��������� ����
			// ����������, � ����-��������������� �� ����� ���� ������� ��������� ����
			child = replace->right;
			parent = replace->parent;
			color = replace->color;

			// ��������� ���� �������� ������������ ����� ����������� ���� (repalce)
			if (parent = delNode)
				parent = replace;
			else
			{
				// ������������� ��������� ����
				if (child != NULL)
					child->parent = parent;
				parent->left = child;

				replace->right = delNode->right;
				delNode->right->parent = replace;
			}

			replace->parent = delNode->parent;
			replace->color = delNode->color;
			replace->left = delNode->left;
			delNode->left->parent = replace;
			if (color == BLACK)
				RemoveFixUp(child, parent);

			delete delNode;
			return;
		}

		// ����� � ��������� ���� ������ ����� (������) ���� ����, ������� �������� ���� ���������� ����
		if (delNode->left != NULL)
			child = delNode->left;
		else
			child = delNode->right;

		parent = delNode->parent;
		color = delNode->color;
		if (child)
			child->parent = parent;

		// ��������� ���� �� �������� �������� �����
		if (parent)
		{
			if (delNode == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}
		// ��������� ���� �������� �������� �����
		else
			root = child;

		if (color == BLACK)
		{
			RemoveFixUp(child, parent);
		}
		delete delNode;
	}
};


void RBTree::RemoveFixUp(Node* node, Node* parent)
{
	Node* otherNode;

	while (node == NULL || node->color == BLACK && node != root)
	{
		if (parent->left == node) // ���� ����� ���������
		{
			otherNode = parent->right;

			// ���� ����.�� ������, ����������� �������, �������� ������
			// ������ 1 �� �����������
			if (otherNode->color == RED)
			{
				otherNode->color = BLACK;
				parent->color = RED;
				leftRotate(parent);
				otherNode = parent->right;
			}
			else
			{
				// ���� ����������� ���� ������, � � ���� ������� ��������� ���� ����, ���� ��� ������
				// ������ 3 
				if ((!otherNode->right) || otherNode->right->color == BLACK)
				{
					otherNode->left->color = BLACK;
					otherNode->color = RED;
					rightRotate(otherNode);
					otherNode = parent->right;
				}
				// ������ 4
				otherNode->color = parent->color;
				parent->color = BLACK;
				otherNode->right->color = BLACK;
				leftRotate(parent);
				node = root;
				break;
			}
		}

		else
		{
			otherNode = parent->left;

			if (otherNode->color == RED)
			{
				otherNode->color = BLACK;
				parent->color = RED;
				rightRotate(parent);
				otherNode = parent->left;
			}

			if ((!otherNode->left || otherNode->left->color == BLACK) && (!otherNode->right ||
				otherNode->right->color == BLACK))
			{
				otherNode->color = RED;
				node = parent;
				parent = node->parent;
			}

			else
			{
				if (!(otherNode->left) || otherNode->left->color == BLACK)
				{
					otherNode->right->color = BLACK;
					otherNode->color = RED;
					leftRotate(otherNode);
					otherNode = parent->left;
				}
				otherNode->color = parent->color;
				parent->color = BLACK;
				otherNode->left->color = BLACK;
				rightRotate(parent);
				node = root;
				break;
			}
		}

	}

	if (node)
		node->color = BLACK;
};


void RBTree::destroy(Node*& temp)
{
	if (temp == nullptr)
		return;

	destroy(temp->left);
	destroy(temp->right);
	delete temp;
	temp = nullptr;
};


Node* RBTree::grandparent(Node* node)
{
	if ((node != NULL) && (node->parent != NULL))
		return node->parent->parent;
	else
		return NULL;
};


Node* RBTree::uncle(Node* node)
{
	Node* g = grandparent(node);
	if (g == NULL)
		return NULL; // No grandparent means no uncle
	if (node->parent == g->left)
		return g->right;
	else
		return g->left;
}


void RBTree::leftRotate(Node* parent)
{
	Node* temp = parent->right;
	parent->right = temp->left;

	if (temp->left != NULL)
		temp->left->parent = parent;

	temp->parent = parent->parent;

	if (parent->parent == NULL)
		root = temp;
	else {
		if (parent == parent->parent->left)
			parent->left->left = temp;
		else
			parent->parent->right = temp;
	}

	temp->left = parent;
	parent->parent = temp;
}


void RBTree::rightRotate(Node* parent)
{
	Node* temp = parent->left;
	parent->left = temp->right;

	if (temp->right != NULL)
		temp->right->parent = parent;

	temp->parent = parent->parent;

	if (parent->parent == NULL)
		root = temp;
	else {
		if (parent == parent->parent->right)
			parent->parent->right = temp;
		else
			parent->parent->left = temp;
	}

	temp->right = parent;
	parent->parent = temp;
}

