#include<iostream>
#include<vector>
#include<queue>
#include<string>
#define SWAP(a, b) {int temp = a; a = b; b = temp;}

using namespace std;

vector<vector<int>> board(3, vector<int>(3));
vector<vector<int>> const answer = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } };

struct Node {
	vector<vector<int>> curBoard;
	int moveCount;
	int x;
	int y;
	int weight;
	bool operator<(const Node& other) const {
		
	}
};

struct Fx {

	
};

int checkWeight(vector<vector<int>> board) {
	int flag = 9;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != answer[i][j]) flag--;
		}
	}
	return flag;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> result; // 결과 저장용 배열
	vector<int> check; // 불가능 판별용 배열

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
				check.push_back(board[i][j]);
			}
		}
		/////// 가능 불가능 판별
		int sum = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = i + 1; i < 9; i++) {
				if (check[j] > check[i]) sum++;
			}
			if (sum % 2 == 1) {
				result.push_back(-1);
				break;
			}
		}
		///////
		priority_queue<Node> pq;
		priority_queue<int> fx;

		pq.push({ board, 0, start.second, start.first, checkWeight(board) });

		while (!pq.empty()) {
			auto node = pq.top(); pq.pop();

			vector<pair<int, int>> direc = { {1,0}, {-1,0}, {0,1}, {0,-1} };

			for (auto p : direc) {
				int x = node.x + p.first;
				int y = node.y + p.second;
				if (x >= 0 && x < 3 && y >= 0 && y < 3) {
					SWAP(node.curBoard[y][x], node.curBoard[node.y][node.x]);
					pq.push({ node.curBoard, node.moveCount + 1, x, y, checkWeight(node.curBoard) });
				}
			}
		}
		

}

