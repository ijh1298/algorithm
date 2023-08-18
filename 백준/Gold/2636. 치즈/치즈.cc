//2638번 치즈 문제에서, 치즈 녹이기 조건(공기 면과 맞닿는 개수)과 마지막 치즈 개수 출력만 추가
#include <iostream>
#include <queue>

std::queue<std::pair<int, int>> q;
int N, M;
bool v[101][101] = {};

//외부 벽을 type = 2로 설정
void makeWall(int** map1, int** map2) {
	for (int i = 0; i < N + 2; ++i) {
		map1[i][0] = 2;
		map1[i][M - 1] = 2;
		map2[i][0] = 2;
		map2[i][M - 1] = 2;
	}
	for (int i = 0; i < M + 2; ++i) {
		map1[0][i] = 2;
		map1[N - 1][i] = 2;
		map2[0][i] = 2;
		map2[N - 1][i] = 2;
	}
}
//외부 공기를 type = 5로 설정
void dfs(int** map, int x, int y) {
	v[x][y] = true;

	if (x + 1 < N + 1 && !v[x + 1][y] && map[x + 1][y] != 1) {
		if (map[x + 1][y] == 2 || map[x + 1][y] == 5)
			dfs(map, x + 1, y);
		else if (map[x + 1][y] == 0) {
			map[x + 1][y] = 5;
			dfs(map, x + 1, y);
		}
	}
	if (y + 1 < M + 1 && !v[x][y + 1] && map[x][y + 1] != 1) {
		if (map[x][y + 1] == 2 || map[x][y + 1] == 5)
			dfs(map, x, y + 1);
		else if (map[x][y + 1] == 0) {
			map[x][y + 1] = 5;
			dfs(map, x, y + 1);
		}
	}
	if (x - 1 >= 0 && !v[x - 1][y] && map[x - 1][y] != 1) {
		if (map[x - 1][y] == 2)
			dfs(map, x - 1, y);
		else if (map[x - 1][y] == 0 || map[x - 1][y] == 5) {
			map[x - 1][y] = 5;
			dfs(map, x - 1, y);
		}
	}
	if (y - 1 >= 0 && !v[x][y - 1] && map[x][y - 1] != 1) {
		if (map[x][y - 1] == 2 || map[x][y - 1] == 5)
			dfs(map, x, y - 1);
		else if (map[x][y - 1] == 0) {
			map[x][y - 1] = 5;
			dfs(map, x, y - 1);
		}
	}
}
//치즈 녹이기
void bfs(int** mapA, int** mapB) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		v[x][y] = true;

		int sum = 0;
		if (x - 1 >= 0)
			sum += mapA[x - 1][y];
		if (x + 1 < N + 2)
			sum += mapA[x + 1][y];
		if (y - 1 >= 0)
			sum += mapA[x][y - 1];
		if (y + 1 < M + 2)
			sum += mapA[x][y + 1];

		//외부공기 한 개 이상과 맟닿으면 다음 맵에 외부공기로 변화
		if (sum >= 5)
			mapB[x][y] = 5;
	}
}
int isEmpty(int** map) {
	for (int i = 1; i < N + 1; ++i)
		for (int j = 1; j < M + 1; ++j) {
			if (map[i][j] != 5)
				return 0;
		}
	return 1;
}
void mapCopy(int** mapA, int** mapB) {
	for (int i = 1; i < N + 1; ++i)
		for (int j = 1; j < M + 1; ++j) {
			mapA[i][j] = mapB[i][j];
			if (mapA[i][j] == 1) {
				q.push({ i, j });
			}
		}
}
void vInit() {
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			v[i][j] = false;
}

//마지막 치즈 개수 확인
int lastCount(int** map) {
	int cnt = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (map[i][j] == 1)
				cnt++;
	return cnt;
}

int main() {
	std::cin >> N >> M;

	//동적 할당
	int** map1 = new int* [N + 2];
	for (int i = 0; i < N + 2; ++i)
		map1[i] = new int[M + 2];

	int** map2 = new int* [N + 2];
	for (int i = 0; i < N + 2; ++i)
		map2[i] = new int[M + 2];

	//외부 벽 세우기
	makeWall(map1, map2);
	//처음 맵 입력
	for (int i = 1; i < N + 1; ++i)
		for (int j = 1; j < M + 1; ++j) {
			int input;
			std::cin >> input;

			if (input == 0)
				map1[i][j] = 0;
			else if (input == 1) {
				map1[i][j] = 1;
				q.push({ i, j });
			}
		}

	int firstCheeze = lastCount(map1);

	//외부공기 5로 설정
	dfs(map1, 0, 0);
	vInit();
	mapCopy(map2, map1);

	int cnt1 = 0, cnt2 = 0;
	while (!isEmpty(map1)) {
		cnt1++;
		//치즈 녹이고
		bfs(map1, map2);
		vInit();
		//내부공기가 열렸으면 type = 5로 설정
		dfs(map2, 0, 0);
		vInit();
		mapCopy(map1, map2);
		if (lastCount(map2) != 0)
			cnt2 = lastCount(map2);
	}
	
	//1시간 만에 사라질 때 예외처리
	if (cnt1 == 1)
		std::cout << cnt1 << '\n' << firstCheeze << '\n';
	else
		std::cout << cnt1 << '\n' << cnt2 << '\n';

	delete map1;
	delete map2;

	return 0;
}