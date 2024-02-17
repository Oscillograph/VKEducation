#include <iostream>
#include <vector>

bool ChangePosition(std::vector<int>& source, int oldPos, int newPos)
{
	bool success = false;
	if ((oldPos > 0) && (oldPos < source.size()) &&
		(newPos >= 0) && (newPos < source.size()))
	{
		int temp = source[oldPos];
		for (int i = oldPos; i > newPos; i--)
		{
			source[i] = source[i - 1];
		}
		source[newPos] = temp;
		success = true;
	}
	return success;
}

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
	
	// process
	// printf("Processing.\n");
	
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (array[i] < array[j])
			{
				ChangePosition(array, i, j);
				// std::swap(array[i], array[j]);
				break;
			}
		}
	}
	
	// output
	// printf("Output:\n");
	for (int i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << ' ';
	}
	
	return 0;
}
