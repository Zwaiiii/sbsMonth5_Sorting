#include<iostream>
#include<vector>
#include<queue>
#include<string>
#define SWAP(a, b) {int temp = a; a = b; b = temp;}

using namespace std;

vector<vector<int>> board(3, vector<int>(3));
vector<vector<int>> const answer = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } };

struct Node {
	int y;
	int x;
	int weight;
	int count;
	vector<vector<int>> currentBoard;
	Node() { currentBoard.assign(3, vector<int>(3)); }
	bool operator<(const Node& other) const {
		return weight > other.weight;
	}
};

int checkWeight(int bx, int by, int x, int y) {
	SWAP(board[by][bx], board[y][x]);
	int weight = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == answer[i][j]) weight++;
		}
	}
	SWAP(board[by][bx], board[y][x]);

	return weight;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> result;

	pair<int, int> start;
	for (int test = 0; test < n; test++) {
		/////// 보드 입력, 시작점 입력
		for (int i = 0; i < 3; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 3; j++) {
				if (s[j] == '#') {
					start = make_pair(i, j);
					board[i][j] = 0;
				}
				else board[i][j] = s[j] - '0';
			}
		}
		///////
		priority_queue<Node> pq;

		pq.push({ start.first, start.second, board[start.first][start.second], 0 });
		
		int w = 0;

		while(!pq.empty()){
			auto node = pq.top(); pq.pop();
			bool flag = false;

			vector<pair<int,int>> direc = {{1,0}, {-1,0}, {0,1}, {0,-1}};
			
			for (auto p : direc) {
				int x = node.x + p.first;
				int y = node.y + p.second;
				if (x >= 0 && x < 3 && y >= 0 && y < 3) {
					w = checkWeight(x, y, node.x, node.y);
					if (w == 9) {
						result.push_back(node.count + 1);
						flag = true;
						break;
					}
					else pq.push({ y, x, w, node.count + 1 });
				}
				w = 0;
			}
			if (flag == true) break;
		}
	}
	for (int i : result) cout << i << "\n";
}

