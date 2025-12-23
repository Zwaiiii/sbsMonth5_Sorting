#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node {
	int x;
	int y;
	int weight;
};

struct cmp {
	bool operator()(Node a, Node b) {
		return a.weight < b.weight;
	}
};

int main() {
	vector<vector<char>> board(3, vector<char>(3));

	int n;
	cin >> n;
	pair<int, int> start;
	for (int test = 0; test < n; test++) {
		/////// 보드 입력, 시작점 입력
		for (int i = 0; i < 3; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 3; j++) {
				board[i][j] = s[j];
				if (s[j] == '#') start = make_pair(i, j);
			}
		}
		///////
		priority_queue<Node, vector<Node>, cmp> pq;

		pq.push(Node(start.second, start.first, 0));




	}
}

