using namespace std;

long long solution(int n) {
    long long dp[2001] = { 0, 1, 2, 3, 5 };
    
    for (int i = 5; i <= n; i++) {
        dp[i] = (dp[i - 1] % 1234567 + dp[i - 2] % 1234567) % 1234567;
    }
    
    return dp[n];
}
