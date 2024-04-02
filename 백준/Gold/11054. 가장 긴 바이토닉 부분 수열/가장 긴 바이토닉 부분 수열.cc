#include <iostream>
using namespace std;
int arr[1001] = {};
int dp1[1001] = {};
int dp2[1001] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	fill(dp1, dp1 + N, 1);
	fill(dp2, dp2 + N, 1);

	int ans = 1;

	// 자기보다 작은 값(arr) 중에 가장 큰 dp 값을 더하기
	for (int i = 1; i < N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j] && dp1[j] + 1 > dp1[i])
				dp1[i] = dp1[j] + 1;
		}
	}
	// 반대 형태로도 dp 진행
	for (int i = N - 2; i >= 0; i--) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] > arr[j] && dp2[j] + 1 > dp2[i])
				dp2[i] = dp2[j] + 1;
		}
	}
	// 오름차순 수열과 내림차순 수열 합치기
	for (int i = 0; i < N; i++) {
		dp1[i] += dp2[i];
		if (ans < dp1[i])
			ans = dp1[i];
	}

	// 중간 지점이 두 번 겹치므로 -1
	cout << ans - 1;

	return 0;
}