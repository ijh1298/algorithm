#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001
int N;
int done[MAX];
bool visit[MAX];
vector<int> graph[MAX];
vector<int> route;

int cycleStart = -1;
int cycleEnd = -1;
// 방문한 곳을 다시 방문하면 Cycle 존재 (다시 방문하게 되는 지점이 Cycle의 시작점)
// route 중 cycleStart부터 route의 마지막까지가 하나의 팀이 됨 (단방향 그래프이기 때문)
void dfs(int s) {
	for (auto next : graph[s]) {
		if (!visit[next]) {
			visit[next] = true;
			route.emplace_back(next);
			dfs(next);
			route.pop_back();
			return;
		}
		else {
			cycleStart = next;
			cycleEnd = s;
		}
	}

	// 탐색한 경로 중 사이클이 존재하면
	if (cycleStart != -1) {
		bool isCycle = false;
		for (auto e : route) {
			if (isCycle || e == cycleStart)
				done[e] = 1;
			else
				done[e] = -1;

			if (e == cycleStart)
				isCycle = true;
			if (e == cycleEnd)
				isCycle = false;
		}
	}
	return;
}

void init() {
	fill(visit, visit + MAX, false);
	fill(done, done + MAX, 0);
	for (int i = 1; i < MAX; i++)
		graph[i].clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		// 그래프 생성
		vector<int> edge;
		for (int i = 0; i < N; i++) {
			int x;
			cin >> x;
			edge.emplace_back(x);
		}
		for (int i = 0; i < N; i++) { // 단방향
			graph[i + 1].emplace_back(edge[i]);
		}

		// 사이클 찾아내어 사이클 구간을 한 팀으로 묶기
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				visit[i] = true;
				route.emplace_back(i);
				dfs(i);
				route.clear();
			}
			cycleStart = -1;
			cycleEnd = -1;
		}

		// 출력
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (done[i] != 1)
				ans++;
		}
		cout << ans << '\n';
		init();
	}

	return 0;
}