#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
bool usedCol[15];
vector<pair<int, int>> queenPos;
int queenAmount = 0;

void nQueen(int n, int row) {
	// 증가 조건 : 퀸이 N개 놓였을 때
	if (queenAmount == n) {
		ans++;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		// 현재 열에 퀸이 있으면 skip
		if (usedCol[i]) continue;

		// 현재까지 놓여진 퀸과 대각선이 겹치는지 체크
		bool isOk = true;
		for (auto& q : queenPos) {
			if (abs(q.first - row) == abs(q.second - i)) {
				isOk = false;
				break;
			}
		}

		// Backtracking
		if (isOk) {
			usedCol[i] = true;
			queenPos.push_back({ row, i });
			queenAmount++;

			nQueen(n, row + 1);

			usedCol[i] = false;
			queenPos.pop_back();
			queenAmount--;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	nQueen(n, 0);
	cout << ans;

	return 0;
}