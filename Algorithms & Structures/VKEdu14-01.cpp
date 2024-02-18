#include <iostream>
#include <vector>

/*
* У вас есть граф, где каждая вершина представляет человека, 
* а ребро между двумя вершинами означает, что эти два человека друзья. 
* Найдите, существуют ли три человека, которые все взаимно дружат друг с другом 
* (то есть между каждой парой из трех человек существует ребро).
* 
* Формат входных данных
* N (количество рёбер в графе, 1 ≤ N ≤ 1000),
* последующие N строк с парой чисел, представляющих вершины (друзей).
* 
* Формат выходных данных
* "YES" или "NO"
* 
* - - -
* Пример 1
* Входные данные:
* 3
* 1 2
* 2 3
* 1 3
* 
* Выходные данные:
* YES
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
	bool visited = false;
};

struct Graph
{
	Graph(int cols = 10, int rows = 10)
	{
		graphMap = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
	}
	
	int Connected(int a, int b)
	{
		return (graphMap[a][b]);
	}
	
	void Connect(int a, int b)
	{
		graphMap[a][b]++;
		graphMap[b][a]++;
		edges.push_back({{a, b}, false});
	}
	
	void Disconnect(int a, int b)
	{
		graphMap[a][b]--;
		graphMap[b][a]--;
		for (auto it = edges.begin(); it != edges.end(); it++)
		{
			if ((*it).Has(a, b))
			{
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
	Graph graph;
	for (int i = 0; i < arraySize; i++)
	{
		int a, b;
		std::cin >> a;
		std::cin >> b;
		graph.Connect(a, b);
	}
	
//	printf("Processing.\n");
	int countCycles = 0;
	std::vector<int> connectionsL1, connectionsL2;
	for(int i = 0; i < graph.graphMap.size(); i++)
	{
		for (int j = 0; j < graph.graphMap[i].size(); j++)
		{
//			std::cout << graph.Connected(i, j) << ' ';
		}
//		std::cout << "\n";
	}
	
	int pathLength = 0;
	std::vector<Edge> path;
	std::vector<Edge> possibleStarts;
	
	// pick every vertice
	for (int j = 0; j < graph.graphMap.size(); j++)
	{
		// prepare to search for edges starting from this vertice
		for(int i = 0; i < graph.edges.size(); i++)
		{
			graph.edges[i].ResetVisited();
			if (graph.edges[i].Has(j))
			{
				if (graph.edges[i].vertices.second == j)
				{
					possibleStarts.push_back({{graph.edges[i].vertices.second, graph.edges[i].vertices.first}, true});
				} else {
					possibleStarts.push_back(graph.edges[i]);
				}
			}
		}
		
		// pick every edge
		for (int possibleStartingEdgeIndex = 0; possibleStartingEdgeIndex < possibleStarts.size(); possibleStartingEdgeIndex++)
		{
			pathLength = 0;
			path.clear();
			
			pathLength++;
			path.push_back(possibleStarts[possibleStartingEdgeIndex]);
//			printf("Start a new path from %i (%i, %i)\n", j, path[0].vertices.first, path[0].vertices.second);
			
			for (int i = 0; i < graph.edges.size(); i++)
			{
				if (path.size() > 0)
				{
					// if it's where we started
					if (path[0].Equal(graph.edges[i]))
					{
						// choose another edge
						continue;
					}
					
					// if it's where we are
					if (path[path.size()-1].Equal(graph.edges[i])) 
					{
						// choose another edge
						continue;
					}
					
					// if it's an edge we can walk on
					if (graph.edges[i].Has(path[path.size()-1].vertices.second))
					{
//						printf("Continue path from %i (%i, %i)\n", j, graph.edges[i].vertices.first, graph.edges[i].vertices.second);
						pathLength++;
						if (graph.edges[i].vertices.second == path[path.size()-1].vertices.second)
						{
							path.push_back({{graph.edges[i].vertices.second, graph.edges[i].vertices.first}, true});
						} else {
							path.push_back(graph.edges[i]);
						}
					}
					
					// if we got into where we started
					if (path[path.size()-1].vertices.second == j)
					{
//						printf("Found a cycle starting from %i (%i, %i)\n", j, graph.edges[i].vertices.first, graph.edges[i].vertices.second);
						j = graph.graphMap.size() + 1;
						possibleStartingEdgeIndex = possibleStarts.size() + 1;
						break;
					}
				}
			}
		}
	}
	
	// output
//	printf("Output:\n");
//	std::cout << "Path Length: " << path.size() << "\n";
	if (pathLength == 3)
	{
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
	
	return 0;
}

