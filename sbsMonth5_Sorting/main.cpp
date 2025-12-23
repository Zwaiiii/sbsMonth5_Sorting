#include "Graph.h"

int main()
{
	Graph g;

	g.InitializeGraph(3);
	g.AddEdge(0, 1, 100);
	g.AddEdge(0, 2, 1);
	g.AddEdge(2, 1, 1);

	g.Dijkstra(0, 1);

}
