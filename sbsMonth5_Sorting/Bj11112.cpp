#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_set>
#define SWAP(a, b) {char temp = a; a = b; b = temp;}

using namespace std;

struct Node {
	int now;
	int level;
	int hx;
	string board;
	bool operator<(const Node& other) const {
		return level + hx > other.level + other.hx;
	}
};

int CalWeight(string board) {
	int weight = 9;
	string answer = "12345678#";

	for (int i = 0; i < 9; i++) 
		if (answer[i] == board[i]) weight--;
	
	return weight;
}

int main() {
	int testCase;

	cin >> testCase;

	vector<int> result;

	for (int i = 0; i < testCase; i++) {
		// 판입력받기 
		string board = "";
		unordered_set<string> visited;

		for (int j = 0; j < 3; j++) {
			string s;
			cin >> s;
			board.append(s);
		}

		//역순 계산

		int chk = 0;
		for (int i = 0; i < 8; i++) {
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

		while (!pq.empty()) {
			auto node = pq.top(); pq.pop();

			if (visited.count(node.board)) continue;
			visited.insert(node.board);

			if (node.hx == 0) {
				result.push_back(node.level);
				break;
			}

			int direc[4] = { -3, -1, 1, 3 };
			for (int i : direc) {
				int next = node.now + i;
				
				bool poss = false;

				if (i % 3 == 0) {
					if (next >= 0 && next < 9) poss = true;
				}
				else {
					if (next >= 0 && next < 9 && next / 3 == node.now / 3) poss = true;
				}
					
				if (poss) {
					SWAP(node.board[node.now], node.board[next]);
					pq.push({ next, node.level + 1, CalWeight(node.board), node.board });
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