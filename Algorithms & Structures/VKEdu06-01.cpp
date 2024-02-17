#include <iostream>
#include <vector>
#include <string>

/*
* Дан массив не отсортированных целых чисел. 
* Написать функцию, которая вернет первое с конца четное число. 
* При написании кода используйте принцип стека. 
* Если массив не содержит четного числа возвращать -1.
*/

bool IsEven(int number)
{
	return !(number % 2);
}

struct Stack
{
public:
	void Push(int number)
	{
		m_Array.push_back(number);
	}
	
	int Pop()
	{
		if (m_Array.size() > 0)
		{
			int out = *(m_Array.end()-1);
			m_Array.erase(m_Array.end()-1);
			return out;
		} else {
			return -1;
		}
	}
	
	int Read()
	{
		if (m_Array.size() > 0)
		{
			return *(m_Array.end()-1);
		} else {
			return -1;
		}
	}
	
private:
	std::vector<int> m_Array;
};

int main(int argc, char** argv) 
{
	int inputNumber = 0;
	
	// first line - total array size
	printf("Array size:\n");
	std::cin >> inputNumber;
	
	Stack array;
//	std::vector<int> array;
//	array.reserve(inputNumber);
//	array.resize(inputNumber);
	
	// second line - the array content
	printf("Write an array:\n");
	for (int i = 0; i < inputNumber; i++)
	{
		std::string buf;
		std::cin >> buf;
		array.Push(std::atoi(buf.c_str()));
	}
	
	// process
	printf("Processing.\n");
	
	// output
	printf("Output:\n");
	int buf;
	while (buf >= 0)
	{
		buf = array.Pop();
		if (IsEven(buf))
		{
			std::cout << buf;
			buf = -2;
		}
	}
	if (buf == -1)
	{
		std::cout << buf;
	}
	
//	for (int i = 0; i < array.size(); i++)
//	{
//		std::cout << array[i] << ' ';
//	}
	
	return 0;
}

