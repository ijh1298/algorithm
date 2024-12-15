#include <iostream>
#include <algorithm>
using namespace std;

#define EMPTY '.'
char matrix[1501][1501];
int N, mostTop, mostBottom, mostLeft, mostRight, cnt = 0;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];
}

void analyze() {
	mostTop = N - 1, mostBottom = 0, mostLeft = N - 1, mostRight = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == 'G') {
				mostTop = min(mostTop, i);
				mostBottom = max(mostBottom, i);
				mostLeft = min(mostLeft, j);
				mostRight = max(mostRight, j);
			}
		}
}

void solve() {
	analyze();
	if (mostTop != mostBottom)
		cnt += min(N - 1 - mostTop, mostBottom);
	if (mostLeft != mostRight)
		cnt += min(N - 1 - mostLeft, mostRight);

	cout << cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	input();
	solve();

	return 0;
}