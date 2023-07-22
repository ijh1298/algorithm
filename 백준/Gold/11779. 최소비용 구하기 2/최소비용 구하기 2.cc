#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<pair<int, int>> g[1001];
int d[1001];
int parent[1001] = {};
stack<int> path;

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

	while (!pq.empty()) {
		int curDist = -pq.top().first;
		int curNum = pq.top().second;
		pq.pop();

        //*****이전 다익스트라 문제들에도 잘못 적음*****//
        //curDist < d[curNum] (이전 문제들에 순서 바꿔서 적음)
        //맞는 표기 : d[curNum] < curDist
        //거리 테이블이 이미 작으면 갱신할 필요없이 넘겨야 시간 복잡도 줄일 수 있음
        //시간 초과 원인
 		if (d[curNum] < curDist)
			continue;
		
		for (int i = 0; i < g[curNum].size(); ++i) {
			int nextDist = curDist + g[curNum][i].first;
			int nextNum = g[curNum][i].second;

			while (nextDist < d[nextNum]) {
				d[nextNum] = nextDist;
				//최단 거리가 갱신 될 때마다 이전 경로를 저장
				parent[nextNum] = curNum;
				pq.push({ -nextDist, nextNum });
			}
		}
	}
}

//end부터 시작하여 start까지 이전 길(parent) 경로를 stack에 담기
void createPath(int start, int end) {
	int p = end;

	path.push(p);
	while (p != start) {
		path.push(parent[p]);
		p = parent[p];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int	V, E;
	cin >> V >> E;

	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		//단방향 그래프
		g[u].push_back({ w, v });
	}

	int start, end;
	cin >> start >> end;
	
	dInit(V);
	dijkstra(start, end);
	createPath(start, end);

	//start - end 최단 거리
	cout << d[end] << '\n';
	//거치는 경로의 개수(stack의 size)
	cout << path.size() << '\n';
	//경로 : stack 끝까지 pop
	while (!path.empty()) {
		cout << path.top() << ' ';
		path.pop();
	}

	return 0;
}