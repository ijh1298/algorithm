// C++ stl을 더 잘 사용한 방식으로 다익스트라 코드 수정
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K;
	// V 간선 개수
	// E 정점 개수
	// K 시작 노드

	cin >> V >> E >> K;

	vector<vector<pair<int, int>>> list;			// 간선 정보
	vector<bool> visit;								// 방문 테이블
	vector<int> d;									// 거리 테이블

	visit.resize(V + 1);
	std::fill(visit.begin(), visit.end(), false);	// 방문 테이블 초기화
	d.resize(V + 1);
	std::fill(d.begin(), d.end(), INT_MAX);			// 거리 테이블 무한으로 초기화
	list.resize(V + 1);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;		
		list[u].push_back({ v, w }); // list pair : { 다음 노드, 거리 }
	}

	// dijkstra 구현
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// 최소힙

	d[K] = 0;
	pq.push({ 0, K });	// pq pair : { 거리, 다음 노드 }
	
	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();

		int curNum = cur.second;

		if (visit[curNum])
			continue;	// 방문한 적 있으면 skip
		visit[curNum] = true;

		int len = list[curNum].size();
		for (int i = 0; i < len; i++) {
			// list pair : { 다음 노드, 거리 }
			int nextNum = list[curNum][i].first;
			int nextDist = list[curNum][i].second;

			if (d[nextNum] > d[curNum] + nextDist) {
				d[nextNum] = d[curNum] + nextDist;
				pq.push({ d[nextNum], nextNum });
			}
		}
	}

	for (int i = 1; i <= V; i++)
		d[i] == INT_MAX ? cout << "INF\n" : cout << d[i] << '\n';

	return 0;
}