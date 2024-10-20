#include <iostream>
using namespace std;

int ans = 0;
int N, M;
char matrix[1001][1001];
int visit[1001][1001];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			matrix[i][j] = c;
		}
}

// DFS로 방문한 구간을 하나의 Safe Zone으로 취급
void dfs(int r, int c) {
	char cur = matrix[r][c];

	int nextR = r, nextC = c;
	if (cur == 'U')
		--nextR;
	else if (cur == 'R')
		++nextC;
	else if (cur == 'D')
		++nextR;
	else
		--nextC;

	// 다음 구간이 벽이면
	if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M || visit[nextR][nextC] == 1) {
		ans++;
		visit[r][c] = 2;
		return;
	}
	// 다음 구간이 Safe Zone으로 
	if (visit[nextR][nextC] == 2) {
		visit[r][c] = 2;
		return;
	}

	visit[nextR][nextC] = 1; // 단순 방문을 의미
	dfs(nextR, nextC);
	visit[r][c] = 2; // SAFE ZONE으로 가지는 길을 의미
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				visit[i][j] = true;
				dfs(i, j);
			}
		}
	cout << ans;
	return 0;
}