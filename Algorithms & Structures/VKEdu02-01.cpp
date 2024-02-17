#include <iostream>
/*
* На вход подается не отсортированный массив целых чисел и некоторое целое число «element».
* Необходимо написать функцию, которая вернет количество элементов, которые не равны данному числу «element».
* Возвращаемое значение после работы функции обозначает количество чисел не равные «element».

* Пример 1
* Входные данные:
* 9
* 7 8 1 3 11 3 9 4 3
* 3

* Выходные данные:
* 6
*/

#include <vector>
int main(int argc, char** argv) 
{
	int inputNumber = 0;
	int outputNumber = 0;
	
	// first line - total array size
	std::cin >> inputNumber;
	std::vector<int> array;
	array.reserve(inputNumber);
	array.resize(inputNumber);
	
	// second line - the array content
	for (int i = 0; i < array.size(); i++)
	{
		std::cin >> array[i];
	}
	
	// third line - a number to compare elements with
	std::cin >> inputNumber;
	
	// prepare an array to store numbers
	std::vector<int> noRepeatsArray;
	noRepeatsArray.reserve(array.size());
	
	// fill the array with no-repeating numbers
	int lastNumber = -array[0];
	for (auto it = array.begin(); it != array.end(); ++it)
	{
		if (*it != lastNumber)
		{
			lastNumber = *it;
			noRepeatsArray.push_back(lastNumber);
		}
	}
	
	// comparing procedure
	outputNumber = 0;
	for (auto it = noRepeatsArray.begin(); it != noRepeatsArray.end(); ++it)
	{
		if (*it != inputNumber)
		{
			outputNumber++;
		}
	}
	
	// output
	std::cout << outputNumber;
	
	return 0;
}
