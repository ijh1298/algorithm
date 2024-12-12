#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int num[10001];
bool visit[10001];
vector<int> ans;
vector<int> graph[10001];

void input() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[v].emplace_back(u);
	}
}

void bfs(int start) {
	queue<int> q;
	q.emplace(start);

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		++num[start];
		
		for (auto e : graph[cur]) {
			if (!visit[e]) {
				visit[e] = true;
				q.emplace(e);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	input();
	for (int i = 1; i <= N; i++) {
		visit[i] = true;
		bfs(i);
		fill(visit, visit + 10001, false);
	}

	int maxNum = 0;
	for (int i = 1; i <= N; i++) {
		maxNum = max(maxNum, num[i]);
	}

	for (int i = 1; i <= N; i++)
		if (num[i] == maxNum) ans.emplace_back(i);

	sort(ans.begin(), ans.end());
	for (auto a : ans)
		cout << a << ' ';

	return 0;
}