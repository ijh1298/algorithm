#include <iostream>
#include <vector>

std::vector<int> g[101];
bool v[101];
int ans = 0;

void dfs(int y, int cur, int depth) {
	if (cur == y) {
		ans = depth;
		return;
	}
	for (int i = 0; i < g[cur].size(); ++i) {
		if (!v[g[cur][i]]) {
			v[g[cur][i]] = true;
			dfs(y, g[cur][i], depth + 1);
			v[g[cur][i]] = false;
		}
	}
}

int main() {
	int N, x, y, E;
	std::cin >> N >> x >> y >> E;

	while (E--) {
		int u, v;
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(y, x, 0);
	int d = ans;
	d ? std::cout << d : std::cout << -1;

	return 0;
}