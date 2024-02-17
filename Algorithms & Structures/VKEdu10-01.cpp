#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

/*
* Рубежный контроль
* 
* Дан массив целых чисел. 
* Необходимо вернуть элемент, который встречается больше половины раз. 
* Если такого элемента нет, возвращайте -1
* 
* Примечание: первая строка во вводе - число элементов в массиве
*/

int main(int argc, char** argv) 
{
	// first line - size of an array
	int arraySize;
	std::cin >> arraySize;
	
	// second line - array
	std::unordered_map<int, int> array = {};
	int buf = 0;
	int max = 0;
	int record = 0;
	for (int i = 0; i < arraySize; i++)
	{
		std::cin >> buf;
		array[buf]++;
		
		if (array[buf] > max)
		{
			max = array[buf];
			record = buf;
		}
	}
	

//	printf("Processing.\n");
	
	// output
//	printf("Output:\n");
	if ((array.size() / (float)max) < 2.0f)
	{
		std::cout << record;
	} else {
		std::cout << -1;
	}
	
	return 0;
}

