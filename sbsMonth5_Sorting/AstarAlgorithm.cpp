#include<iostream>
#include<vector>
#include<queue>
#include<string>
#define SWAP(a, b) {int temp = a; a = b; b = temp;}

using namespace std;

vector<vector<int>> board(3, vector<int>(3));
vector<vector<int>> const answer = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } };
vector<vector<int>> visited;

struct Node {
	vector<vector<int>> curBoard;
	int moveCount;
	int x;
	int y;
	int weight;
	bool operator<(const Node& other) const {
		return moveCount + weight > other.moveCount + other.weight;
	}
};

int checkWeight(vector<vector<int>> board) {
	int flag = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != 0 && board[i][j] != answer[i][j]) flag++;
		}
	}
	return flag;
}

bool isVisited(vector<int> board) {
	for (vector<int> v : visited) {
		if (v == board) return true;
	}
	return false;
}

vector<int> makeArray(vector<vector<int>> board) {
	vector<int> arr;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) arr.push_back(board[i][j]);
	return arr;
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
			if(check[i] != 0)
			{
				for (int j = i + 1; j < 9; j++) {
					if (check[j] < check[i] && check[j] != 0) sum++;
				}
			}
		}
		if (sum % 2 == 1) {
			result.push_back(-1);
			check.clear();
			visited.clear();
			continue;
		}
		///////
		priority_queue<Node> pq;

		pq.push({ board, 0, start.second, start.first, checkWeight(board) });

		while (!pq.empty()) {
			auto node = pq.top(); pq.pop();

			vector<int> arr = makeArray(node.curBoard);
			if (isVisited(arr)) continue;
			visited.push_back(arr);

			if (node.curBoard == answer) {
				result.push_back(node.moveCount);
				break;
			}

			vector<pair<int, int>> direc = { {1,0}, {-1,0}, {0,1}, {0,-1} };

			for (auto p : direc) {
				int x = node.x + p.first;
				int y = node.y + p.second;
				if (x >= 0 && x < 3 && y >= 0 && y < 3) {
					SWAP(node.curBoard[y][x], node.curBoard[node.y][node.x]);
					vector<int> nextArr = makeArray(node.curBoard);
					if (!isVisited(nextArr)) {
						pq.push({ node.curBoard, node.moveCount + 1, x, y, checkWeight(node.curBoard) });
					}
					SWAP(node.curBoard[y][x], node.curBoard[node.y][node.x]);
				}
			}
		}
		check.clear();
		visited.clear();
	}
	for (int i : result) {
		if (i == -1) cout << "impossible\n";
		else cout << i << "\n";
	}
}

