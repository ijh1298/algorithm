#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int N, D;
int d[10001];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

void init_dist() {
	for (int i = 0; i <= D; i++)
		d[i] = i;
}

void adjust_dist() {
	for (int i = 1; i <= D; i++)
		d[i] = min(d[i], d[i - 1] + 1);
}

void find_shortest() {
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int dist = get<1>(cur);
		int from = get<2>(cur);
		int to = get<0>(cur);
		
		d[to] = min(d[to], d[from] + dist);
		adjust_dist();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> D;

	for (int i = 0; i < N; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		pq.emplace(to, dist, from);
	}

	init_dist();
	find_shortest();
	adjust_dist();
	cout << d[D];

	return 0;
}