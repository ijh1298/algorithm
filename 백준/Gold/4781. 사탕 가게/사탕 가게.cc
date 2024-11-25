#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
double money;
vector<pair<int, int>> candies;
int dp[10001];

void init() {
    candies.clear();
    fill(dp, dp + 10001, 0);
}

void knapsack() {
    int M = static_cast<int>(money * 100 + 0.5);

    for (auto [price, calorie] : candies) {
        for (int j = price; j <= M; j++) {
            dp[j] = max(dp[j], dp[j - price] + calorie);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        cin >> N >> money;

        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            int v; double w;
            cin >> v >> w;
            candies.emplace_back(static_cast<int>(w * 100 + 0.5), v);
        }

        knapsack();

        int M = static_cast<int>(money * 100 + 0.5);
        cout << dp[M] << '\n';
        init();
    }

    return 0;
}
