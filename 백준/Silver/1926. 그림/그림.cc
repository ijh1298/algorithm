#include <iostream>
#include <queue>
using namespace std;

int n, m, cnt, maxDepth, curDepth;
int matrix[501][501];
bool visit[501][501];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matrix[i][j];
}

void dfs(int r, int c) {
	curDepth++;
	if (curDepth > maxDepth)
		maxDepth = curDepth;

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };

	for (int i = 0; i < 4; i++) {
		int nextR = r + dx[i];
		int nextC = c + dy[i];
			
		if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m || visit[nextR][nextC] || matrix[nextR][nextC] == 0)
			continue;

		visit[nextR][nextC] = true;
		dfs(nextR, nextC);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && matrix[i][j] != 0) {
				cnt++;
				visit[i][j] = true;
				curDepth = 0;
				dfs(i, j);
			}
		}
	if (cnt == 0) maxDepth = 0;
	cout << cnt << '\n' << maxDepth;

	return 0;
}