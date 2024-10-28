#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

#define MAX 1001
int W, H, ans = 1e9;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int fireMatrix[MAX][MAX];
bool fireVisit[MAX][MAX];

char matrix[MAX][MAX];
bool visit[MAX][MAX];

pair<int, int> start;
queue<pair<int, int>> fire;

void input() {
	cin >> W >> H;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++) {
			cin >> matrix[i][j];

			if (matrix[i][j] == '@')
				start = { i, j };
			else if (matrix[i][j] == '*') {
				fireMatrix[i][j] = 0;
				fireVisit[i][j] = true;
				fire.emplace(i, j);
			}
			else if (matrix[i][j] == '#') // 벽
				fireMatrix[i][j] = -2;
		}
}

// 불이 이동하는 시간 matrix 생성
void bfs_fire() {
	while (!fire.empty()) {
		auto [r, c] = fire.front();
		fire.pop();

		for (int i = 0; i < 4; i++) {
			int nextR = r + dx[i];
			int nextC = c + dy[i];

			if (nextR < 0 || nextR >= H || nextC < 0 || nextC >= W || fireVisit[nextR][nextC] || fireMatrix[nextR][nextC] == -2)
				continue;

			fireVisit[nextR][nextC] = true;
			fireMatrix[nextR][nextC] = fireMatrix[r][c] + 1;
			fire.emplace(nextR, nextC);
		}
	}
}

// 탈출 가능 확인
void bfs_escape() {
	queue<tuple<int, int, int>> q;
	visit[start.first][start.second] = true;
	q.emplace(start.first, start.second, 0);

	while (!q.empty()) {
		auto [r, c, depth] = q.front();
		q.pop();

		if ((r == 0 || r == H - 1 || c == 0 || c == W - 1) && fireMatrix[r][c] != -2 && (fireMatrix[r][c] == -1 || fireMatrix[r][c] > depth)) {
			ans = depth + 1;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nextR = r + dx[i];
			int nextC = c + dy[i];

			if (nextR < 0 || nextR >= H || nextC < 0 || nextC >= W) continue;
			if (visit[nextR][nextC] || matrix[nextR][nextC] == '#') continue;
			if (fireMatrix[nextR][nextC] != -1 && fireMatrix[nextR][nextC] <= depth + 1) continue;

			visit[nextR][nextC] = true;
			q.emplace(nextR, nextC, depth + 1);
		}
	}
}

void init() {
	ans = 1e9;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++) {
			matrix[i][j] = '#';
			fireMatrix[i][j] = -1; // -1 : 이동 가능한 경로
			visit[i][j] = false;
			fireVisit[i][j] = false;
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		init();
		input();
		bfs_fire();
		bfs_escape();
		if (ans == 1e9)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans << '\n';
	}
	return 0;
}
