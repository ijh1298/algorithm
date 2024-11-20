#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visit[50001];
int depth[50001];
int parent[50001];
vector<int> graph[50001];
vector<pair<int, int>> nodePairs;

void input() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		nodePairs.emplace_back(x, y);
	}
}

void dfs_mark_parent(int node) {
	for (auto e : graph[node]) {
		if (!visit[e]) {
			visit[e] = true;
			depth[e] = depth[node] + 1;
			parent[e] = node;
			dfs_mark_parent(e);
		}
	}
}

// 두 노드의 LCA 출력
void solve(int x, int y) {
	int curX = x;
	int curY = y;

	while (curX != curY) {
		// 깊이가 더 깊은 노드를 올리기
		if (depth[curX] < depth[curY])
			curY = parent[curY];
		else if (depth[curX] > depth[curY])
			curX = parent[curX];
		else {
			curX = parent[curX];
			curY = parent[curY];
		}
	}
	cout << curX << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	visit[1] = true;
	dfs_mark_parent(1);
	for (auto p : nodePairs)
		solve(p.first, p.second);

	return 0;
}