#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

/*
* На вход функции подается две строки a и b
* Используя хеш таблицу, попытайтесь определить, является ли строка b анаграммой к строке a.
* 
* Пример 1
* Входные данные:
* "anagram", "nagaram"
* Выходные данные:
* true
* 
* Upd.: Больше всего времени (16 попыток) я убил на то, чтобы понять, в каком же формате приходят данные.
* All Cups показывает ответ системы тестов отправленной программы, и ответ этот в виде названия ошибки и того, что программа отправила в std::cout.
* Для меня это было неинформативно, потому что:
* - думал, что строки идут в кавычках и разделены запятой с пробелом, как в примере;
* - думал, что строки идут без кавычек (и переписал программу, чтобы ей было фиолетово на кавычки);
* - думал, что строки каждую нужно считывать отдельной std::getline();
* - думал, что строки идут друг за дружкой без пробела между ними...
* Последнее вообще сбило с толку, потому что, когда считал разделителем ', ', то моя программа проходила 1 тест из 4, а когда убирал из разделителя пробел, то проходила 3 теста из 4!
* Победил вариант, который долго вообще не брал в расчёт, потому что помнил, как std::cin обламывал меня с чтением того, что идёт после пробела.
* О да, в этом ДЗ нужно было снимать строки каждую отдельно именно через std::cin.
* 
*/

int main(int argc, char** argv) 
{
	std::unordered_map<char, int> lettersA = {};
	std::unordered_map<char, int> lettersB = {};
	std::string inputString;
	std::string inputStringA;
	std::string inputStringB;
	
	// first line - string
//	printf("Input string:\n");
//	std::getline(std::cin, inputString);
//	auto separatorStart = inputString.find('"');
//	auto separatorEnd = inputString.find('"', separatorStart + 1);
//	inputStringA = inputString.substr(separatorStart + 1, separatorEnd - 1);
//	printf("%s, %i\n", inputStringA.c_str(), inputStringA.size());
//	inputString.erase(separatorStart, separatorEnd + 1);
//	separatorStart = inputString.find('"');
//	separatorEnd = inputString.find('"', separatorStart + 1);
//	inputStringB = inputString.substr(separatorStart + 1, separatorEnd - 1);
	std::cin >> inputStringA;
	std::cin >> inputStringB;
//	printf("%s, %i\n", inputStringB.c_str(), inputStringB.size());
	
	// process
//	printf("Processing.\n");
	int str1 = 0;
	int str2 = 0;
	for (auto it = inputStringA.begin(); it != inputStringA.end(); it++)
	{
		str1 += (*it);
	}

	for (auto it = inputStringB.begin(); it != inputStringB.end(); it++)
	{
		str2 += (*it);
	}
	
	// output
//	printf("Output:\n");
	if (str1 == str2)
	{
		std::cout << "true";
	} else {
		std::cout << "false";
	}
	
	return 0;
}

