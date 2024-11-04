#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

priority_queue<pair<int, int>> pq;
set<int> numSet;
vector<int> num;
bool cutIdx[1000001] = {};

int N, K;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		numSet.emplace(x); // 중복 제거 및 순서 정렬을 위한 set
	}

	for (auto e : numSet)
		num.emplace_back(e); // vector 사용

	if (num.empty()) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i < num.size(); i++)
		pq.emplace(num[i] - num[i - 1], i); // (앞 idx와의 차이, 현재 idx)

	for (int i = 0; i < K - 1; i++) {
		if (!pq.empty()) {
			cutIdx[pq.top().second] = true; // 그리디로 자를 idx 결정
			pq.pop();
		}
	}

	int total = 0;
	int start = 0;
	int size = num.size();
	for (int i = 0; i < size; i++) {
		if (start == 0)
			start = num[i];
		if (cutIdx[i + 1] == true || i == size - 1) {
			total += num[i] - start;
			start = 0;
		}
	}

	cout << total;

	return 0;
}