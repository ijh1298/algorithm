// 세그먼트 트리 : 갤탭 노트 참조
#include <iostream>
#include <vector>

using namespace std;
vector<long long> tree = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	// 트리 시작 index 구하기
	// 2^k >= n (입력 개수) 구하는 과정
	int exp = 1, start = 1;
	for (int i = 2; i < N; i *= 2)
		exp++;
	for (int i = 0; i < exp; i++)
		start *= 2;

	tree.resize(start * 2);

	// 입력
	for (int i = 0; i < N; i++) {
		long long x;
		cin >> x;
		tree[start + i] = x;
	}

	// 세그먼트 트리 초기화
	for (int i = start * 2 - 1; i > 1; i--)
		tree[i / 2] += tree[i];

	// 데이터 변경, 구간 합 출력 구현
	for (int i = 0; i < M + K; i++) {
		int a, b;
		long long c, ans = 0;
		cin >> a >> b >> c;

		// 데이터 변경
		if (a == 1) {
			int temp = start + b - 1;
			tree[temp] = c;

			// 부모로 올라가면서 바뀐 값에따라 트리 값 재조정
			while (temp != 0) {
				if (temp % 2 == 0)	// 왼쪽 노드
					tree[temp / 2] = tree[temp] + tree[temp + 1];
				else				// 오른쪽 노드
					tree[temp / 2] = tree[temp] + tree[temp - 1];
				temp /= 2;
			}
		}
		// 구간 합 출력
		else if (a == 2) {
			int s = start + b - 1;	// 인덱스 조정
			long long e = start + c - 1;

			int topS = s, topE = e;
			while (s <= e) {
				if (s % 2 == 1)				// s가 오른쪽 노드면
					ans += tree[s];			// 독립 노드로 취급
				s = (s + 1) / 2;

				if (e % 2 == 0)				// e가 왼쪽 노드면
					ans += tree[e];			// 독립 노드로 취급
				e = (e - 1) / 2;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}