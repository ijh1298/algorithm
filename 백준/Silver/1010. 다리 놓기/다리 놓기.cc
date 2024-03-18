// 다리 놓기 1010번, 조합론 DP
#include <iostream>
using namespace std;

int dp[31][31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // DP 테이블 초기화
    for (int i = 1; i <= 30; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
        dp[i][i] = 1;
        // DP[3][0] : 3 Combination 0 = 1
        // DP[3][1] : 3 Combination 1 = 3   
        // DP[3][3] : 3 Combination 3 = 1
    }

    // DP
    for (int i = 3; i <= 30; i++)
        for (int j = 2; j < i; j++)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

    while (N--) {
        int a, b;
        cin >> a >> b;

        if (a < b)
            swap(a, b);

        cout << dp[a][b] << '\n';
    }

    return 0;
}