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

	while (rtNode != NULL)  // ищем местоположение узла
	{
		newParent = rtNode;
		if (temp->data > newParent->data)  // если узел больше родителя
			rtNode = rtNode->right;
		else
			rtNode = rtNode->left;
	}

	temp->parent = newParent;

	// вставляем узел
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
	InsertFixUp(temp); // регулируем узел
};


void RBTree::InsertFixUp(Node* temp)
{
	Node* parent = temp->parent;

	while (temp != root && parent->color == RED) // если узел не корень и родитель красный
	{
		Node* gparent = parent->parent;

		if (gparent->left == parent) // если родитель левое поддерево дедушки
		{
			Node* uncle = gparent->right;

			// Когда узел parent красный, если узел uncle существует и красный, изменим цвет uncle на красный 
			// и изменим цвет узла parent и узла uncle на черный
			if (uncle != NULL && uncle->color == RED) {
				parent->color = BLACK;
				uncle->color = BLACK;
				gparent->color = RED;
				temp = gparent;
				parent = temp->parent;
			}
			else
			{
				// Если узел temp является правым узлом parent, а узел parent красный, а цвет uncle черный или не 
				// существует, поворот налево, а затем направо
				if (parent->right == temp) {  // если ребенок правое поддерево 
					leftRotate(parent);
					swap(temp, parent);   // обмен узлами
				}
				//Если узел temp является левым узлом parent, а узел parent красный, а цвет uncle черный 
				//  или не существует, поворот направо
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
				if (parent->left == temp) // если ребенок левое поддерево
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
		cout << "Такого узла нет!" << endl;
		return;
	}
	else
	{
		Node* child, * parent;
		RBColors color;

		// если есть левый и правый дочерние узлы
		if (delNode->left != NULL && delNode->right != NULL) {
			Node* replace = delNode->right;

			// Найти узел-преемник (самый нижний левый узел правого поддерева текущего узла)
			while (replace->left != NULL)
			{
				replace = replace->left;
			}

			// Случай, когда удаленный узел не является корневым узлом
			if (delNode->parent != NULL) {

				if (delNode->parent->left == delNode) // если левое поддерево родителя
					delNode->parent->left = replace;
				else
					delNode->parent->right = replace;
			}
			else
				root = replace;

			// child - это правильный узел, который заменяет узел и является узлом, который требует 
			// последующей корректировки. Поскольку замена является преемником, он не
			//  может иметь левого дочернего узла
			// Аналогично, у узла-предшественника не может быть правого дочернего узла
			child = replace->right;
			parent = replace->parent;
			color = replace->color;

			// Удаленный узел является родительским узлом замещающего узла (repalce)
			if (parent = delNode)
				parent = replace;
			else
			{
				// Существование дочернего узла
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

		// Когда в удаленном узле только левый (правый) узел пуст, найдите дочерний узел удаленного узла
		if (delNode->left != NULL)
			child = delNode->left;
		else
			child = delNode->right;

		parent = delNode->parent;
		color = delNode->color;
		if (child)
			child->parent = parent;

		// Удаленный узел не является корневым узлом
		if (parent)
		{
			if (delNode == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}
		// Удаленный узел является корневым узлом
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
		if (parent->left == node) // если левое поддерево
		{
			otherNode = parent->right;

			// если удал.уз черный, сестринский красный, родитель черный
			// случай 1 из призентации
			if (otherNode->color == RED)
			{
				otherNode->color = BLACK;
				parent->color = RED;
				leftRotate(parent);
				otherNode = parent->right;
			}
			else
			{
				// если сестринский узел черный, и у узла правого поддерева либо нету, либо оно черное
				// случай 3 
				if ((!otherNode->right) || otherNode->right->color == BLACK)
				{
					otherNode->left->color = BLACK;
					otherNode->color = RED;
					rightRotate(otherNode);
					otherNode = parent->right;
				}
				// случай 4
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

