#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#include "graph.h"

class undirected_graph : public Graph 
{
	private:
		int nodes;
		bool findCycle(int vertex, vector<int> &color, vector<int> &parent);

	public:
		undirected_graph()
		{
			this->nodes = 0;
		}
		undirected_graph(int nodes) : Graph(nodes)
		{
			this->nodes = nodes;
		}
		void add_edge(int srcVertex, int destVertex, long long int weight = 1)
		{
			adjacencyList[srcVertex].push_back({destVertex, weight});
			adjacencyList[destVertex].push_back({srcVertex, weight});
		}
		int length();
		bool is_cyclic();

		~undirected_graph()
		{
			delete adjacencyList;
		}
};

int undirected_graph::length()
{
	int length = 0;
	for(int i = 1 ; i <= nodes ; i++)
	{
		length += adjacencyList[i].size();
	}
	return length/2;
}

bool undirected_graph::is_cyclic()
{
	if(nodes <= 1)
	{
		return false;
	}

	vector<int> color(nodes+1, 0);
	vector<int> parent(nodes+1, -1);

	for(int vertex = 1 ; vertex <= nodes ; vertex++)
	{
		if(color[vertex] == 0 && findCycle(vertex, color, parent))
		{
			return true;
		}
	}
	return false;
}

bool undirected_graph::findCycle(int vertex, vector<int> &color, vector<int> &parent)
{
	color[vertex] = 1;
	for(auto v: adjacencyList[vertex])
	{
		int neighbour = v.first;
		if(neighbour == parent[vertex])
		{
			continue;
		}
		if(color[neighbour] == 0)
		{
			parent[neighbour] = vertex;
			if(findCycle(neighbour, color, parent))
			{
				return true;
			}
		}
		else if(color[neighbour] == 1)
		{
			return true;
		}
	}
	color[vertex] = 2;
	return false;
}

#endif