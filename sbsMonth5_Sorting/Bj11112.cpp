#include<iostream>
#include<vector>
#include<queue>
#define SWAP(a, b) {char temp = a; a = b; b = temp;}

using namespace std;

struct Node {
	int now;
	int level;
	int hx;
	string board;
	bool operator<(const Node& other) const {
		return level + hx < other.level + other.hx;
	}
};

int CalWeight(string board) {
	int weight = 0;
	string answer = "12345678#";

	for (int i = 0; i < 9; i++) 
		if (answer[i] == board[i]) weight++;
	
	return weight;
}

int main() {
	int testCase;

	cin >> testCase;

	vector<int> result;
	vector<string> visited;

	for (int i = 0; i < testCase; i++) {
		// 판입력받기 
		string board = "";

		for (int j = 0; j < 3; j++) {
			string s;
			cin >> s;
			board.append(s);
		}

		//역순 계산

		int chk = 0;
		for (int i = 0; i < 9; i++) {
			if (board[i] == '#') continue;
			for (int j = i + 1; j < 9; j++) {
				if (board[j] == '#') continue;
				else if (board[i] > board[j]) chk++;
			}
		}
		if (chk % 2 != 0) {
			result.push_back(-1);
			continue;
		}

		//

		priority_queue<Node> pq;
		int startP = board.find("#");
		pq.push({ startP, 0, CalWeight(board), board });
		visited.push_back(board);

		while (!pq.empty()) {
			auto node = pq.top(); pq.pop();
			if (node.hx == 9) {
				result.push_back(node.level);
				break;
			}

			for (int i = -3; i <= 3; i = i + 2) {
				int next = node.now + i;
				if (next >= 0 && next <= 9) {
					SWAP(node.board[node.now], node.board[next]);
					if (find(visited.begin(), visited.end(), node.board) != visited.end()) {
						pq.push({ next, node.level + 1, CalWeight(node.board), node.board });
						visited.push_back(node.board);
					}
					SWAP(node.board[node.now], node.board[next]);
				}
			}
		}
	}

	for (int i : result) {
		if (i != -1) cout << i << "\n";
		else cout << "impossible\n";
	}

}