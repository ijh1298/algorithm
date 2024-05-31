#include <iostream>
#include <vector>
using namespace std;

int row, col;
int answer = 1e9;
int map[8][8] = {};
int simulation[8][8] = {};
vector<pair<int, int>> cctv; // cctv 위치(x, y)를 담는 벡터

void setUp(int x, int y, bool fill) {
	for (int a = x - 1; a >= 0; a--) {
		if (fill) {
			if (map[a][y] == 6) break;
			else if (map[a][y] == 0) simulation[a][y]++;
		}
		if (!fill) {
			if (map[a][y] == 6) break;
			else if (map[a][y] == 0) simulation[a][y]--;
		}
	}
}
void setDown(int x, int y, bool fill) {	// 하 채우기
	for (int a = x + 1; a < row; a++) {
		if (fill) {
			if (map[a][y] == 6) break;
			else if (map[a][y] == 0) simulation[a][y]++;
		}
		if (!fill) {
			if (map[a][y] == 6) break;
			else if (map[a][y] == 0) simulation[a][y]--;
		}
	}
}
void setLeft(int x, int y, bool fill) {	// 좌 채우기
	for (int a = y - 1; a >= 0; a--) {
		if (fill) {
			if (map[x][a] == 6) break;
			else if (map[x][a] == 0) simulation[x][a]++;
		}
		if (!fill) {
			if (map[x][a] == 6) break;
			else if (map[x][a] == 0) simulation[x][a]--;
		}
	}
}
void setRight(int x, int y, bool fill) {	// 우 채우기
	for (int a = y + 1; a < col; a++) {
		if (fill) {
			if (map[x][a] == 6) break;
			else if (map[x][a] == 0) simulation[x][a]++;
		}
		if (!fill) {
			if (map[x][a] == 6) break;
			else if (map[x][a] == 0) simulation[x][a]--;
		}
	}
}
void backtracking(int cctvNum) {
	if (cctvNum == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (simulation[i][j] == 0)
					cnt++;
			}
		}
		if (cnt < answer) answer = cnt;
		return;
	}

	int x = cctv[cctvNum].first;
	int y = cctv[cctvNum].second;
	int cctvType = map[x][y];

	switch (cctvType) {
	// 1번 cctv의 경우
	case 1: 
		setUp(x, y, 1); backtracking(cctvNum + 1); setUp(x, y, 0);
		setDown(x, y, 1); backtracking(cctvNum + 1); setDown(x, y, 0);
		setLeft(x, y, 1); backtracking(cctvNum + 1); setLeft(x, y, 0);
		setRight(x, y, 1); backtracking(cctvNum + 1); setRight(x, y, 0);
		break;
	case 2:
		setUp(x, y, 1); setDown(x, y, 1);
		backtracking(cctvNum + 1);
		setUp(x, y, 0); setDown(x, y, 0);

		setLeft(x, y, 1); setRight(x, y, 1);
		backtracking(cctvNum + 1);
		setLeft(x, y, 0); setRight(x, y, 0);
		break;
	case 3:
		setUp(x, y, 1); setRight(x, y, 1);
		backtracking(cctvNum + 1);
		setUp(x, y, 0); setRight(x, y, 0);

		setRight(x, y, 1); setDown(x, y, 1);
		backtracking(cctvNum + 1);
		setRight(x, y, 0); setDown(x, y, 0);

		setLeft(x, y, 1); setDown(x, y, 1);
		backtracking(cctvNum + 1);
		setLeft(x, y, 0); setDown(x, y, 0);

		setLeft(x, y, 1); setUp(x, y, 1);
		backtracking(cctvNum + 1);
		setLeft(x, y, 0); setUp(x, y, 0);
		break;
	case 4:
		setUp(x, y, 1); setLeft(x, y, 1); setRight(x, y, 1);
		backtracking(cctvNum + 1);
		setUp(x, y, 0); setLeft(x, y, 0); setRight(x, y, 0);

		setUp(x, y, 1); setDown(x, y, 1); setRight(x, y, 1);
		backtracking(cctvNum + 1);
		setUp(x, y, 0); setDown(x, y, 0); setRight(x, y, 0);

		setUp(x, y, 1); setDown(x, y, 1); setLeft(x, y, 1);
		backtracking(cctvNum + 1);
		setUp(x, y, 0); setDown(x, y, 0); setLeft(x, y, 0);

		setRight(x, y, 1); setDown(x, y, 1); setLeft(x, y, 1);
		backtracking(cctvNum + 1);
		setRight(x, y, 0); setDown(x, y, 0); setLeft(x, y, 0);
		break;
	case 5:
		setRight(x, y, 1); setDown(x, y, 1); setLeft(x, y, 1); setUp(x, y, 1);
		backtracking(cctvNum + 1);
		setRight(x, y, 0); setDown(x, y, 0); setLeft(x, y, 0); setUp(x, y, 0);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> row >> col;
	// input
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			simulation[i][j] = map[i][j];
			if (0 < map[i][j] && map[i][j] < 6) {
				simulation[i][j] = -1e9;	// 벽이나 CCTV인 경우 X로 표기
				cctv.push_back({ i, j });
			}
			if (map[i][j] == 6)
				simulation[i][j] = -1e9;
		}
	}
	if (cctv.size() > 0)
		backtracking(0);
	else {
		answer = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == 0)
					answer++;
			}
		}
	}
	cout << answer;
	return 0;
}