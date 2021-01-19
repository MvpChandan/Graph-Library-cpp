#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
using namespace std;

class Graph {
	private:
		int countOfNodes;
	
	protected:
		vector<pair<int,int>> *adjacencyList;

	public:
		Graph()
		{
			this->countOfNodes = 0;
		}
		Graph(int countOfNodes)
		{
			this->countOfNodes = countOfNodes;
			adjacencyList = new vector<pair<int,int>>[countOfNodes+1];
		}
		bool empty();
		void display();

		vector<int> DFS(int sourceVertex);
		vector<int> BFS(int sourceVertex);

		vector<int> neighbours(int sourceVertex);
		vector<vector<int>> components();

		void DFSTraversalHelper(vector<int> &nodesFound, vector<bool> &visited, int sourceVertex);

		virtual ~Graph()
		{
			delete adjacencyList;
		}
};

bool Graph::empty()
{
	for(int i = 1 ; i <= countOfNodes ; i++)
	{
		if(adjacencyList[i].size() > 0) 
		{
			return false;
		}
	}
	return true;
}

void Graph::DFSTraversalHelper(vector<int> &nodesFound, vector<bool> &visited, int sourceVertex)
{
	visited[sourceVertex] = true;
	nodesFound.push_back(sourceVertex);

	for(auto vertex: adjacencyList[sourceVertex])
	{
		int neighbour = vertex.first;
		if(!visited[neighbour])
		{
			DFSTraversalHelper(nodesFound, visited, neighbour);
		}
	}
}

vector<int> Graph::DFS(int sourceVertex)
{
	vector<int> nodesFound;
	vector<bool> visited(countOfNodes+1, false);
	DFSTraversalHelper(nodesFound, visited, sourceVertex);
	return nodesFound;
}

vector<int> Graph::BFS(int sourceVertex)
{
	vector<bool> visited(countOfNodes+1, false);
	vector<int> nodesFound;
	nodesFound.push_back(sourceVertex);

	queue<int> exploreNodes;
	exploreNodes.push(sourceVertex);
	visited[sourceVertex] = true;

	while(!exploreNodes.empty())
	{
		int currentVertex = exploreNodes.front();
		exploreNodes.pop();

		for(auto vertex: adjacencyList[currentVertex])
		{
			int neighbour = vertex.first;
			if(!visited[neighbour])
			{
				visited[neighbour] = true;
				exploreNodes.push(neighbour);
				nodesFound.push_back(neighbour);
			}
		}
	}
	return nodesFound;
}

vector<int> Graph::neighbours(int sourceVertex)
{
	vector<int> neighbour;
	for(auto vertex: adjacencyList[sourceVertex])
	{
		neighbour.push_back(vertex.first);
	}
	return neighbour;
}

vector<vector<int>> Graph::components()
{
	vector<bool> visited(countOfNodes+1, false);
	vector<vector<int>> connectedComponents;

	for(int i = 1 ; i <= countOfNodes ; i++)
	{
		if(!visited[i])
		{
			vector<int> individualComponent;
			DFSTraversalHelper(individualComponent, visited, i);
			connectedComponents.push_back(individualComponent);
		}
	} 
	return connectedComponents;
}

void Graph::display()
{
	for(int i = 1 ; i <= countOfNodes ; i++)
	{
		cout << i << " : ";
		for(auto x: adjacencyList[i])
		{
			cout << x.first << ' ';
		}
		cout << endl;
	}
}

#endif