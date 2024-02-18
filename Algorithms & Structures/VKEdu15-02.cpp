#include <iostream>
#include <vector>
#include <unordered_map>

/*
* Найдите путь с минимальным количеством пересадок между станциями.
* 
* Формат входных данных
* N (количество рёбер, 1 ≤ N ≤ 1000), 
* последующие N строк с парой чисел для вершин, два числа, представляющих начальную и конечную станции.
* 
* Формат выходных данных
* Количество пересадок.
* Если путей между станциями нет, то вывести «No path found».
* 
* Пример 1
* Входные данные:
* 4
* 1 2
* 2 3
* 3 4
* 4 5
* 1 5
* 
* Выходные данные:
* 3
*/

struct Edge
{
	bool Has(int a)
	{
		if ((vertices.first == a) || (vertices.second == a))
		{
			return true;
		} else {
			return false;
		}
	}
	
	bool HasOne(int a, int b)
	{
		if (((vertices.first == a) || (vertices.second == b)) ||
			((vertices.first == b) || (vertices.second == a)))
		{
			return true;
		} else {
			return false;
		}
	}
	
	bool Has(int a, int b)
	{
		if (((vertices.first == a) && (vertices.second == b)) ||
			((vertices.first == b) && (vertices.second == a)))
		{
			return true;
		} else {
			return false;
		}
	}
	
	bool Equal(const Edge& edge)
	{
		if (((edge.vertices.first == vertices.first) && (edge.vertices.second == vertices.second)) ||
			((edge.vertices.first == vertices.second) && (edge.vertices.second == vertices.first)))
		{
			return true;
		} else {
			return false;
		}
	}
	
	void ResetVisited()
	{
		visited = false;
	}
	
	void SetVisited()
	{
		visited = true;
	}
	
	bool IsVisited()
	{
		return visited;
	}
	
	std::pair<int, int> vertices;
	int mass = 0;
	bool visited = false;
};

struct Graph
{
	Graph(int cols = 10, int rows = 10)
	{
		graphMap = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 1000));
	}
	
	int Connected(int a, int b)
	{
		return (graphMap[a][b]);
	}
	
	void Connect(int a, int b, int mass = 1000)
	{
		graphMap[a][b] = mass;
		graphMap[b][a] = mass;
		edges.push_back({{a, b}, false, mass});
	}
	
	void Disconnect(int a, int b)
	{
		for (auto it = edges.begin(); it != edges.end(); it++)
		{
			if ((*it).Has(a, b))
			{
				graphMap[a][b] -= (*it).mass;
				graphMap[b][a] -= (*it).mass;
				edges.erase(it);
				break;
			}
		}
	}
	
	std::vector<std::vector<int>> graphMap;
	std::vector<Edge> edges;
};

int main(int argc, char** argv) 
{
	// first line - size of an array
//	printf("Input data:\n");
	
	int arraySize;
	std::cin >> arraySize;
	
	// second line - pairs
	Graph graph(10, 10);
	for (int i = 0; i < arraySize; i++)
	{
		int a, b;
		std::cin >> a;
		std::cin >> b;
		graph.Connect(a, b, 1);
	}
	
	int pointA, pointB;
	std::cin >> pointA;
	std::cin >> pointB;
	
//	printf("Processing.\n");
	// Floyd-Ingerman algorithm
	for (int i = 0; i < graph.graphMap.size(); i++)
	{
		for (int j = 0; j < graph.graphMap.size(); j++)
		{
			for (int k = 0; k < graph.graphMap.size(); k++)
			{
				if (graph.graphMap[j][k] > (graph.graphMap[j][i] + graph.graphMap[i][k]))
				{
					graph.graphMap[j][k] = (graph.graphMap[j][i] + graph.graphMap[i][k]);
				}
			}
		}
	}
	
	// output
//	printf("Output:\n");
//	std::cout << "Path Length: " << path.size() << "\n";
	if (graph.graphMap[pointA][pointB] == 1000)
	{
		std::cout << 0;
	} else {
		std::cout << (graph.graphMap[pointA][pointB] - 1);
	}
	
	return 0;
}

