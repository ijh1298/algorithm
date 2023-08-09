#include <iostream>
#include <queue>

int N, M;
int minimum = 99999999;
bool map[1001][1001] = {};
bool v[1001][1001][2] = {};

struct Node {
	int x, y, depth;
	bool didBreak;
};
std::queue<Node> q;

//BFS Queue에 넣는 조건은 두 가지.
// 
//1. 다음 갈 좌표에 벽이 있고, 아직 한번도 벽을 부수지 않은 상태
//2. 다음 갈 좌표에 벽이 없고, 지금 상태(안 부쉈으면 0, 부쉈으면 1)
// (**벽을 한 번 부쉈는데, 다음 갈 좌표에 벽이 있는 상태는 포함하지 않는다.**)
//
//벽을 부수지 않은 채로 방문한 기록은 v[x][y][0]에 기록
//벽을 부순 채로 방문한 기록은 v[x][y][1]에 기록
//
//도착 했을 때의 최소 깊이를 출력

void bfs() {
	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		int x = cur.x;
		int y = cur.y;
		int d = cur.depth;
		bool dB = cur.didBreak;

		if (x == N - 1 && y == M - 1)
			if (d < minimum)
				minimum = d;

		//상
		if (x - 1 >= 0) {
			//조건 1
			if (map[x - 1][y] == 1 && dB == 0) {
				v[x - 1][y][1] = true;
				q.push({ x - 1, y, d + 1, true });
			}
			//조건 2
			else if (map[x - 1][y] == 0 && !v[x - 1][y][dB]) {
				v[x - 1][y][dB] = true;
				q.push({ x - 1, y, d + 1, dB });
			}
		}
		//하
		if (x + 1 < N) {
			if (map[x + 1][y] == 1 && dB == 0) {
				v[x + 1][y][1] = true;
				q.push({ x + 1, y, d + 1, true });
			}
			else if (map[x + 1][y] == 0 && !v[x + 1][y][dB]) {
				v[x + 1][y][dB] = true;
				q.push({ x + 1, y, d + 1, dB });
			}
		}
		//좌
		if (y - 1 >= 0) {
			if (map[x][y - 1] == 1 && dB == 0) {
				v[x][y - 1][1] = true;
				q.push({ x, y - 1, d + 1, true });
			}
			else if (map[x][y - 1] == 0 && !v[x][y - 1][dB]) {
				v[x][y - 1][dB] = true;
				q.push({ x, y - 1, d + 1, dB });
			}
		}
		//우
		if (y + 1 < M) {
			if (map[x][y + 1] == 1 && dB == 0) {
				v[x][y + 1][1] = true;
				q.push({ x, y + 1, d + 1, true });
			}
			else if (map[x][y + 1] == 0 && !v[x][y + 1][dB]) {
				v[x][y + 1][dB] = true;
				q.push({ x, y + 1, d + 1, dB });
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			char c;
			std::cin >> c;

			if (c == '1')
				map[i][j] = true;
			else
				map[i][j] = false;
		}

	//BFS {x=0, y=0, depth=1, didBreak=false} 처음부터 시작
	v[0][0][0] = true;
	q.push({ 0, 0, 1, false });
	bfs();

	if (minimum == 99999999)
		std::cout << -1;
	else
		std::cout << minimum;

	return 0;
}