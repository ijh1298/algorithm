#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int m[101][101] = {};
	int msum[101];

	std::fill(m[0], m[100], 999999);

	int N, M;
	std::cin >> N >> M;

	//자신과의 거리는 0
	for (int i = 0; i <= N; ++i)
		m[i][i] = 0;

	for (int i = 0; i < M; ++i) {
		int u, v;
		std::cin >> u >> v;

		//양방향
		m[u][v] = 1;
		m[v][u] = 1;
	}

	//플로이드-워셜 알고리즘
	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				if (m[i][k] + m[k][j] < m[i][j])
					m[i][j] = m[i][k] + m[k][j];

	int min = 999999, index = 0;

	//msum[i] == (i번째 유저) ~ (모든 다른 사람들 간의 거리) 총합
	//플로이드-워셜로 만든 거리 테이블을 합하여 총합 거리가 제일 짧은 사람을 찾기
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			msum[i] += m[i][j];

		if (msum[i] < min) {
			min = msum[i];
			index = i;
		}
	}

	std::cout << index;

	return 0;
}