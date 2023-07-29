#include <iostream>

using namespace std;

int N;
int map[17][17] = {};

struct Node {
	int prev, x, y;
};

/*
* (주의) 벽이 있을 때, 파이프를 밀어서 회전시킨다는 점 때문에
* 이동하고자 하는 위치에만 벽이 있는지 확인하지 말고, 이동할 때 쓰이는 주변 칸도 벽이 있는지 확인해주어야 함
* (map[x][y + 1] != -1 && map[x + 1][y] != -1 && map[x + 1][y + 1] != -1)
*/
void dfs(Node n) {
	int p = n.prev;
	int x = n.x;
	int y = n.y;

	//직전이 가로고, 가로로 이동할 때
	if (p == 0 && y + 1 < N && map[x][y + 1] != -1) {
		map[x][y + 1]++;
		dfs({ 0, x, y + 1 });
	}
	//직전이 가로고, 대각으로 이동할 때
	if (p == 0 && (x + 1 < N && y + 1 < N) && (map[x][y + 1] != -1 && map[x + 1][y] != -1 && map[x + 1][y + 1] != -1)) {
		map[x + 1][y + 1]++;
		dfs({ 2, x + 1, y + 1 });
	}
	//직전이 세로고, 세로로 이동할 때
	if (p == 1 && x + 1 < N && map[x + 1][y] != -1) {
		map[x + 1][y]++;
		dfs({ 1, x + 1, y });
	}
	//직전이 세로고, 대각으로 이동할 때
	if (p == 1 && (x + 1 < N && y + 1 < N) && (map[x][y + 1] != -1 && map[x + 1][y] != -1 && map[x + 1][y + 1] != -1)) {
		map[x + 1][y + 1]++;
		dfs({ 2, x + 1, y + 1 });
	}
	//직전이 대각이고, 가로로 이동할 때
	if (p == 2 && y + 1 < N && map[x][y + 1] != -1) {
		map[x][y + 1]++;
		dfs({ 0, x, y + 1 });
	}
	//직전이 대각이고, 세로로 이동할 때
	if (p == 2 && x + 1 < N && map[x + 1][y] != -1) {
		map[x + 1][y]++;
		dfs({ 1, x + 1, y });
	}
	//직전이 대각이고, 대각으로 이동할 때
	if (p == 2 && (x + 1 < N && y + 1 < N) && (map[x][y + 1] != -1 && map[x + 1][y] != -1 && map[x + 1][y + 1] != -1)) {
		map[x + 1][y + 1]++;
		dfs({ 2, x + 1, y + 1 });
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j])
				map[i][j] = -1;
		}

	Node start;
	//prev는 직전 상태를 가르킴, 0이면 직전이 가로, 1이면 세로, 2면 대각선
	start.prev = 0;
	start.x = 0;
	start.y = 1;

	dfs(start);

	if (map[N - 1][N - 1] == -1)
		cout << 0;
	else
		cout << map[N - 1][N - 1];

	return 0;
}