#include <iostream>
using namespace std;

int dp[1001][1001];

int main() {
    int N, K;
    cin >> N >> K;

    // DP 테이블 초기화
    for (int i = 1; i <= N; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
        dp[i][i] = 1;
        // DP[3][0] : 3 Combination 0 = 1
        // DP[3][1] : 3 Combination 1 = 3   
        // DP[3][3] : 3 Combination 3 = 1
    }

    // DP
    for (int i = 3; i <= N; i++) {
        for (int j = 2; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            dp[i][j] %= 10007;
        }
    }

    cout << dp[N][K];

    return 0;
}