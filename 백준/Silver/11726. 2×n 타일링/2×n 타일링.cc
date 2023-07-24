#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);

	int dp[1001] = { 0,1,2 };
	
	//*다이나믹 프로그래밍 문제*
	//1, 2, 3, 5, 8 ... 점화식을 세우면
	//i번째 항은 i-2번째 항 + i-1번째 항의 값과 같다.
	for (int i = 3; i < 1001; ++i)
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;

	int n;
	std::cin >> n;

	std::cout << dp[n];

	return 0;
}