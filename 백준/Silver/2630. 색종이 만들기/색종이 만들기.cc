#include <iostream>

int N;
bool map[129][129];
int blue = 0;
int white = 0;

/*
* 1. N 사이즈의 정사각형이 하나의 색깔을 유지하는지 확인한다. (2중 for문)
* 2. 하나의 색깔로 구성되어 있지 않다면 N / 2로 분할 정복 (반복)
* 3. N 사이즈의 정사각형이 하나의 색깔을 유지한다면, 색깔에 따라 blue++ 또는 white++
*/
void run(int x, int y, int N) {
	bool color = map[x][y];
	
	for(int i = x; i < x + N; ++i)
		for (int j = y; j < y + N; ++j) {
			if (color != map[i][j]) {
				run(x, y, N / 2);
				run(x, y + N / 2, N / 2);
				run(x + N / 2, y, N / 2);
				run(x + N / 2, y + N / 2, N / 2);
				return;
			}
		}

	color ? blue++ : white++;
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			std::cin >> map[i][j];

	run(0, 0, N);

	std::cout << white << '\n' << blue;

	return 0;
}