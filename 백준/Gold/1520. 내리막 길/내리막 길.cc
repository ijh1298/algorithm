#include <iostream>
using namespace std;

int M, N;
int ans = 0;
int matrix[501][501];
int visit[501][501];

// DP + DFS 풀이
int dfs(int row, int col) {
	if (row == M - 1 && col == N - 1) {
		ans++;
		visit[row][col]++;
		return visit[row][col];
	}
	int way = 0;
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	for (int i = 0; i < 4; i++) {
		int nextRow = row + dx[i];
		int nextCol = col + dy[i];

		if (nextRow < 0 || nextRow >= M || nextCol < 0 || nextCol >= N)
			continue;

		// visit의 값은 해당 길로 갔을 때 도달하는 개수
		if (matrix[nextRow][nextCol] < matrix[row][col] && visit[nextRow][nextCol] != 0) {
			// 1 이상의 길은 DFS를 들어가지 않고, visit[cur] += visit[next] (DP)
			if (visit[nextRow][nextCol] > 0) {
				ans += visit[nextRow][nextCol];
				way += visit[nextRow][nextCol];
			}
			// -1 길은 방문하지 않은 곳이므로 DFS
			else {
				visit[nextRow][nextCol] = 0;
				way += dfs(nextRow, nextCol);
			}
		}
	}
	// visit[cur] += visit[next] 갱신
	if (way > 0)
		visit[row][col] += way;
	return visit[row][col];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	// 입력
	for (int i = 0; i < M ; i++)
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			matrix[i][j] = input;
		}
	// 방문 배열 초기화
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = -1;
	// DFS
	visit[0][0] = 0;
	dfs(0, 0);
	cout << ans;

	return 0;
}