#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 9999999

vector<pair<int, int>> g[1001];
int d[1001];
int result1[1001];
int result2[1001];

//거리 테이블 초기화
void dInit() {
	for (int i = 0; i < 1001; ++i)
		d[i] = INF;
}

//우선 순위 큐를 이용한 다익스트라
void dijkstra(int start, int end, bool type) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int curDist = -pq.top().first;
		int curNum = pq.top().second;
		pq.pop();
        
        //7.22 수정 : curDist가 더 클 때, 거리 테이블 갱신 하지 않으면 시간 복잡도 감소
	        if (d[curNum] < curDist)
			continue;

		for (int i = 0; i < g[curNum].size(); ++i) {
			int nextDist = curDist + g[curNum][i].first;
			int nextNum = g[curNum][i].second;
			
			while (nextDist < d[nextNum]) {
				d[nextNum] = nextDist;
				pq.push({ -nextDist, nextNum });
				
				if (nextNum == end) {
					// i ~ X 까지 최단 경로 result1에 저장
					if (type == 0)
						result1[start] = nextDist;
					// X ~ i 까지 최단 경로 result2에 저장
					else
						result2[end] = nextDist;
				}
			}
		}
	}
}

int main() {
	//N : vertex, M : edge, X : destination
	int N, M, X;
	cin >> N >> M >> X;

	for (int i = 0; i < M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		//단방향
		g[u].push_back({ w, v });
	}

	//i ~ X 까지 다익스트라
	dInit();
	for (int i = 1; i <= N; ++i) {
		dijkstra(i, X, 0);
		dInit();
	}

	//X ~ i 까지 다익스트라
	for (int i = 1; i <= N; ++i) {
		dijkstra(X, i, 1);
		dInit();
	}
	
	//두 거리 배열을 합하고 최대값 탐색
	int max = 0;
	for (int i = 0; i <= N; ++i) {
		result1[i] += result2[i];
		if (max < result1[i])
			max = result1[i];
	}

	cout << max;

	return 0;
}
