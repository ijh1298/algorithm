#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[501];
bool visit[501];

int N, M;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	int u, v;
	while (M--) {
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}

	vector<int> friends;
	for (auto e : graph[1]) {
		visit[e] = true;
		friends.emplace_back(e);
	}

	for (auto f : friends)
		for (auto e : graph[f])
			if (!visit[e]) 
				visit[e] = true;

	int ans = 0;
	for (int i = 2; i <= N; i++) {
		if (visit[i]) ans++;
	}

	cout << ans;

	return 0;
}