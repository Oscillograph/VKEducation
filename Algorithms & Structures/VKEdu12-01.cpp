#include <iostream>
#include <vector>
#include <math.h>

/*
* Дана последовательность целых чисел и число K. 
* Найдите максимальное произведение подпоследовательности размером K.
* 
* Пример 1
* Входные данные:
* 5
* 1 2 3 4 5
* 2
* 
* Выходные данные:
* 20
*/

/*
* Примечание в ходе прохождения тестов на All Cups: в массиве могут быть отрицательные числа.
*/
// classic merge sort
void MergeSort(std::vector<int>& source, int left, int right)
{
	if (left == right)
	{
		// arrays of size 1 are sorted already
		return;
	}
	
	// divide and call recursion
	int middle = (left + right)/2;
	MergeSort(source, left, middle);
	MergeSort(source, middle + 1, right);
	
	// sort these arrays
	int start1 = left;
	int start2 = middle + 1;
	
	std::vector<int> temp; // temporary array
	temp.resize(right);
	
	for (int i = 0; i < (right - left + 1); i++) // pick every element in an array of length (right - left - 1)
	{
		if ((start2 > right) || // what's left of the first interval
			((start1 <= middle) && // we have only one interval
				(source[start1] <= source[start2])))  // left number is less than right number
		{
			temp[i] = source[start1];
			start1++;
		} else {
			temp[i] = source[start2];
			start2++;
		}
	}
	
	// rewrite the source array
	for (int i = 0; i < (right - left + 1); i++)
	{
		source[left + i] = temp[i];
	}
}

int GetResultRight(const std::vector<int>& array, int k)
{
	int resultRight = 1;
	for (int i = array.size()-1; i > array.size() - k - 1; i--)
	{
		resultRight = resultRight * array[i];
	}
	
	return resultRight;
}

int GetResultLeft(const std::vector<int>& array, int k)
{
	int zeroPosition = 0;
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] < 0)
		{
			zeroPosition++;
		}
	}
	
	int resultLeft = 1;
	int j = 0; // counter on the right side
	bool needToPickFromRight = false;
	for (int i = 0; i < k; i++)
	{
		if ((i > 0) && (resultLeft > 0))
		{
			if (zeroPosition < (array.size() - 1 - j))
			{
				needToPickFromRight = true;
				resultLeft = resultLeft * array[array.size() - 1 - j];
				j++;
			} else {
				resultLeft = resultLeft * array[i - j];
			}
		} else {
			resultLeft = resultLeft * array[i - j]; // ugly repetition, but works
		}
//		printf("Left result: %i\n", resultLeft);
	}
	return resultLeft;
}

int main(int argc, char** argv) 
{
	// first line - size of an array
//	printf("Input array size:\n");
	int arraySize;
	std::cin >> arraySize;
	
	// second line - array
//	printf("Input array:\n");
	std::vector<int> array;
	for (int i = 0; i < arraySize; i++)
	{
		int buf;
		std::cin >> buf;
		array.push_back(buf);
	}
	
	// third line - number K
//	printf("Input K:\n");
	int k;
	std::cin >> k;
	
//	printf("Processing.\n");
	// sort
	MergeSort(array, 0, array.size()-1);
	// select and multiply
	int resultLeft = GetResultLeft(array, k);
	int resultRight = GetResultRight(array, k);
	
	// output
//	printf("Output:\n");
	std::cout << ((resultLeft > resultRight) ? resultLeft : resultRight);
	
	return 0;
}

