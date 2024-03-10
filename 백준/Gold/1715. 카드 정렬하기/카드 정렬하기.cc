// 최초 문제 접근 방식에 문제가 있었다. 참고 : https://www.acmicpc.net/board/view/90899
// 카드 묶음은 합친 이후 갱신되어야 한다.

#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		pq.push(-x); // 최소 힙처럼 사용
	}

	if (N == 1) {
		cout << '0';
		return 0;
	}

	int cnt = 0;
	while (!pq.empty()) {		// 가장 작은 카드 묶음 두 개를 pop해서 합침
		int box = 0;
		box += -pq.top();
		pq.pop();

		if (!pq.empty()) {
			box += -pq.top();
			pq.pop();

			pq.push(-box);		// 합친 카드 묶음을 최소 힙으로 push, 더 최선의 경우가 생기기 때문
			cnt += box;
		}
	}
	cout << cnt;

	return 0;
}