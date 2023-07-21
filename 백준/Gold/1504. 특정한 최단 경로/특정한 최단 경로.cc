#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> g[801];
int d[801];
int shortest;

//거리 테이블 초기화
void dInit(int N) {
	for (int i = 0; i <= N; ++i)
		d[i] = 99999999;
}

//우선 순위 큐를 이용한 다익스트라
void dijkstra(int start, int end) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	shortest = 0;
	while (!pq.empty()) {
		int curDist = -pq.top().first;
		int curNum = pq.top().second;
		pq.pop();

		if (curDist < d[curNum])
			continue;
		
		for (int i = 0; i < g[curNum].size(); ++i) {
			int nextDist = curDist + g[curNum][i].first;
			int nextNum = g[curNum][i].second;

			while (nextDist < d[nextNum]) {
				d[nextNum] = nextDist;
				pq.push({ -nextDist, nextNum });

				if (nextNum == end)
					shortest = nextDist;
			}
		}
	}
}

int run(int V, int v1, int v2, int sum) {
	dInit(V);
	dijkstra(1, v1);
	//출발(1)에서 v1이 자기 자신일 때는 shortest == 0 이지만, 예외 처리
	if (v1 != 1 && !shortest)
		return -1;
	sum += shortest;

	dInit(V);
	dijkstra(v1, v2);
	//최단 거리가 없다면 가는 길이 없는 것이므로 return -1
	if (!shortest)
		return -1;
	sum += shortest;

	dInit(V);
	dijkstra(v2, V);
	//v2에서 V이 자기 자신일 때는 shortest == 0 이지만, 예외 처리
	if (v2 != V && !shortest)
		return -1;
	sum += shortest;

	return sum;
}

int main() {
	int	V, E;
	cin >> V >> E;
	
	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		//무방향 그래프
		g[u].push_back({ w, v });
		g[v].push_back({ w, u });
	}
	
	int v1, v2;
	cin >> v1 >> v2;

	//특정한 최단 경로 문제
	//1번에서 v1, v2를 거치고 N(마지막)으로 도착
	//1. 1 - v1 - v2 - N 순으로 dijkstra
	//2. 1 - v2 - v1 - N 순으로 dijkstra
	//1., 2.를 비교하여 최소값 출력

	int sum1, sum2;
	sum1 = sum2 = 0;

	//1번 과정
	sum1 = run(V, v1, v2, sum1);

	//2번 과정
	sum2 = run(V, v2, v1, sum2);

	//둘 중 최소값 출력
	if (sum1 == -1 && sum2 == -1)
		cout << -1;
	else
		cout << min(sum1, sum2);

	return 0;
}