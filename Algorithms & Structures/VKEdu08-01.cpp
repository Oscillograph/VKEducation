#include <iostream>
#include <vector>

/*
* Дан отсортированный по возрастанию массив целых чисел и заданное число.
* Заданное число может и не находиться в массиве. 
* Тогда необходимо вернуть предполагаемый индекс, где мог бы находится элемент. 
* Другими словами, найдите правильное место для вставки элемента. 
* Если же число есть, то возвращаем его индекс.
* 
* Пример 1
* Входные данные:
* 5
* 5 7 9 11 13
* 6
* 
* Выходные данные:
* 1
* Если бы в массиве было число 6, то оно находилось бы под индексом 1 то есть правее 5 и левее 7
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
	int possibleIndex = -1;
	int realIndex = -1;
	int direction = 0;
	while (run)
	{
		if (array[start + middle] == search) // lol, found it!
		{
			realIndex = start + middle;
			found = true;
			run = false;
		} else {
			if (array[start + middle] < search) // it should be on the right
			{
				start = start + middle;
				searchWindow = end - start;
				direction = +1;
			} else {
				if (array[start + middle] > search) // it should be on the left
				{
					end = end - middle;
					searchWindow = end - start;
					direction = -1;
				}
			}
		}
		
		if (middle == 0)
		{
			possibleIndex = start + 1 * direction;
			run = false;
		}

		middle = searchWindow / 2;
	}
	
	// output
	printf("Output:\n");
	if (found)
	{
		std::cout << realIndex;
	} else {
		std::cout << possibleIndex;
	}
	
	return 0;
}

