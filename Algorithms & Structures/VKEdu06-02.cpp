#include <iostream>
#include <vector>
#include <string>

/*
* Дана строка s. 
* Строка состоит из английских букв в нижнем регистре.
* Необходимо из строки удалить все рядом стоящие повторяющиеся буквы. 
* Например, в строке xyyx мы должны удалить yy, а после и оставшиеся xx и того после должна получиться пустая строка. 
* Или же в строке fqffqzzsd после удаления остануться только fsd. 
* Первыми удаляться ff, являющимися третьими и четвертыми символами, затем qq и после уже zz.
*/

int main(int argc, char** argv) 
{
	// input string
	std::string string = "";
	printf("Write a string:\n");
	std::getline(std::cin, string);
	
	// process
	printf("Processing.\n");
	if (string.size() > 1)
	{
		auto it1 = string.begin();
		auto it2 = string.begin()+1;
		for ( ; (it1 != string.end()) && (it2 != string.end()); )
		{
			if ((*it1) == (*it2)) // match!
			{
				string.erase(it1, it2+1);
				it1 = string.begin();
				it2 = string.begin()+1;
			} else {
				it1++;
				it2++;
			}
		}
	} else {
		printf("String size cannot be less than 2!\n");
	}
	
	// output
	printf("Output:\n");
	std::cout << string.c_str();
	
	return 0;
}

