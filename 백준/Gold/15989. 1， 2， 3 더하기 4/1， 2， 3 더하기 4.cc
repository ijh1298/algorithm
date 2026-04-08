#include <iostream>

#define MAX 10'000

using namespace std;

int dp[MAX + 1] = {0, 1, 2, 3, 4};
int dp2or3[MAX + 1] = {0, 0, 1, 1}; // i를 2 또는 3만 이용해서 만들 수 있는 경우의 수

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // dp2or3 생성
    for (int i = 4; i <= MAX; i++) {
        dp2or3[i] += dp2or3[i - 2];
        if (i % 3 == 0) dp2or3[i]++;
    }

    // dp 생성
    for (int i = 5; i <= MAX; i++) {
        dp[i] = dp[i - 1] + dp2or3[i];
    }

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
