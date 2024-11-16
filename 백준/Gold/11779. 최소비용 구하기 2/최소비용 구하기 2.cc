#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, start, goal, dist[1001];
int route_reverse[1001];
vector<pair<int, int>> graph[1001]; // (도착 도시, 가중치)

void init_dist() {
	for (int i = 1; i <= N; i++)
		dist[i] = 1e9;
}

void input() {
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
	}
	cin >> start >> goal;
}

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, start);

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		auto [curDist, curV] = cur;

		if (dist[curV] < curDist) continue;

		for (auto next : graph[curV]) {
			auto [nextV, nextDist] = next;

			if (dist[nextV] > curDist + nextDist) {
				dist[nextV] = curDist + nextDist;
				route_reverse[nextV] = curV;
				pq.emplace(curDist + nextDist, nextV);
			}
		}
	}
}

void output() {
	cout << dist[goal] << '\n';

	vector<int> route; // 경로 출력
	route.push_back(goal);
	int cur = route_reverse[goal];
	while (cur != start) {
		route.push_back(cur);
		cur = route_reverse[cur];
	}
	route.push_back(start);

	cout << route.size() << '\n';
	while (!route.empty()) {
		int cur = route.back();
		route.pop_back();
		cout << cur << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	init_dist();
	dijkstra(start);
	output();

	return 0;
}