// Prim 알고리즘으로 MST 구하기
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V, E;
long long ans = 0;
vector<pair<int, int>> tree[10001]; // tree[u].push_back({w, v}) : u-v 노드의 가중치 w를 의미
priority_queue<pair<int, int>> pq;	// pq.push({w, v}) : 현재 MST에서 갈 수 있는 노드 v와 가중치 w
bool visit[10001] = {};

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;

	while (E--) {
		int u, v, w;
		cin >> u >> v >> w;
		tree[u].push_back({ -w, v });
		tree[v].push_back({ -w, u });
	}
	// Prim 알고리즘 구현
	visit[1] = true;
	// 1번 노드에서 갈 수 있는 모든 노드를 pq에 push
	while (!tree[1].empty()) {
		pq.push(tree[1].back());
		tree[1].pop_back();
	}
	while (!pq.empty()) {
		pair<int, int> next = pq.top();
		pq.pop();
		int nextNum = next.second;
		int nextWeight = -next.first;
		// 방문했던 노드라면 생략
		if (visit[nextNum]) 
			continue;
		visit[nextNum] = true;
		ans += nextWeight;
		// 다음 노드에서 갈 수 있는 모든 노드를 pq에 push
		while (!tree[nextNum].empty()) {
			pq.push(tree[nextNum].back());
			tree[nextNum].pop_back();
		}
	}
	cout << ans;
	return 0;
}