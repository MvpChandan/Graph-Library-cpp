# Graph-Library-cpp
An implementation of graph data structure along with common graph algorithms using OOPs and STL containers. An abstract base class Graph is used to model a graph. The derived classes DirectedGraph and UndirectedGraph inherit from base class Graph.


## Getting Started

Download or clone the repository, copy the required header file to location of your program and then include the header file(s) in your program (main.cpp file).

``` c++
#include <iostream>
#include "directed_graph.h"
#include "undirected_graph.h"

using namespace std;

int main()
{
	return 0;
}
```

## Implementation

### Creating new graph

A directed graph is declared using `directed_graph` and undirected graph is declared using `undirected_graph` along with a parameter i.e no. of edges in the graph to constructor.

``` c++
int main()
{
	directed_graph g1(x); //Where x represents no. of vertices in graph
	undirected_graph g2(x);

	// Using dynamic memory allocation
	directed_graph *graph = new directed_graph(x);
	// deallocating using delete
	delete graph;
}
```

### Adding edges

Edges are added using `add_edge` function and vertices will be created automatically if they don't already exist. It takes 2 arguments as `vertices` and 3rd argument is optional i.e the `weigth of edge` connecting them.

```c++
// Makes an edge between u and v with weight 1.
graph.add_edge(u, v);

// Makes an edge between u and v with given weight.
graph.add_edge(u, v, weight);
```

### Algorithms

1. **Depth First Search** :
The DFS algorithm is implemented in Graph.h and takes an arguement, the 
starting vertex and start DFS from this vertex.

```c++
vector<int> list = graph.DFS(vertex);
```

2. **Breadth First Search** : 
The BFS algorithm is implemented in Graph.h and takes an arguement, the 
starting vertex and start BFS from this vertex.

```c++
vector<int> list = graph.BFS(vertex);
```

3. **Components** :
This method is defined in Graph.h and returns a 2d list conatining the different components seperately.

```c++
vector<vector<int>> list = graph.components();
```

4. **Cycle** :
This method is defined in directed_graph.h and undirected_graph.h and returns a boolean value whether a cycle is present or not.

```c++
if(graph.is_cyclic()) {
	cout << "Graph contains cycle";
}
else {
	cout << "No cycle found";
}
```

5. **Neighbours** :
This method is implemented in Graph.h and returns the list of neighbours of a given vertex.

```c++
vector<int> list = graph.neighbours();
```

6. **Empty** :
This method is implemented in Graph.h and returns the boolean value whether the graph contains an edge or not.

```c++
if(graph.empty()) {
	cout << "Graph contains no edge";
}
else {
	cout << "Graph contains edge";
}
```

## 
