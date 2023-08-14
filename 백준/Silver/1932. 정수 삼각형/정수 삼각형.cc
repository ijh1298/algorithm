#include <iostream>
#include <algorithm>
//개념 참고 : https://gaeunhan.tistory.com/67
//일일이 이전 단계 값의 합을 저장해두는 2차원 배열 dp
//모든 값을 지나며 최대값을 갱신함
int dp[501][501] = {};
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, max = 0;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j)
			std::cin >> dp[i][j];

	if (n == 1) {
		std::cout << dp[0][0];
		return 0;
	}

	for(int i = 1; i < n; ++i)
		for (int j = 0; j <= i; ++j) {
			if (j == 0) //좌측인 경우
				dp[i][j] += dp[i - 1][0];
			else if (j == i) //우측인 경우
				dp[i][j] += dp[i - 1][j - 1];
			else
				dp[i][j] = std::max(dp[i - 1][j - 1] + dp[i][j], dp[i - 1][j] + dp[i][j]);

			max = std::max(max, dp[i][j]);
		}

	std::cout << max;	
	return 0;
}