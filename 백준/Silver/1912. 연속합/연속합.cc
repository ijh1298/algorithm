#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans;
int dp[100001];
vector<int> v;

void input() {
	cin >> N;
	while (N--) {
		int x;
		cin >> x;
		v.emplace_back(x);
	}
}

void make_dp() {
	dp[0] = v[0];
	int MAX = dp[0];
	for (int i = 1; i < v.size(); i++) {
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		MAX = max(MAX, dp[i]);
	}
	ans = MAX;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	make_dp();
	cout << ans;

	return 0;
}