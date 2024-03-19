#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[301][301] = {};
int after[301][301] = {};
bool v[301][301] = {};
int num = 0;				// 빙산의 개수
int ans = 0;				// 루프 횟수

void DFS(int row, int col) {
	v[row][col] = true;
	if (!v[row - 1][col] && row - 1 > 0 && map[row - 1][col] != 0)
		DFS(row - 1, col);
	if (!v[row + 1][col] && row + 1 <= N && map[row + 1][col] != 0)
		DFS(row + 1, col);
	if (!v[row][col - 1] && col - 1 > 0 && map[row][col - 1] != 0)
		DFS(row, col - 1);
	if (!v[row][col + 1] && col + 1 <= M && map[row][col + 1] != 0)
		DFS(row, col + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	// 입력
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			after[i][j] = map[i][j];
		}

	while (1) {
		// 빙산 녹이기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0) {
					if (i - 1 >= 0 && map[i - 1][j] == 0)
						if (after[i][j] > 0) after[i][j]--;
					if (i + 1 < N && map[i + 1][j] == 0)
						if (after[i][j] > 0) after[i][j]--;
					if (j - 1 >= 0 && map[i][j - 1] == 0)
						if (after[i][j] > 0) after[i][j]--;
					if (j + 1 < M && map[i][j + 1] == 0)
						if (after[i][j] > 0) after[i][j]--;
				}
			}
		}
		ans++;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = after[i][j];
			}
		}
		// 덩어리 확인 (DFS)
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!v[i][j] && map[i][j] != 0) {
					DFS(i, j);
					num++;
				}
			}
		}
		// visit 배열 초기화
		for (int i = 0; i < 301; i++)
			for (int j = 0; j < 301; j++)
				v[i][j] = false;

		if (num != 1) 
			break;
		num = 0;
	}
	num == 0 ? cout << 0 : cout << ans;

	return 0;
}