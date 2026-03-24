#include <iostream>
#include <algorithm>

using namespace std;

int dp[101][10001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // 입력
    int N, T;
    cin >> N >> T;
    
    vector<pair<int, int>> bag;
    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        bag.push_back({w, v});
    }
    
    // 배낭 문제
    for (int i = 1; i <= N; i++) {
        auto [w, v] = bag[i - 1];
        
        for (int j = 0; j <= T; j++) {
            // idx가 w보다 작으면 이전 값으로 채우기
            if (j < w) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
        }
    }
    cout << dp[N][T] << '\n';
    
    return 0;
}
