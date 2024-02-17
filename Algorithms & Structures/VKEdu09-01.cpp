#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

/*
* Есть строка с многократным повторением разных букв. 
* Надо понять какое максимальное количество повторений встречается в строке. 
* Используя хеш таблицу, записывайте пару буква - количество вхождений в строку.
* 
* Пример 1
* Входные данные:
* adeuuuuio
* 
* Выходные данные:
* 4
*/

int main(int argc, char** argv) 
{
	std::unordered_map<char, int> letters;
	std::string inputString;
	
	// first line - string
	printf("Input string:\n");
	std::getline(std::cin, inputString);
	
	// process
	printf("Processing.\n");
	for (auto it = inputString.begin(); it != inputString.end(); it++)
	{
		letters[(*it)]++;
	}
	
	int max = 0;
	for (auto it : letters)
	{
		if (it.second > max)
		{
			max = it.second;
		}
	}
	
	// output
	printf("Output:\n");
	std::cout << max;
	
	return 0;
}

