#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
bool matrix[101][101];
vector<int> ans;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int cnt = 0;
void dfs(int r, int c) {
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nextR = r + dx[i];
		int nextC = c + dy[i];

		if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M || matrix[nextR][nextC])
			continue;

		matrix[nextR][nextC] = true;
		dfs(nextR, nextC);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> M >> N >> K;

	// input
	while (K--) {
		int fromR, fromC, toR, toC;
		cin >> fromR >> fromC >> toR >> toC;

		for (int i = fromR; i < toR; i++)
			for (int j = fromC; j < toC; j++)
				matrix[i][j] = true;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!matrix[i][j]) {
				matrix[i][j] = true;
				dfs(i, j);
				ans.emplace_back(cnt);
				cnt = 0;
			}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (auto e : ans) {
		cout << e << ' ';
	}

	return 0;
}