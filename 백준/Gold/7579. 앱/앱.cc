#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int dp[101][10001];
vector<int> memory, cost;

// 입력
void input() {
	cin >> N >> M;
	int m, c;
	for (int i = 0; i < N; i++) {
		cin >> m;
		memory.emplace_back(m);
	}
	for (int i = 0; i < N; i++) {
		cin >> c;
		cost.emplace_back(c);
	}
}

// 냅색 DP의 열을 메모리가 아닌 비용으로 설정
int solve_knapsack() {
	int costSum = 0;
	for (auto c : cost) 
		costSum += c;
	
	// 첫 행 초기화
	for (int i = 0; i < costSum; i++) {
		if (i >= cost[0])
			dp[0][i] = memory[0];
	}

	// 0-1 냅색 구현
	int min = 1e9;
	int minIdx = costSum;
	for (int i = 1; i < N; i++) {
		int m = memory[i];
		int w = cost[i];
		for (int j = 0; j <= costSum; j++) {
			if (j < w) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + m);
			}

			// 더 낮은 비용으로 최소 메모리를 채울 수 있으면 갱신
			if (dp[i][j] >= M && minIdx > j) {
				min = dp[i][j];
				minIdx = j;
			}
		}
	}

	return minIdx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	cout << solve_knapsack();

	return 0;
}