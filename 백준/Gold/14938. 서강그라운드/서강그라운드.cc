#include <iostream>

using namespace std;

int item[101];
int d[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, M, E;
	cin >> V >> M >> E;

	for (int i = 1; i <= V; ++i)
		cin >> item[i];

	fill(d[0], d[100], 99999999);

	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		//양방향
		d[u][v] = w;
		d[v][u] = w;
	}

	//플로이드-워셜 알고리즘
	for (int m = 1; m <= V; ++m) {
		for (int i = 1; i <= V; ++i)
			for (int j = 1; j <= V; ++j) {
				if (d[i][m] + d[m][j] < d[i][j])
					d[i][j] = d[i][m] + d[m][j];
				//자기 지역이면 거리 0
				if (i == j)
					d[i][j] = 0;
			}
	}

	int max, sum;
	max = sum = 0;

	/*
	플로이드 - 워셜로 만든 2차원 거리 테이블을 대상으로
	모든 출발 지점(i부터 V까지)에서 수색범위(M)보다 작은 지점(j)이라면
	그 지점(j)의 아이템을 더하여 sum

	각 i의 sum 중에 최대값 출력 하기
	*/
	for (int i = 1; i <= V; ++i) {
		for (int j = 1; j <= V; ++j)
			if (d[i][j] <= M)
				sum += item[j];

		if (sum > max)
			max = sum;
		sum = 0;
	}

	cout << max;

	return 0;
}