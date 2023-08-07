#include <iostream>

int R, C, T, puri; 
//puri : 공기청정기 하단의 x 좌표
int map1[51][51], map2[51][51]; 

//cycle 과정
//1. 미세먼지 확산
//2. 순환
void cycle();
void spread();
void circulate_up(int p_u);
void circulate_down(int p_d);
void mapReload();

void cycle() {
	//공기청정기의 위, 아래 x 좌표 저장
	int puri_up, puri_down;
	puri_up = puri_down = puri;
	--puri_up;

	map2[puri_up][0] = -1;
	map2[puri_down][0] = -1;
	//1. 미세먼지 확산
	spread();

	//2. 순환
 
	//상단 순환
	circulate_up(puri_up);
	//하단 순환
	circulate_down(puri_down);

	mapReload();
}

void spread() {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			//확산되는 방향의 개수
			int dir = 0;

			if (map1[i][j] == -1)
				continue;

			//차례대로 상좌우하 확산
			if (i - 1 >= 0 && map1[i - 1][j] != -1) {
				++dir;
				map2[i - 1][j] += map1[i][j] / 5;
			}
			if (j - 1 >= 0 && map1[i][j - 1] != -1) {
				++dir;
				map2[i][j - 1] += map1[i][j] / 5;
			}
			if (j + 1 < C && map1[i][j + 1] != -1) {
				++dir;
				map2[i][j + 1] += map1[i][j] / 5;
			}
			if (i + 1 < R && map1[i + 1][j] != -1) {
				++dir;
				map2[i + 1][j] += map1[i][j] / 5;
			}

			map2[i][j] += map1[i][j] - map1[i][j] / 5 * dir;
		}
	}
}

void circulate_up(int p_u) {
	for (int i = p_u; i > 0; --i)
		map2[i][0] = map2[i - 1][0];
	map2[p_u][0] = -1;

	for (int i = 0; i < C - 1; ++i)
		map2[0][i] = map2[0][i + 1];

	for (int i = 0; i < p_u; ++i)
		map2[i][C - 1] = map2[i + 1][C - 1];

	for (int i = C - 1; i > 1; --i)
		map2[p_u][i] = map2[p_u][i - 1];
	map2[p_u][1] = 0;
}

void circulate_down(int p_d) {
	for (int i = p_d; i < R - 1; ++i)
		map2[i][0] = map2[i + 1][0];
	map2[p_d][0] = -1;

	for (int i = 0; i < C - 1; ++i)
		map2[R - 1][i] = map2[R - 1][i + 1];

	for (int i = R - 1; i > p_d; --i)
		map2[i][C - 1] = map2[i - 1][C - 1];

	for (int i = C - 1; i > 1; --i)
		map2[p_d][i] = map2[p_d][i - 1];
	map2[p_d][1] = 0;
}

void mapReload() {
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			map1[i][j] = map2[i][j];
			map2[i][j] = 0;
		}
}

int main() {
	std::cin >> R >> C >> T;

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			std::cin >> map1[i][j];
			if (map1[i][j] == -1)
				puri = i;
		}

	while(T--)
		cycle();

	int sum = 0;
	for(int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			if (map1[i][j] != -1)
				sum += map1[i][j];
		}
	std::cout << sum;

	return 0;
}