#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> graph[201]; // { w, v }

int dist[201][201];
int route[201][201];

int N, M;
void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = w;
		dist[v][u] = w;
	}
}

void init() {
	for (int i = 0; i < 201; i++)
		for (int j = 0; j < 201; j++) {
			if (i == j) continue;
			dist[i][j] = 1e9;
		}

	for (int i = 1; i < 201; i++)
		for (int j = 1; j < 201; j++) {
			if (i == j) continue;
			route[i][j] = j;
		}
}

// 플로이드 워셜로 다음 경로를 저장
void solve() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					route[i][j] = route[i][k];
				}
			}
		}
	}
}

void output() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) cout << "- ";
			else cout << route[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	init();
	input();
	solve();
	output();

	return 0;
}