#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct Node
{
	int data;
	int weight;
	Node* next;
};

class Graph
{
private:
	int count = 0;
	vector<bool> isVisited;
	Node** graph = nullptr;
public:
	void InitializeGraph(int nodeCount);
	void AddEdge(int from, int to, int weight);
	void ShowGraphEdge(int node);
	bool VisitVertex(int node);
	void DepthFirstSearch(int node);  // stack
	void BreadthFirstSearch(int node);// queue
	void Dijkstra(int start, int end);

private:
	Node* CreateNode(int data, int weight);
public:
	Graph();
	~Graph();
};

