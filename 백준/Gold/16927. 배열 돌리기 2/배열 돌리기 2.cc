#include <iostream>
#include <vector>
#include <deque>

//시간 복잡도 개선 방식 참고 : https://www.acmicpc.net/board/view/90534
//직접 값을 돌리면서 저장하고 갱신하니 시간 초과가 나서 다른 방식으로 접근한 코드

//하나의 회전하는 줄을 양방향 큐(deque)로 구현함

//알고리즘
//1. 우선 모든 줄을 분해하여 덱으로 만든 후 lines라는 vector에 push
//2. 각 lines[i]에 회전 횟수(R)만큼 'pop_front, push_back' (회전)
//3. lines를 원래 map에 다시 갖다 붙이고 출력하기

int map[301][301];
std::vector<std::deque<int>> lines;

std::deque<int> save(int x, int y, int N, int M) {
	std::deque<int> d;

	for (int i = y; i < M; ++i)
		d.push_back(map[x][i]);
	for (int j = x + 1; j < N; ++j)
		d.push_back(map[j][M - 1]);
	for (int i = M - 1 - 1; i >= x; --i)
		d.push_back(map[N - 1][i]);
	for (int j = N - 1 - 1; j > y; --j)
		d.push_back(map[j][x]);

	return d;
}

void apply(int num, int x, int y, int N, int M) {
	for (int i = y; i < M; ++i) {
		map[x][i] = lines[num].front();
		lines[num].pop_front();
	}
	for (int j = x + 1; j < N; ++j) {
		map[j][M - 1] = lines[num].front();
		lines[num].pop_front();
	}
	for (int i = M - 1 - 1; i >= x; --i) {
		map[N - 1][i] = lines[num].front();
		lines[num].pop_front();
	}
	for (int j = N - 1 - 1; j > y; --j) {
		map[j][x] = lines[num].front();
		lines[num].pop_front();
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int N, M, R;
	std::cin >> N >> M >> R;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			std::cin >> map[i][j];

	int t = std::min(N, M) / 2 - 1;

	//1.
	for (int i = 0; i <= t; ++i)
		lines.push_back(save(i, i, N - i, M - i));

	//2.
	for (int i = 0; i < lines.size(); ++i)
		for (int j = 0; j < R % lines[i].size(); ++j) {
			// ** R 만큼 회전할 필요가 없음 **
			// R % 선의 길이 만큼 회전해도 된다.
			// * 시간 초과의 주 원인 *
			lines[i].push_back(lines[i].front());
			lines[i].pop_front();
		}

	//3.
	for (int i = 0; i < lines.size(); ++i)
		apply(i, i, i, N - i, M - i);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			std::cout << map[i][j] << ' ';
		std::cout << '\n';
	}

	return 0;
}