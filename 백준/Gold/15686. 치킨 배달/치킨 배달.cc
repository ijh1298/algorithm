/*
BFS 개념은 익숙했으나, 브루트포스에서 치킨집을 정하는 방법에 애먹은 문제.
치킨집을 정하는 숫자가 정해져 있으면 쉽지만, M(1<=M<=13)으로 정해지면 중첩 반복문을 쓸 수 없음.
Iterator를 쓰는 방법도 생각해보았으나, 재귀 함수로 구현하는 게 더 쉽다고 생각

1. 집과 치킨집 좌표를 vector로 받아둔다.
2. 재귀 함수로 치킨집을 선택한다. (e.g. M == 4 일 때, 123, 124, 134 번째 치킨집을 택하도록)
3. 각 거리를 더한 sum 중 최소값을 구한다.

***시간 초과가 나길래 생각해보니 BFS를 쓸 필요가 없었다. 정해진 거리를 빼주면 됨***
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int x, y, w, depth;
};

#define minimum 99999999
int MIN = minimum;

int map[51][51];
bool v[51][51];
queue<Node> q;
//C : 모든 치킨집
vector<pair<int, int>> C;
//using C : 치킨집 중에 매 브루트포스에 사용하는 치킨집
vector<pair<int, int>> usingC;
vector<pair<int, int>> H;

void bruteforce(int limit, int M, int prev);
int dist(int N);

int dist(int N) {
	int min = minimum;

	Node cur = q.front();
	int x = cur.x;
	int y = cur.y;
	q.pop();

	int sum = 0;
	for (int i = 0; i < usingC.size(); ++i) {
		sum += abs(usingC[i].first - x);
		sum += abs(usingC[i].second - y);

		if (sum < min)
			min = sum;
		sum = 0;
	}

	//집과 치킨집 사이 최단 거리를 return
	return min;
}

void bruteforce(int N, int M, int prev) {
	for (int i = prev + 1; i < C.size(); ++i) {
		map[C[i].first][C[i].second] = 2;
		usingC.push_back({ C[i].first, C[i].second });

		if (M > 1)
			bruteforce(N, M - 1, i);

		if (M == 1) {
			int sum = 0;
			//집 좌표를 하나씩 q에 넣어 최단 거리를 구해 sum에 더함
			for (int j = 0; j < H.size(); ++j) {
				q.push({ H[j].first, H[j].second, 1, 0 });
				sum += dist(N);

				//visit 테이블 초기화
				fill(v[0], v[50], false);
			}
			//모든 경우의 수 중에 가장 최단 거리 합을 선별
			if (sum < MIN)
				MIN = sum;
		}

		//선택된 치킨집을 다시 해제
		map[C[i].first][C[i].second] = 0;
		usingC.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for(int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			int input;
			cin >> input;
			map[i][j] = input;

			//집은 1로 입력을 받아두고, 벡터 H에 집 좌표를 저장해둠
			if (input == 1)
				H.push_back({ i, j });

			//치킨집은 0으로 입력을 받아두고, 벡터 C에 치킨집 좌표를 저장해둠
			//매 브루트포스마다 치킨집을 쓸지 안쓸지 정하기 때문
			if (input == 2) {
				map[i][j] = 0;
				C.push_back({ i, j });
			}
		}

	//브루트포스 재귀함수로 구현
	bruteforce(N, M, -1);

	cout << MIN;

	return 0;
}