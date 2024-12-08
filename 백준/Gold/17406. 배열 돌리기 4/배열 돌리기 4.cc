#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int ans = 1e9;
int N, M, K;
int matrix[51][51]; // 원본
int copied[51][51]; // 이번 분기에 사용하는 복사본
int rotated[51][51]; // 회전을 위해 임시 사용본
vector<tuple<int, int, int>> order;
vector<tuple<int, int, int>> combination;
bool used[6];

void input();
void rotate(int r, int c, int s);
void overwriteOrigin();
void rotatedToCopied();
void copiedToRotated();
void backtrackOrder();
void getMinValue();

void input() {
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> matrix[i][j];
			copied[i][j] = matrix[i][j];
		}

	int r, c, s;
	for (int i = 0; i < K; i++) {
		cin >> r >> c >> s;
		order.emplace_back(r, c, s);
	}
}

void rotate(int r, int c, int s) {
	while (s >= 1) {
		copiedToRotated();

		for (int i = c - s + 1; i <= c + s; ++i)
			rotated[r - s][i] = copied[r - s][i - 1];

		for (int i = r - s + 1; i <= r + s; ++i)
			rotated[i][c + s] = copied[i - 1][c + s];

		for (int i = c + s - 1; i >= c - s; --i)
			rotated[r + s][i] = copied[r + s][i + 1];

		for (int i = r + s - 1; i >= r - s; --i)
			rotated[i][c - s] = copied[i + 1][c - s];

		rotatedToCopied();
		--s;
	}
}

void overwriteOrigin() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			copied[i][j] = matrix[i][j];
}

void rotatedToCopied() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			copied[i][j] = rotated[i][j];
}

void copiedToRotated() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			rotated[i][j] = copied[i][j];
}

void backtrackOrder() {
	if (combination.size() == K) {
		for (auto com : combination) {
			auto [r, c, s] = com;
			rotate(r, c, s);
		}
		getMinValue();
		overwriteOrigin();
		return;
	}

	for (int i = 0; i < K; i++) {
		if (!used[i]) {
			used[i] = true;
			combination.emplace_back(order[i]);
			backtrackOrder();
			used[i] = false;
			combination.pop_back();
		}
	}
}

void getMinValue() {
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++)
			sum += copied[i][j];
		ans = min(ans, sum);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	input();
	backtrackOrder();
	cout << ans;

	return 0;
}