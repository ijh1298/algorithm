#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int dp[30001][3001]; // 0-1 Knapsack
bool visit[100001];
vector<int> candies = { 0 };
vector<int> graph[100001];
vector<pair<int, int>> knapsack;

void input() {
	cin >> N >> M >> K;

	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		candies.emplace_back(x);
	}

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}
}

int cnt = 0;
int dfs(int s) {
	cnt++;
	int candy = candies[s];

	visit[s] = true;
	for (auto e : graph[s]) {
		if (!visit[e]) {
			visit[e] = true;
			candy += dfs(e);
		}
	}
	return candy;
}

void solve_knapsack() {
	// 배낭 첫 행 초기화
	for (int i = 1; i <= K; i++) {
		if (knapsack[0].second <= i)
			dp[0][i] = knapsack[0].first;
	}

	// 0-1 냅색 구현
	for (int i = 1; i < knapsack.size(); i++) {
		auto [v, w] = knapsack[i];
		for (int j = 1; j <= K; j++) {
			if (j < w) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - w] + v, dp[i - 1][j]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	input();
	// DFS를 통해 배낭 문제(사탕 수의 합, 친구 수의 합)로 만들기
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			knapsack.emplace_back(make_pair(dfs(i), cnt));
			cnt = 0;
		}
	}

	solve_knapsack();
	cout << dp[knapsack.size() - 1][K - 1];

	return 0;
}