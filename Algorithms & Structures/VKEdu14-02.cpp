#include <iostream>
#include <vector>
#include <unordered_map>

/*
* Определите количество различных социальных кругов в графе. 
* Социальный круг – это подграф, где все вершины связаны между собой напрямую или через других членов круга.
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
* 4
* 1 2
* 2 3
* 3 4
* 5 6
* 
* Выходные данные:
* 2
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
	int socialClubs = 0;
	std::vector<Edge> path;
	std::vector<Edge> possibleStarts;
	std::unordered_map<int, bool> social = {};
	
	// pick every vertice
	for (int j = 0; j < graph.graphMap.size(); j++)
	{
		// prepare to search for edges starting from this vertice
		if (social.find(j) == social.end())
		{
			possibleStarts.clear();
			for(int i = 0; i < graph.edges.size(); i++)
			{
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
			
			if (possibleStarts.size() > 0)
			{
				socialClubs++;
			}
			
			// pick every edge
			for (int possibleStartingEdgeIndex = 0; possibleStartingEdgeIndex < possibleStarts.size(); possibleStartingEdgeIndex++)
			{
				path.clear();
				
				path.push_back(possibleStarts[possibleStartingEdgeIndex]);
				social[path[0].vertices.first] = true;
				social[path[0].vertices.second] = true;
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
							if (graph.edges[i].vertices.second == path[path.size()-1].vertices.second)
							{
								path.push_back({{graph.edges[i].vertices.second, graph.edges[i].vertices.first}, true});
							} else {
								path.push_back(graph.edges[i]);
							}
							social[path[path.size()-1].vertices.second] = true;
						}
						
						// if we got into where we started
						if (path[path.size()-1].vertices.second == j)
						{
//						printf("Found a cycle starting from %i (%i, %i)\n", j, graph.edges[i].vertices.first, graph.edges[i].vertices.second);
							// j = graph.graphMap.size() + 1;
							// possibleStartingEdgeIndex = possibleStarts.size() + 1;
							break;
						}
					}
				}
			}
		}
	}
	
	// output
//	printf("Output:\n");
//	std::cout << "Path Length: " << path.size() << "\n";
	std::cout << socialClubs;
	
	return 0;
}

