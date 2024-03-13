// Do it! C++ 알고리즘 p.352 : 벨만 포드
// + 출력 초과를 해결하기 위해서 INT_MAX -> LONG_MAX로 수정
#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;						// N 정점 수, M 간선 수
	cin >> N >> M;
	
	vector<long> d;					// 거리 테이블
	vector<tuple<int, int, int>> v;	// 시작 노드, 도착 노드, 가중치를 담는 vector

	d.resize(N + 1);
	std:fill(d.begin(), d.end(), LONG_MAX);

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		v.push_back({ A, B, C });
	}
	
	// 벨만 포드 구현
	// 최단 거리 테이블을 *(N - 1)*번 반복, N번 부터의 반복은 음수 사이클 존재 유무 판단에 이용
	d[1] = 0;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			tuple<int, int, int> cur = v[j];
			int u = get<0>(cur);
			int v = get<1>(cur);
			int w = get<2>(cur);

			// 방문한 적이 없는 노드(d == INF)는 업데이트 하지 않음
			if (d[u] != LONG_MAX && d[v] > d[u] + w)
				d[v] = d[u] + w;	// 더 가까운 최단 거리가 있다면 갱신
		}
	}

	bool cycle = false;
	for (int i = 0; i < M; i++) {	// N번째 반복
		tuple<int, int, int> cur = v[i];
		int u = get<0>(cur);
		int v = get<1>(cur);
		int w = get<2>(cur);

		if (d[u] != LONG_MAX && d[v] > d[u] + w)
			cycle = true;			// 최단 거리가 갱신된다면 음수 사이클 존재
	}

	if (cycle)
		cout << "-1";
	else {
		for (int i = 2; i <= N; i++) {
			if (d[i] == LONG_MAX)
				cout << "-1" << '\n';
			else
				cout << d[i] << '\n';
		}
	}

	return 0;
}