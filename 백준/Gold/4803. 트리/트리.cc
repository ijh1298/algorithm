#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[501];
bool visit[501] = {};
int ans = 0;
bool flag = false;

void dfs(int u, int parent) {
	int len = tree[u].size();

	for (int i = 0; i < len; i++) {
		if (!visit[tree[u][i]]) {
			visit[tree[u][i]] = true;
			dfs(tree[u][i], u);
		}
		// indegree인 노드를 제외한 다른 노드를 방문하는 것은 cycle이 존재한다는 뜻
		else if (visit[tree[u][i]] && tree[u][i] != parent) {
			flag = true;
			return;
		}
	}
}

// 매 케이스마다 초기화
void init(int vertices) {
	ans = 0;
	for (int i = 1; i <= vertices; i++) {
		tree[i].clear();
		visit[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int turn = 1;
	while (1) {
		int vertices, edges;
		cin >> vertices >> edges;

		if (vertices == 0 && edges == 0)
			break;

		int u, v;
		for (int i = 0; i < edges; i++) {
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		
		// DFS로 트리 개수 세기
		for (int i = 1; i <= vertices; i++) {
			if (!visit[i]) {
				visit[i] = true;
				dfs(i, i);
				// Cycle이 존재하지 않으면 트리 개수++
				if (!flag)
					ans++;
				flag = false;
			}
		}

		cout << "Case " << turn << ": ";
		if (ans == 0)
			cout << "No trees.\n";
		else if (ans == 1)
			cout << "There is one tree.\n";
		else
			cout << "A forest of " << ans << " trees.\n";

		init(vertices);
		turn++;
	}

	return 0;
}