// BOJ 1083 소트 : 문제 핵심은 가장 사전 순으로 크게 정렬하기
// 갈 수 있는 범위(S) 내의 최댓값을 찾아서 내림차순 정렬하기를 반복해야 함
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v;

	int N, x, S;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
	cin >> S;

	int cur = 0;
	while (S > 0) {
		int max, maxId;
		max = maxId = 0;

		for (int i = cur; i <= min(N - 1, cur + S); i++) {
			if (v[i] > max) {
				max = v[i];
				maxId = i;
			}
		}
		if (cur != maxId) { 
			// 범위 내에 다른 최댓값이 있으면 그 값까지 버블 정렬
			for (int i = maxId; i > cur; i--) {
				swap(v[i], v[i - 1]);
			}
			// 정렬 이후에는 사용 가능한 범위를 줄이기
			S -= (maxId - cur);
		}
		cur++;
	}

	int len = v.size();
	for (int i = 0; i < len; i++)
		cout << v[i] << ' ';

	return 0;
}