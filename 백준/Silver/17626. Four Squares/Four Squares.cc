#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(0); 
	std::cin.tie(0);
    std::cout.tie(0);

    int n;
    int dp[50001] = {0, 1};
    std::cin >> n;

	for (int i = 1; i <= n; ++i){
		dp[i] = dp[1] + dp[i - 1];
		for (int j = 2; j * j <= i; ++j){
			dp[i] = std::min(dp[i], dp[i - j * j] + 1);
		}
	}
	std::cout << dp[n];
}