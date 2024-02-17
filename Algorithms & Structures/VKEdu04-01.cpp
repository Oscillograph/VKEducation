#include <iostream>
#include <vector>
#include <string>

// #include <math.h>

/*
struct vec2
{
	int x = 0;
	int y = 0;
};

struct Interval
{
	int length = 2;
	int start = 0;
	int end = 0;
	bool sorted = false;
};

bool MergeSort(std::vector<int>& source)
{
	bool success = false;
	
	int currentLength = 2; // the tiniest interval
	int temp = 0; // a buffer for one value
	Interval intervalA, intervalB; // intervals
	
	while (currentLength <= source.size())
	{
		// general O(log n) part
		intervalA = {currentLength, 0, currentLength - 1, false};
		intervalB = {currentLength, currentLength, 2*currentLength - 1, false};
		printf("length: %i\n", currentLength);
		
		int sourceSize = source.size();
		for (int i = 0; (i * currentLength - sourceSize) <= (2 * currentLength); i+=2)
		{
			printf("where we are: %i\n", i * currentLength);
			// set up intervals
			intervalA.length = currentLength;
			intervalA.start = i * currentLength;
			intervalA.sorted = false;
			
			intervalB.length = currentLength;
			intervalB.start = (i + 1) * currentLength;
			intervalB.sorted = false;
			
			// check if the intervals are in the array - there are several options
			// 1. We have only left interval which is not full
			if ((intervalA.start + intervalA.length) > source.size())
			{
				intervalA.length = source.size() - intervalA.start;
				intervalA.end = intervalA.start + intervalA.length - 1;
				intervalA.sorted = true;
			}
			
			// 2. We have two intervals, the right one is not full
			if ((intervalB.start + intervalB.length) > source.size())
			{
				intervalB.length = source.size() - intervalB.start;
				intervalB.end = intervalB.start + intervalB.length - 1;
			}
			
			// 3. We have two intervals, both of proper size
			if (!intervalA.sorted)
			{
				for (int i = 0; i < intervalA.length; i++)
				{
					if (source[intervalA.start + i] <= source[intervalB.start + i])
					{
						// do nothing
						printf("intervalA: {%i, %i}\n", intervalA.start, intervalA.end);
					}
					
					if (source[intervalA.start + i] > source[intervalB.start + i])
					{
						printf("intervalB: {%i, %i}\n", intervalB.start, intervalB.end);
						// save the value in a temporary location
						temp = source[intervalB.start + i];
						// shift everything to the right by 1
						for (int j = intervalB.end; j > (intervalA.start + i); j++)
						{
							source[j] = source[j - 1];
						}
						// store the value in its place
						source[intervalA.start + i] = temp;
						
						// update indexes
						
						// intervalA.start++;
						// if ((intervalB.start + i) < intervalB.end)
						// {
						//	intervalB.start++;
						//	intervalB.length--;
						// }
						
					}
				}
			}
		}
		
		// prepare the next O(log n) cycle
		currentLength = 2 * currentLength;
	}
	
	success = true;
	
	return success;
}
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

struct Book
{
	std::str
};

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
	
	// process
	printf("Processing.\n");
	MergeSort(array, 0, array.size() - 1);
	
	// output
	printf("Output:\n");
	for (int i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << ' ';
	}
	
	return 0;
}
