#include <iostream>
#include <vector>
#include <tuple>

#define INT_MAX 2000000000

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin >> TC;

	while (TC--) {
		int N, M, W;
		cin >> N >> M >> W;

		vector<tuple<int, int, int>> list;		// tuple 시작, 도착, 거리
		vector<long> d;							// 거리 테이블
		d.resize(N + 1);
		std::fill(d.begin(), d.end(), INT_MAX);

		for (int i = 0; i < M; i++) {			// 도로
			int u, v, w;
			cin >> u >> v >> w;
			list.push_back({ u, v, w });
			list.push_back({ v, u, w });
		}
		for (int i = 0; i < W; i++) {			// 웜홀
			int u, v, w;
			cin >> u >> v >> w;
			list.push_back({ u, v, -w });
		}

		// 벨만 포드 구현
		d[1] = 0;

		for (int i = 1; i < N; i++) {
			for (int j = 0; j < list.size(); j++) {
				tuple<int, int, int> cur = list[j];
				int u = get<0>(cur);
				int v = get<1>(cur);
				int w = get<2>(cur);

				if (d[v] > d[u] + w)
					d[v] = d[u] + w;
			}
		}

		// 음수 사이클 유무 확인
		bool cycle = false;
		for (int i = 0; i < list.size(); i++) {
			tuple<int, int, int> cur = list[i];
			int u = get<0>(cur);
			int v = get<1>(cur);
			int w = get<2>(cur);

			if (d[v] > d[u] + w) {
				cycle = true;
				break;	// 무한 루프 방지
			}
		}

		cycle ? cout << "YES\n" : cout << "NO\n";
	}

	return 0;
}