/*
* В школе прошел экзамен по математике. Несколько человек списали решения и были замечены. Этим школьникам поставил 0 баллов.
* Задача: есть массив с оценками, среди которых есть 0. Необходимо все оценки, равные нулю перенести в конец массива, чтобы все такие школьники оказались в конце списка.
* Примечание: первая строка во вводе - число элементов в массиве


* Пример 1
* Входные данные:
* 9
* 0 33 57 88 60 0 0 80 99
* Выходные данные:
* 33 57 88 60 80 99 0 0 0

* Пример 2
* Входные данные:
* 8
* 0 0 88 0 99 0 100 0 
* Выходные данные:
* 88 99 100 0 0 0 0 0
*/

#include <iostream>
#include <vector>
struct Node
{
	Node() = default;
	Node(int value) : data(value), prev(nullptr), next(nullptr) {}
	Node(Node* _prev, Node* _next) : prev(_prev), next(_next) 
	{
		if (prev != nullptr)
			prev->next = this;
		if (next != nullptr)
			next->prev = this;
	}
	
	~Node()
	{
		next = nullptr;
		prev = nullptr;
	}
	
	int data = 0;
	Node* prev = nullptr;
	Node* next = nullptr;
};

struct NodeList
{
public:
	NodeList()
	{
		head = new Node();
		tail = head;
		size = 1;
	}
	
	~NodeList()
	{
		while (size > 0)
		{
			if (tail != head)
			{
				currentNode = tail->prev;
				delete tail;
				tail = currentNode;
				size--;
			} else {
				delete head;
				head = nullptr;
				tail = nullptr;
				size = 0;
			}
		}
	}
	
	int size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
	
	Node* operator[](int index)
	{
		if (index == 0) // aim at head
			return head;
		
		if (index > 0)
		{
			if (index == (size - 1)) // aim at tail
				return tail;
			
			// index is in between, start from head
			int currentNodeIndex = 0;
			currentNode = head;
			bool makeNewNode = false;
			// int newNodesCount = 0;
			while (currentNodeIndex < index)
			{
				currentNodeIndex++;
				if (currentNode->next != nullptr) // we're not in the tail yet, it's all right
				{
					currentNode = currentNode->next;
				} else { // we need to get past the tail!
					makeNewNode = true;
					// newNodesCount++;
				}
			} // by the end of the cycle currentNodeIndex should be equal to index
			
			if ((currentNode == tail) && (makeNewNode)) // do we need to make a new Node?
			{
				// printf("creating a new node with index %i", index);
				currentNode = new Node(tail, nullptr);
				size++;
			}
		} else {
			currentNode = nullptr;
		}
		
		return currentNode;
	}
	
	bool Append(Node* prev, Node* node)
	{
		bool success = false;
		
		if (node != nullptr)
		{
			if (prev == nullptr) // append before head
			{
				node->next = head;
				node->prev = nullptr;
				
				head->prev = node;
				head = node;
			} else {
				if (prev == tail)
				{
					node->next = nullptr;
					node->prev = tail;
					
					tail->next = node;
					tail = node;
				} else {
					node->next = prev->next;
					node->prev = prev;
					
					node->next->prev = node;
					node->prev->next = node;
				}
			}
			size++;
			success = true;
		}
		
		return success;
	}
	
private:
	Node* currentNode = nullptr;
};

int main(int argc, char** argv) 
{
	int inputNumber = 0;
	
	// first line - total array size
	// printf("Array size:\n");
	std::cin >> inputNumber;
	
	std::vector<int> array;
	array.reserve(inputNumber);
	array.resize(inputNumber);
	
	// second line - the array content
	// printf("Write an array:\n");
	for (int i = 0; i < array.size(); i++)
	{
		std::cin >> array[i];
	}
	
	// prepare a list
	NodeList list;
	
	Node* listNode = nullptr; // pointer at the beginning
	for (int i = 0; i < array.size(); i++)
	{
		// printf("%i: array value - %i ... ", i, array[i]);
		
		if (array[i] != 0)
		{
			if (listNode != nullptr)
			{
				list.Append(listNode, new Node(array[i]));
				listNode = listNode->next;
			} else {
				list.head->data = array[i];
				listNode = list.head;
			}
			
			// printf("stored.\n");
		} else {
			// printf("a new node with value %i", array[i]);
			list.Append(list.tail, new Node(array[i]));
			// printf("created and saved.\n");
		}
	}
	
	// printf("The list is constructed.\n");
	// output
	for (int i = 0; i < array.size(); i++)
	{
		std::cout << list[i]->data << ' ';
	}
	// printf("\nEnd?\n");
	
	return 0;
}
