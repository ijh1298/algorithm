// 플로이드 워셜 알고리즘
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
int d[101][101] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	// 거리 테이블 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = 1e9;
		}
	}

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		d[u][v] = 1;
		d[v][u] = 1;
	}

	// 플로이드 워셜 구현
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	int cnt[101] = { 0 };

	// 케빈 베이컨 수 구하기
	// 플로이드 워셜 테이블에서, 다른 노드까지의 합이 제일 작은 인덱스 구하기
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (d[i][j] != 1e9)
				cnt[i] += d[i][j];

	int min = 1e9, minId = 1;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] < min) {
			min = cnt[i];
			minId = i;
		}
	}

	cout << minId;

	return 0;
}