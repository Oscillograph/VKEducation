#include <iostream>
#include <vector>

/*
* Есть список товаров в магазине отсортированный по возрастанию, 
* необходимо понять, есть ли в этом списке товар с заданной ценой. 
* В случае если цена найдена возвращайте true
*/

int main(int argc, char** argv) 
{
	int inputNumber = 0;
	
	// first line - total array size
	printf("Array size:\n");
	std::cin >> inputNumber;
	
	std::vector<int> array;
	array.reserve(inputNumber);
	array.resize(inputNumber);
	
	// second line - the array content
	printf("Write an array:\n");
	for (int i = 0; i < array.size(); i++)
	{
		std::cin >> array[i];
	}
	printf("Write the search:\n");
	int search;
	std::cin >> search;
	
	// process
	printf("Processing.\n");
	int start = 0;
	int end = array.size()-1;
	int searchWindow = end - start;
	int middle = searchWindow / 2;;
	bool run = true;
	bool found = false;
	while (run)
	{
		if (array[start + middle] == search) // lol, found it!
		{
			found = true;
			run = false;
		} else {
			if (array[start + middle] < search) // it should be on the right
			{
				start = start + middle;
				searchWindow = end - start;
			} else {
				if (array[start + middle] > search) // it should be on the left
				{
					end = end - middle;
					searchWindow = end - start;
				}
			}
		}
		
		if (middle == 0)
			run = false;
		middle = searchWindow / 2;
	}
	
	// output
	printf("Output:\n");
	if (found)
	{
		std::cout << "true";
	} else {
		std::cout << "false";
	}
	
	return 0;
}

