#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

class Node
{
public:
	Node(int value, Node* left, Node* right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}
	int getValue() const
	{
		return value;
	}
	Node* getLeft() const
	{
		return left;
	}
	Node* getRight() const
	{
		return right;
	}

private:
	int value;
	Node* left;
	Node* right;
};

class BinarySearchTree
{
public:
	static bool contains(const Node& root, int value)
	{
		/*
		    20
		  11   21
		10 5      25
		*/
		Node* elem = nullptr;

		if (root.getValue() == value)
		{
			return true;
		}
		else if (root.getValue() < value)
			elem = root.getLeft();
		else elem = root.getRight();

		while (elem)
		{
			if (left && elem->getValue() == value)
				return true;
			else if (elem->getValue() < value)
				elem = elem->getLeft();
			else if (elem->getValue() > value)
				elem = elem->getRight();
		}

		return false;
	}
};

#ifndef RunTests
int main()
{
	Node n1(1, NULL, NULL);
	Node n3(3, NULL, NULL);
	Node n2(2, &n1, &n3);

	std::cout << BinarySearchTree::contains(n3, 3);
}
#endif