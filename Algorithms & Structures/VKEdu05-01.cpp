#include <iostream>
#include <vector>
#include <string>

// Рубежный контроль
// Дан не отсортированный массив целых чисел. 
// Необходимо перенести в начало массива все _чётные_ числа. 
// При этом последовательность _чётных_ чисел должна быть сохранена. 
// То есть если 8 стояла после 6, то после переноса в начало, она по-прежнему должна стоять после 6.

bool IsEven(int number)
{
	return !(number % 2);
}

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
	std::string buf;
	for (int i = 0; i < inputNumber; i++)
	{
		std::cin >> array[i];
	}
	
	// process
	printf("Processing.\n");
	int temp;
	auto arrayStartIterator = array.begin();
	if (IsEven(*arrayStartIterator))
	{
		arrayStartIterator++;
	}
	
	// [2 1 7 3 4 0 5]
	// arrayStartIterator -> 2
	// it -> 2
	// swap, then both ++;
	// [2 1 7 3 4 0 5]
	// arrayStartIterator -> 1
	// it -> 1 - not even, it++
	// arrayStartIterator -> 1
	// it -> 7 - not even, it++
	// arrayStartIterator -> 1
	// it -> 3 - not even, it++
	// arrayStartIterator -> 1
	// it -> 4 - even!
	// swap, then both ++;
	// [2 4 7 3 1 0 5]
	// arrayStartIterator -> 7
	// it -> 0 - even! go the same
	// [2 4 0 3 1 7 5]
	// So that's the solution, I suppose.
	
	for (auto it = arrayStartIterator; it != array.end(); it++)
	{
		if (IsEven(*it))
		{
			// swap integers
			temp = *it;
			*it = *arrayStartIterator;
			*arrayStartIterator = temp;
			
			arrayStartIterator++;
		}
	}
	
	// output
	printf("Output:\n");
	for (int i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << ' ';
	}
	
	return 0;
}
