#include <iostream>
#include <queue>
using namespace std;

int T, s, r, c, goalR, goalC;
bool visit[301][301];
int dist[301][301];

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void find() {
	int ans = 0;
	queue<pair<int, int>> q;
	visit[r][c] = true;
	q.emplace(r, c);

	while (!q.empty()) {
		auto [curR, curC] = q.front();
		q.pop();

		if (curR == goalR && curC == goalC)
			return;

		for (int i = 0; i < 8; i++) {
			int nextR = curR + dx[i];
			int nextC = curC + dy[i];

			if (nextR < 0 || nextR >= s || nextC < 0 || nextC >= s || visit[nextR][nextC])
				continue;

			visit[nextR][nextC] = true;
			dist[nextR][nextC] = dist[curR][curC] + 1;
			q.emplace(nextR, nextC);
		}
	}
}

void init() {
	for (int i = 0; i < 301; i++)
		for (int j = 0; j < 301; j++) {
			visit[i][j] = 0;
			dist[i][j] = 0;
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		init();
		cin >> s >> r >> c >> goalR >> goalC;
		find();
		cout << dist[goalR][goalC] << '\n';
	}

	return 0;
}