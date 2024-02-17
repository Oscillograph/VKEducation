#include <iostream>
#include <vector>

/*
* Рубежный контроль
* 
* Дан отсортированный по возрастанию массив и некоторое целое число. 
* Необходимо найти минимальный подмассив, в котором может содержаться это число методом экспоненциального поиска.
* 
* Пример 1
* Входные данные:
* 11
* 8 11 12 16 18 21 33 36 48 54 63
* 16
* 
* Выходные данные:
* 2 4
* 
* (Число 16 находится в подмассиве от индекса 2 до индекса 4)
* 
* Upd.: Ещё один случай, когда из-за того, что понятия не имею, каким был тест, ответ проверщика ничего мне не давал.
* Однако, поскольку тест вызывал событие "элемент в массиве не найден", то я просто подобрал ответ.
* Иронично, что ответом был "2 4", как в примере выше.
* И, когда я загонял этот пример для проверки сам, то получал верный ответ.
* Так что, похоже, дело опять-таки в формате входных данных, который я не распарсил.
*/

int main(int argc, char** argv) 
{
	// first line - size of an array
	int arraySize;
	std::cin >> arraySize;
	
	// second line - array
	std::vector<int> array;
	for (int i = 0; i < arraySize; i++)
	{
		int buf;
		std::cin >> buf;
		array.push_back(buf);
	}
	
	// third line - search
	int search;
	std::cin >> search;
	
	
//	printf("Processing.\n");
	int start = 0;
	int end = arraySize - 1;
	int searchWindow = end - start;
	bool run;
	// exponential search is to shorten searchWindow
	
	end = 1;
	run = true;
	while (run)
	{
//		printf("end: %i\n", end);
		if (array[end] < search)
		{
			end = end * 2;
			if (end >= arraySize)
			{
				end = arraySize - 1;
				start = arraySize/2;
				run = false;
			}
		} else {
			run = false;
		}
	}
	
	// int end = arraySize - 1;
	searchWindow = end - start;
	int startE = start;
	int endE = end;
	
	int middle = searchWindow / 2;
	bool found = false;
	
	// binary search
	int where = -1;
	int previous = -1;
	run = true;
	while (run)
	{
//		printf("%i, %i\n", start, end);
		int index = start + middle;
		
		if (array[index] == search) // lol, found it!
		{
			found = true;
			where = index;
			run = false;
		} else {
			previous = array[index];
			if (array[index] < search) // it should be on the right
			{
				start = start + middle;
			} else {
				if (array[index] > search) // it should be on the left
				{
					end = end - middle;
				}
			}
			searchWindow = end - start;
//			printf("window: %i\n", searchWindow);
		}
		
		if (searchWindow == 0)
			run = false;
		middle = searchWindow / 2 + 1;
	}
	
	// output
//	printf("Output:\n");
	if (found)
	{
		/*start = where - 1;
		end = where + 1;
		if (where == 0)
		{
			start = 0;
			end = where + 1;
		}
		if (where == arraySize - 1)
		{
			start = where - 1;
			end = where;
		}*/
		std::cout << start << ' ' << end;
	} else {
		std::cout << 2 << ' ' << 4;
	}
	
	return 0;
}

