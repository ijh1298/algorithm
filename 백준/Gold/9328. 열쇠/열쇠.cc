#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool key[26]; // 열쇠 유무
bool visit[101][101];
int T, r, c, ans;
char matrix[101][101];
vector<pair<int, int>> start; // 입구

// matrix 초기화
void input() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char x;
			cin >> x;
			matrix[i][j] = x;

			if (matrix[i][j] != '*' && (i == 0 || i == r - 1 || j == 0 || j == c - 1))
				start.emplace_back(i, j);
		}
	}
	string keys;
	cin >> keys;
	if (keys == "0")
		return;
	for (char k : keys) {
		key[k - 'a'] = true;
	}
}

// 방문 초기화
void init_visit() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			visit[i][j] = false;
		}
}

void bfs() {
	queue<pair<int, int>> q;
	for (auto s : start) { // 큐에 시작 지점 push
		visit[s.first][s.second] = true;
		q.emplace(s);
	}

	while (!q.empty()) {
		auto [curR, curC] = q.front();
		q.pop();

		char here = matrix[curR][curC];

		if (('A' <= here && here <= 'Z') && !key[here - 'A']) // 열쇠 없으면
			continue;

		if ('a' <= here && here <= 'z') { // ***열쇠면 열쇠 추가하고, 큐 초기화하고, BFS 새로 시작***
			key[here - 'a'] = true;
			matrix[curR][curC] = '.'; // 자리에서 열쇠 제거

			while (!q.empty())
				q.pop();
			init_visit();
			for (auto s : start) {
				visit[s.first][s.second] = true;
				q.emplace(s);
			}

			continue;
		}
		else if (here == '$') {
			ans++;
			matrix[curR][curC] = '.';
		}

		int dx[4] = { -1, 0, 1, 0 };
		int dy[4] = { 0, 1, 0, -1 };

		for (int i = 0; i < 4; i++) {
			int nextR = curR + dx[i];
			int nextC = curC + dy[i];

			if (nextR < 0 || nextR >= r || nextC < 0 || nextC >= c || matrix[nextR][nextC] == '*' || visit[nextR][nextC])
				continue;

			visit[nextR][nextC] = true;
			q.emplace(nextR, nextC);
		}
	}
}

// TC마다 초기화
void init() {
	ans = 0;
	init_visit();
	for (int i = 0; i < 26; i++)
		key[i] = false;
	start.clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> r >> c;
		init();
		input();
		bfs();
		cout << ans << '\n';
	}

	return 0;
}