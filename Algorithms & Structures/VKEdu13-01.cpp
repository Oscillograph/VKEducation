#include <iostream>
#include <vector>
#include <math.h>

/*
* Дано бинарное дерево поиска в виде массива. 
* Необходимо написать функцию, которая находит и возвращает максимальный элемент в дереве
*/

/*
* ЛОЛ
*/

struct BinaryTree
{
	int data = -1;
	// BinaryTree* root = nullptr;
	BinaryTree* leftChild = nullptr;
	BinaryTree* rightChild = nullptr;
	
	BinaryTree(int value = -1, BinaryTree* left = nullptr, BinaryTree* right = nullptr)
	: data(value), leftChild(left), rightChild(right) {}
	~BinaryTree()
	{
		// root = nullptr;
		delete leftChild;
		delete rightChild;
	}
	
	bool Push(int value)
	{
		bool placeFound = false;
		BinaryTree* currentNode = this;
		while(!placeFound)
		{
			// we need to place it to the left of the root
			if (value < currentNode->data)
			{
				if (!(currentNode->leftChild))
				{
					placeFound = true;
					currentNode->leftChild = new BinaryTree(value);
				} else {
					currentNode = currentNode->leftChild;
				}
			} else if (value >= currentNode->data)
			{ // we need to place it to the right of the root
				if (!(currentNode->rightChild))
				{
					placeFound = true;
					currentNode->rightChild = new BinaryTree(value);
				} else {
					currentNode = currentNode->rightChild;
				}
			}
		}
		return placeFound;
	}
	
	int Pop()
	{}
	
	int FindMin()
	{
		BinaryTree* currentNode = this;
		while (currentNode->leftChild)
		{
			currentNode = currentNode->leftChild;
		}
		return currentNode->data;
	}
	
	int FindMax()
	{
		BinaryTree* currentNode = this;
		while (currentNode->rightChild)
		{
			currentNode = currentNode->rightChild;
		}
		return currentNode->data;
	}
};

int main(int argc, char** argv) 
{
	// first line - size of an array
	printf("Input data:\n");
	
	int arraySize;
	std::cin >> arraySize;
	
	// second line - array
	std::vector<int> array;
	for (int i = 0; i < arraySize; i++)
	{
		int buf;
		std::cin >> buf;
		array.push_back(buf);
	}
	
	printf("Processing.\n");
	BinaryTree tree(array[0]);
	for (int i = 1; i < arraySize; i++)
	{
		tree.Push(array[i]);
	}
	
	// output
	printf("Output:\n");
	int result = tree.FindMax();
	std::cout << result;
	
	return 0;
}

