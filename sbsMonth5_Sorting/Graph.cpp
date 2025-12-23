#include "Graph.h"

void Graph::InitializeGraph(int nodeCount)
{
    isVisited.resize(nodeCount, false);
    graph = new Node * [nodeCount] {nullptr};
    count = nodeCount;
}

void Graph::AddEdge(int from, int to, int weight)
{  
   if (graph[from] == nullptr) graph[from] = CreateNode(to, weight);
   else {
       Node* next = graph[from];
       while (next->next != nullptr) next = next->next;
       next->next = CreateNode(to, weight);
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

void Graph::Dijkstra(int start, int end)
{
    if (start == end) { // start랑 end랑 같은지 확인.
        cout << "0"; 
        return;
    }

    //다이나믹 프로그래밍 점화식 이용.
    //이전까지 저장해놓은 최단거리랑 비교해서 낮은갚을 계속 변수에 저장.
    //배열에 각각 노드까지의 거리를 저장 -> 가장 적은 값을 계속 비교.

    vector<int> dp(count, INT_MAX); // 각각 노드까지의 거리를 저장할 배열
    dp[start] = 0;
    Node* temp;

    vector<bool> visited(count, false);
    int now = start;

    while(true)
    {
        if(visited[now] == false) {
            temp = graph[now];
            visited[now] = true;
            while (temp != nullptr) {
                // 가중치 낮은값부터 다음으로 찾아야하함.
                dp[temp->data] = dp[temp->data] <= dp[now] + temp->weight ? dp[temp->data] : dp[now] + temp->weight;
                temp = temp->next;
            }
        }
    }

    cout << dp[end] << endl;
}

Node* Graph::CreateNode(int data, int weight)
{
    Node* temp = new Node{ data, weight, nullptr };
    return temp;
}

Graph::Graph()
{
}

Graph::~Graph()
{
}

