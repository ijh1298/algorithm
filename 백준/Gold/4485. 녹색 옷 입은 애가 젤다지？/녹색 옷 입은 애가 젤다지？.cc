#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int N;
int matrix[126][126];
int dist[126][126]; // 최단 거리 배열

void init() {
	for (int i = 0; i < 126; i++)
		for (int j = 0; j < 126; j++) {
			matrix[i][j] = 0;
			dist[i][j] = 1e9;
		}
}

void input() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];
}

void dijkstra() {
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	pq.emplace(matrix[0][0], 0, 0);
	dist[0][0] = matrix[0][0];

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	while (!pq.empty()) {
		auto [curW, curR, curC] = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nextR = curR + dx[i];
			int nextC = curC + dy[i];
			
			if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N)
				continue;

			int nextW = curW + matrix[nextR][nextC];

			if (dist[nextR][nextC] > nextW) {
				dist[nextR][nextC] = nextW;
				pq.emplace(dist[nextR][nextC], nextR, nextC);
			}
		}
	}
}

void print_result(int idx) {
	cout << "Problem " << idx << ": " << dist[N - 1][N - 1] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int idx = 1;
	while (true) {
		cin >> N;
		if (N == 0) break;

		init();
		input();
		dijkstra();
		print_result(idx++);
	}
	return 0;
}