// 직사각형의 왼쪽 상단을 기준으로 이동
// 도달하고도 matrix 안에 위치하는지 확인
#include <iostream>
#include <queue>
using namespace std;

int N, M, H, W, sr, sc, fr, fc, ans = 1e9;
int matrix[1001][1001];
bool visit[1001][1001];
int dist[1001][1001];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> matrix[i][j];
	cin >> H >> W >> sr >> sc >> fr >> fc;
}

void bfs() {
	queue<pair<int, int>> q;
	visit[sr - 1][sc - 1] = true;
	q.emplace(sr - 1, sc - 1); 

	while (!q.empty()) {
		auto [curR, curC] = q.front(); q.pop();
		
		if (curR == fr - 1 && curC == fc - 1) {
			if (curR + H - 1 < N && curC + W - 1 < M) { // 도착하고도 matrix 내에 위치할 것
				ans = dist[curR][curC];
			}
			return;
		}
		
		for (int i = 0; i < 4; i++) {
			int nextR = curR + dx[i];
			int nextC = curC + dy[i];

			if (visit[nextR][nextC]) continue;
 			bool block = false;

			if (i == 0) { // 상
				if (nextR < 0) continue;
				for (int j = 0; j < W; j++) {
					if (matrix[nextR][curC + j] == 1) {
						block = true;
						break;
					}
				}
			}
			else if (i == 1) { // 우
				if (nextC + W - 1 >= M) continue;
				for (int j = 0; j < H; j++) {
					if (matrix[curR + j][nextC + W - 1] == 1) {
						block = true;
						break;
					}
				}
			}
			else if (i == 2) { // 하
				if (nextR + H - 1 >= N) continue;
				for (int j = 0; j < W; j++) {
					if (matrix[nextR + H - 1][curC + j] == 1) {
						block = true;
						break;
					}
				}
			}
			else { // 좌
				if (nextC < 0) continue;
				for (int j = 0; j < H; j++) {
					if (matrix[curR + j][nextC] == 1) {
						block = true;
						break;
					}
				}
			}

			if (block) continue;
			visit[nextR][nextC] = true;
			dist[nextR][nextC] = dist[curR][curC] + 1;
			q.emplace(nextR, nextC);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	bfs();
	if (ans == 1e9)
		cout << -1;
	else
		cout << ans;

	return 0;
}