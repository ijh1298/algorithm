#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N_MAX 100000
#define M_MAX 1000

int n, k, m;
vector<int> graph[N_MAX	+ M_MAX + 1];
bool visit[N_MAX + 1];

int bfs() {
	queue<pair<int, int>> q; // Pair(역, 깊이)
	visit[1] = true;
	q.push({ 1, 1 });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		
		if (cur.first == n)
			return cur.second;

		for (auto node : graph[cur.first]) {
			if (node < n + 1) { // 역인 경우
				if (visit[node]) 
					continue;
				visit[node] = true;
				q.push({ node, cur.second + 1 });
			}
			else { // 튜브인 경우
				q.push({ node, cur.second });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k >> m;

	for (int i = 1; i <= m; i++) {
		vector<int> input;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			input.push_back(x);
		}

		for (auto a : input) { // 역, 튜브 연결
			graph[n + i].push_back(a);
			graph[a].push_back(n + i);
		}
	}

	cout << bfs();

	return 0;
}