#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1000001
int F, S, G, U, D, ans = 1e9;
bool visit[MAX];
queue<pair<int, int>> q; // <floor, depth>

void bfs() {
	while (!q.empty()) {
		auto [floor, depth] = q.front();
		q.pop();

		if (floor == G)
			ans = min(ans, depth);

		if (floor + U <= F && !visit[floor + U]) {
			visit[floor + U] = true;
			q.emplace(floor + U, depth + 1);
		}

		if (floor - D > 0 && !visit[floor - D]) {
			visit[floor - D] = true;
			q.emplace(floor - D, depth + 1);
		}
	}
}

int main() {
	cin >> F >> S >> G >> U >> D;
	q.emplace(S, 0);
	visit[S] = true;
	bfs();
	if (ans != 1e9)
		cout << ans;
	else
		cout << "use the stairs";

	return 0;
}