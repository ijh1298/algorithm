#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> arr;
int dp[100] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int u, v;
	for (int i = 0; i < N; i++) {
		cin >> u >> v;
		arr.push_back({ u, v });
	}

	// 전깃줄을 A 기준으로 정렬
	sort(arr.begin(), arr.end());

	// DP 테이블 초기화
	fill(dp, dp + 100, 1);

	int max = -1;
	// A 기준으로 정렬된 상태에서 B의 오름차순이 최장 상태가 되는 값을 구하기 (DP)
	// B로 가는 전깃줄이 오름차순이라면 엉키지 않기 때문
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i].second > arr[j].second && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				if (dp[i] > max)
					max = dp[i];
			}
		}
	}

	cout << N - max;

	return 0;
}