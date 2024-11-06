#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char matrix[12][6];
bool visit[12][6];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void input() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> matrix[i][j];
}

// 터질 수 있는 것을 탐색
bool bfs(char type, int r, int c) {
	queue<pair<int, int>> q;
	q.emplace(r, c);

	vector<pair<int, int>> route;

	int cnt = 0;
	while (!q.empty()) {
		auto [r, c] = q.front();
		q.pop();
		cnt++;
		route.emplace_back(r, c);

		for (int i = 0; i < 4; i++) {
			int nextR = r + dx[i];
			int nextC = c + dy[i];

			if (nextR < 0 || nextR >= 12 || nextC < 0 || nextC >= 6 || visit[nextR][nextC] || matrix[nextR][nextC] != type)
				continue;

			visit[nextR][nextC] = true;
			q.emplace(nextR, nextC);
		}
	}

	// 터질 수 있으면 X로 교체
	if (cnt >= 4) {
		for (auto pos : route) {
			auto [r, c] = pos;
			matrix[r][c] = 'X';
		}
		return true;
	}
	return false;
}

// 매판 이후 중력, visit 초기화
void afterOneRound() {
	// X가 없을 때까지 내리기
	while (true) {
		bool isX = false;
		for (int i = 11; i > 0; i--)
			for (int j = 0; j < 6; j++)
				if (matrix[i][j] == 'X') {
					isX = true;
					matrix[i][j] = matrix[i - 1][j];
					matrix[i - 1][j] = 'X';
				}
		for (int k = 0; k < 6; k++)
			if (matrix[0][k] == 'X') matrix[0][k] = '.';

		if (!isX)
			break;
	}

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			visit[i][j] = false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	bool isAnyPop = false;

	int ans = 0;
	while (true) {
		// 탐색
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (matrix[i][j] == '.' || visit[i][j])
					continue;

				visit[i][j] = true;
				if (bfs(matrix[i][j], i, j))
					isAnyPop = true;
			}
		}
		if (isAnyPop) { 
			ans++;
			afterOneRound();
			isAnyPop = false;
		}
		else break;
	}
	cout << ans;

	return 0;
}