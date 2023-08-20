#include <iostream>
#include <vector>

std::vector<int> g[2001];
bool v[2001];
bool ans = false;

void dfs(int cur, int M, int depth) {
	//ABCDE 관계가 되는 조건 == 깊이 4
	if (depth == 4) {
		ans = true;
		return;
	}
	for (int i = 0; i < g[cur].size(); ++i) {
		if (!v[g[cur][i]]) {
			v[g[cur][i]] = true;
			dfs(g[cur][i], M, depth + 1);
			v[g[cur][i]] = false;
		}
	}
}

void vInit(int M) {
	for (int i = 0; i < M; ++i)
		v[i] = false;
}

int main() {
	int N, M;
	std::cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int u, v;
		std::cin >> u >> v;

		//양방향
		g[u].push_back(v);	
		g[v].push_back(u);
	}

	//모든 인원에 대해 체크
	for (int i = 0; i < M; ++i) {
		v[i] = true;
		dfs(i, M, 0);

		if (ans)
			break;

		vInit(M);
	}
	ans == true ? std::cout << 1 : std::cout << 0;

	return 0;
}