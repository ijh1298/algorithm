#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1001][1001];
string s1, s2;
vector<char> route;

// LCS를 구하는 DP 배열 생성
void make_LCS_DP() {
	for (int i = 1; i <= s1.length(); i++) { 
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] != s2[j - 1]) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}
}

// 경로 역추적
void track_route() {
	int i = s1.length();
	int j = s2.length();

	while (i > 0 && j > 0) {
		if (s1[i - 1] == s2[j - 1]) {
			route.emplace_back(s1[i - 1]);
			i--; j--;
		}
		else if (dp[i - 1][j] >= dp[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s1 >> s2;

	make_LCS_DP();
	track_route();

	// 출력
	cout << route.size() << '\n';
	if (!route.empty()) {
		for (int i = route.size() - 1; i >= 0; i--) {
			cout << route[i];
		}
	}

	return 0;
}