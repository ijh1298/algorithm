#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, x, y, K;
int dice[4][3]; // 2차원으로 주사위 전개도, top: [1][1], bottom: [3][1]
int map[21][21];
vector<int> moves;

void print_top() {
	cout << dice[1][1] << '\n';
}

void check_bottom() {
	if (map[x][y] == 0) {
		map[x][y] = dice[3][1];
	}
	else {
		dice[3][1] = map[x][y];
		map[x][y] = 0;
	}
}

void move(int dir) {
	int temp = dice[1][1];
	int bottom;
	if (dir == 1) { // 동
		if (y + 1 == M)
			return;
		y++;
		dice[1][1] = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = temp;
	}
	else if (dir == 2) { // 서
		if (y == 0)
			return;
		y--;
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = dice[1][0];
		dice[1][0] = temp;
	}
	else if (dir == 3) { // 북
		if (x == 0)
			return;
		x--;
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = dice[0][1];
		dice[0][1] = temp;
	}
	else { // 남
		if (x + 1 == N)
			return;
		x++;
		dice[1][1] = dice[0][1];
		dice[0][1] = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = temp;
	}
	check_bottom();
	print_top();
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	while (K--) {
		int m;
		cin >> m;
		moves.emplace_back(m);
	}

	for (auto dir : moves) {
		move(dir);
	}
	return 0;
}