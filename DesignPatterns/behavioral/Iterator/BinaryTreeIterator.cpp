// BinaryTreeIterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T> class BinaryTree;

template <typename T> class Node
{
public:
	T value = T();

	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
	Node<T>* parent = nullptr;

	BinaryTree<T>* tree = nullptr; 	// Pointer to the tree with identical type

	// constructor with filling value
	explicit Node(const T& value):value(value)
	{
	}
	
	// constructor with filling l,r,p
	explicit Node(const T& value, Node<T>* const left,  Node<T>* const right) :
		value(value), left(left), right(right)
	{
		this->left->parent = this->right->parent = this;
	}

	~Node()
	{
		if (left)  delete left;
		if (right) delete right;
	}

	// set tree recursively
	void setTree(BinaryTree<T>* t)
	{
		tree = t;
		if (left)  left->setTree(t);
		if (right) right->setTree(t);
	}
};

template <typename T> class BinaryTree
{
public:
	Node<T>* root = nullptr;

	// To support iterator
	template <typename U> class BTreeIterator
	{
	public:
		Node<U>* current;
		BTreeIterator(Node<U>* const current) : current(current)
		{
		}

		bool operator != (const BTreeIterator<U>& other)
		{
			return current != other.current;
		}

		Node<U>& operator *()
		{
			return *current;
		}

		BTreeIterator<U>& operator ++()
		{
			if (current->right)
			{
				current = current->right;
				while (current->left)
				{
					current = current->left;
				}
			}
			else
			{
				Node <T>* p = current->parent;
				while (p && current == p->right)
				{
					current = p;
					p = p->parent;
				}

				current = p;
			}
			return *this;
		}
	};

	typedef BTreeIterator<T> _iterator;

	explicit BinaryTree(Node<T>* const root) :root(root)
	{
		root->setTree(this);
	}

	~BinaryTree()
	{
		if (root) delete root;
	}

	_iterator begin()
	{
		Node <T>* n = root;

		if (n)
		{
			while (n->left)
			{
				n = n->left;
			}
		}
		return n;
	}

	_iterator end()
	{
		return _iterator(nullptr);
	}
};

int main()
{
	BinaryTree<string> family_tree {
		new Node <string> {"child",
			new Node <string> {"Mom",
				new Node <string> {"Mom's Mom"},
				new Node <string> {"Mom's Father"}
			},
		new Node<string> {"Father"}
		}
	};

	for (auto it = family_tree.begin(); it != family_tree.end(); ++it)
	{
		cout << (*it).value << endl;
	}

	return 0;
}