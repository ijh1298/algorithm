#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 20
int w, h, ans = 1e9;
int shortestPath[11][11]; // i번 - j번 dirty(0 : cleaner) 간 최단 거리
char matrix[MAX][MAX];
bool visit[MAX][MAX];
bool visitDirty[11];
vector<int> order = { 0 };
vector<pair<int, int>> dirty;

bool input() {
	cin >> w >> h;
	if (w == 0 && h == 0)
		return false;

	pair<int, int> cleaner;
	vector<pair<int, int>> tmp;
	char idx = '1';
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == '*') {
				tmp.emplace_back(i, j);
				matrix[i][j] = idx++;
			}
 			else if (matrix[i][j] == 'o') {
				cleaner = { i, j };
				matrix[i][j] = '0';
			}
		}
	dirty.emplace_back(cleaner); // cleaner : 0
	for (auto d : tmp) {
		dirty.emplace_back(d); // dirty : 1 ~ n
	}
	return true;
}

// 각 dirty 간 shortestPath 구하기
void get_dist(int dirtyNum) {
	queue<tuple<int, int, int>> q;
	visit[dirty[dirtyNum].first][dirty[dirtyNum].second] = true;
	q.emplace(dirty[dirtyNum].first, dirty[dirtyNum].second, 0);
	
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	while (!q.empty()) {
		auto [r, c, depth] = q.front();
		q.pop();

		// dirty 칸이면
		if ('1' <= matrix[r][c] && matrix[r][c] <= '10') {
			shortestPath[dirtyNum][matrix[r][c] - '0'] = depth;
		}

		for (int i = 0; i < 4; i++) {
			int nextR = r + dx[i];
			int nextC = c + dy[i];

			if (nextR < 0 || nextR >= h || nextC < 0 || nextC >= w || visit[nextR][nextC] || matrix[nextR][nextC] == 'x')
				continue;

			visit[nextR][nextC] = true;
			q.emplace(nextR, nextC, depth + 1);
		}
	}
}

// 조합대로 최단 거리 계산
void combine() {
	if (dirty.size() == 1) { // 청소기만 있는 경우
		ans = 0;
		return;
	}

	// 청소기에서 dirty로 가지 못하는 경우 -1 출력
	for (int i = 1; i < dirty.size(); i++) {
		if (shortestPath[0][i] == 0) {
			ans = -1;
			return;
		}
	}

	int dist = 0;
	for (int i = 1; i < order.size(); i++) {
		dist += shortestPath[order[i - 1]][order[i]];
	}
	ans = min(dist, ans);
}

// 백트래킹으로 방문 순서 조합하기
void backtrack() {
	if (order.size() == dirty.size()) {
		combine();
	}

	for (int i = 1; i < dirty.size(); i++) {
		if (!visitDirty[i]) {
			visitDirty[i] = true;
			order.emplace_back(i);

			backtrack();

			visitDirty[i] = false;
			order.pop_back();
		}
	}
}

// 방문 초기화
void init_visit() {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++) {
			visit[i][j] = false;
		}
}

void solve() {
	for (int i = 0; i < dirty.size(); i++) {
		get_dist(i);
		init_visit();
	}
	backtrack();
}

// 전역변수 초기화
void init() {
	ans = 1e9;
	init_visit();

	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			shortestPath[i][j] = false;

	for (int i = 0; i < 11; i++)
		visitDirty[i] = false;

	dirty.clear();
	order.clear();
	order.emplace_back(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> test;
	while (input() == true) {
		solve();
		cout << ans << '\n';
		test.emplace_back(ans);
		init();
	}
	return 0;
}