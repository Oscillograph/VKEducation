#include <iostream>
#include <vector>
#include <string>

struct Book
{
	std::string ISBN = "";
	std::string Name = "";
	int Year = 0;
};

// classic merge sort
void MergeSort(std::vector<Book>& source, int left, int right)
{
	// printf("processing source: %i, %i\n", left, right);
	if (left == right)
	{
		// arrays of size 1 are sorted already
		// printf("Sorted!\n");
		return;
	}
	
	// divide and call recursion
	int middle = (left + right)/2;
	MergeSort(source, left, middle);
	MergeSort(source, middle + 1, right);
	
	// sort these arrays
	int start1 = left;
	int start2 = middle + 1;
	
	std::vector<Book> temp; // temporary array
	temp.resize(right - left + 1);
	
	for (int i = 0; i < (right - left + 1); i++) // pick every element in an array of length (right - left - 1)
	{
		//printf("Step #%i...\n", i);
		if ((start2 > right) || // what's left of the first interval
			((start1 <= middle) && // we have only one interval
				(source[start1].Year <= source[start2].Year)))  // left number is less than right number
		{
			temp[i] = source[start1];
			start1++;
			// printf("Left is bigger\n");
		} else {
			temp[i] = source[start2];
			start2++;
			// printf("Right is bigger\n");
		}
	}
	
	// rewrite the source array
	// printf("rewriting source: %i, %i\n", left, right);
	for (int i = 0; i < (right - left + 1); i++)
	{
		source[left + i] = temp[i];
	}
}

int main(int argc, char** argv) 
{
	int inputNumber = 0;
	
	// first line - total array size
	// printf("Array size:\n");
	std::cin >> inputNumber;
	
	std::vector<Book> array;
	array.reserve(inputNumber);
	array.resize(inputNumber);
	
	// second line - the array content
	// printf("Write an array:\n");
	std::string buf;
	for (int i = 0; i < inputNumber; i++)
	{
		// std::cin >> array[i];
		std::cin >> array[i].ISBN;
		std::cin >> array[i].Name;
		while (*(array[i].Name.end()-1) != '"')
		{
			std::cin >> buf;
			array[i].Name += (" " + buf);
		}
		std::cin >> array[i].Year;
		/*
		Book book;
		std::cin >> book.ISBN;
		std::cin >> book.Name;
		std::cin >> book.Year;
		array.push_back(book);
		*/
	}
	
	// process
	// printf("Processing.\n");
	MergeSort(array, 0, array.size() - 1);
	
	// output
	// printf("Output:\n");
	for (int i = 0; i < array.size(); i++)
	{
		// std::cout << array[i] << ' ';
		std::cout << array[i].ISBN.c_str() << ' ' << array[i].Name.c_str() << ' ' << array[i].Year << "\n";
	}
	
	return 0;
}
