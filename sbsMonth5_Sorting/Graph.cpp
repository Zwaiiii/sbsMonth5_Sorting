#include "Graph.h"

void Graph::InitializeGraph(int nodeCount)
{
    isVisited.resize(nodeCount, false);
    graph = new Node * [nodeCount] {nullptr};
    count = nodeCount;
}

void Graph::AddEdge(int from, int to)
{  
   if (graph[from] == nullptr) graph[from] = CreateNode(to);
   else {
       Node* next = graph[from];
       while (next->next != nullptr) next = next->next;
       next->next = CreateNode(to);
   }
} 

void Graph::ShowGraphEdge(int node)
{
    Node* temp;
    if (graph[node] != nullptr) temp = graph[node];
    else return;

    cout << "Node [" << node << "]->";
    
     while (temp != nullptr) {
            cout << "[" << temp->data << "]->";
            temp = temp->next;
      }
    cout << "[NULL]" << endl;
}

bool Graph::VisitVertex(int node)
{
    return false;
}

void Graph::DepthFirstSearch(int node)
{
    isVisited.assign(count, false);

    stack<int> s;
    s.push(node);
    isVisited[node] = true;
    
    while (!s.empty()) {
        int node = s.top(); s.pop();
        cout << node << " ";
        Node* temp = graph[node];
        while (temp != nullptr) {
            if (isVisited[temp->data] == false) {
                s.push(temp->data);
                isVisited[temp->data] = true;
            }
            temp = temp->next;
        }
    }

    cout << endl;
}

void Graph::BreadthFirstSearch(int node)
{
    isVisited.assign(count, false);

    queue<int> q;
    q.push(node);
    isVisited[node] = true;
    while (!q.empty()) {
        int num = q.front(); q.pop();
        cout << num << " ";
        Node* temp = graph[num];
        while (temp != nullptr) {
            if (isVisited[temp->data] == false)
            {
                q.push(temp->data);
                isVisited[temp->data] = true;
            }
            temp = temp->next;
        } 
    }
    cout << endl;
}

Node* Graph::CreateNode(int data)
{
    Node* temp = new Node{ data, nullptr };
    return temp;
}

Graph::Graph()
{
}

Graph::~Graph()
{
}

