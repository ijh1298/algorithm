// C++으로 코드 개선
#include <iostream>
#include <queue>

using namespace std;
bool v[100001] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push({ N, 0 });

	// BFS
	while (!q.empty()) {
		pair<int, int> pos = q.front();
		q.pop();

		int curPos = pos.first;
		int curDepth = pos.second;

		if (curPos == K) {
			cout << curDepth;
			break;
		}

		if (2 * curPos < 100001 && !v[2 * curPos]) {
			v[2 * curPos] = true;
			q.push({ 2 * curPos, curDepth });
		}
		if (curPos - 1 >= 0 && !v[curPos - 1]) {
			v[curPos - 1] = true;
			q.push({ curPos - 1, curDepth + 1 });
		}
		if (curPos + 1 < 100001 && !v[curPos + 1]) {
			v[curPos + 1] = true;
			q.push({ curPos + 1, curDepth + 1 });
		}
	}

	return 0;
}