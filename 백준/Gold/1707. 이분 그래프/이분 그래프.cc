// 이분 그래프 알고리즘 숙지 (진입하면서 RED, BLUE 색 구분)
#include <iostream>
#include <vector>
using namespace std;

bool flag;
int color[20001];
vector<int> graph[20001];

// 이분 그래프 판별 DFS
void dfs(int start) {
	for (auto e : graph[start]) {
		if (color[e] == 0) { // 진입하는 지점은 이전 지점과 다른 색으로 설정
			int thisColor;
			if (color[start] == 1)
				thisColor = 2;
			else
				thisColor = 1;

			color[e] = thisColor;
			dfs(e);
		}
		else if (color[start] == color[e]) {
			flag = false;
			return;
		}
	}
}

// 변수 초기화
void init(int v) {
	flag = true;
	for (int i = 0; i <= v; i++) {
		color[i] = 0;
		graph[i].clear();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		int V, E;
		cin >> V >> E;
		init(V);

		int u, v;
		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			graph[u].emplace_back(v);
			graph[v].emplace_back(u);
		}

		for (int i = 1; i <= V; i++) {
			if (color[i] == 0) { // 방문하지 않은 정점의 색을 1로 두고 DFS 시작
				color[i] = 1;
				dfs(i);
			}
		}

		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}