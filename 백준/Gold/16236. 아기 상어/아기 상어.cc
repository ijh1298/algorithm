/*
BFS 개념에 *우선 순위*가 더해져서 어려웠던 문제

가장 위, 가장 왼쪽에 있는 것을 먼저 먹는다고 하여 
단순히 '위, 왼쪽을 먼저 방문하는 BFS를 쓰면 되겠다'는 생각이 틀림.
(방문 순서가 그렇다 하더라도 가장 위, 가장 왼쪽이라는 것을 보장할 수 없다.)

(중요) C++ 라이브러리 우선 순위 큐를 쓸 때, 
우선 순위 큐를 정렬하는 operator를 쓰는 법 익히기
*/

#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int x, y, d, size, stack;
	//거리가 제일 작은 순, 
	//거리가 같다면 x가 제일 작은 순(가장 위),
	//x가 같다면 y가 제일 작은 순(가장 왼쪽)으로 정렬
	bool operator<(const Node& other) const {
		if (d != other.d)
			return d > other.d;
		if (x != other.x)
			return x > other.x;
		return y > other.y;
	}
};

priority_queue<Node> q;
int N;
int sum = 0;
int map[21][21];
bool v[21][21];

int bfs() {
	while (!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		int d = q.top().d;
		int size = q.top().size;
		int stack = q.top().stack;
		q.pop();

		//자기 보다 작은 물고기를 먹는 경우
		if (map[x][y] > 0 && map[x][y] < size) {
			map[x][y] = 0;
			++stack;

			//숫자만큼 먹으면 크기를 올려주기
			if (stack == size) {
				stack = 0;
				++size;
			}

			//d : 먹이까지 최단 거리
			sum += d;

			//좌표 저장 및 방문 테이블 초기화
			while (!q.empty())
				q.pop();
			q.push({ x, y, 0, size, stack });
			fill(v[0], v[20], false);

			return 1;
		}

		//BFS
		if (x - 1 >= 0 && map[x - 1][y] <= size && !v[x - 1][y]) {
			v[x - 1][y] = true;
			q.push({ x - 1, y, d + 1, size, stack });
		}

		if (y - 1 >= 0 && map[x][y - 1] <= size && !v[x][y - 1]) {
			v[x][y - 1] = true;
			q.push({ x, y - 1, d + 1, size, stack });
		}

		if (y + 1 < N && map[x][y + 1] <= size && !v[x][y + 1]) {
			v[x][y + 1] = true;
			q.push({ x, y + 1, d + 1, size, stack });
		}

		if (x + 1 < N && map[x + 1][y] <= size && !v[x + 1][y]) {
			v[x + 1][y] = true;
			q.push({ x + 1, y, d + 1, size, stack });
		}
	}

	return 0;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];

			//시작 위치
			if (map[i][j] == 9) {
				map[i][j] = 0;
				q.push({ i, j, 0, 2, 0 });
				v[i][j] = true;
			}
		}

	while (bfs());

	cout << sum;

	return 0;
}