#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long freq[100][21]; // freq[idx][num] : 등장 횟수
vector<int> nums;

void solve() {
	freq[0][nums[0]]++;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < 21; j++) {
			if (freq[i][j] != 0) {
				if (j - nums[i + 1] >= 0)
					freq[i + 1][j - nums[i + 1]] += freq[i][j];
				if (j + nums[i + 1] < 21)
					freq[i + 1][j + nums[i + 1]] += freq[i][j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		nums.emplace_back(x);
	}

	long long ans = 0;
	solve();
	cout << freq[N - 2][nums.back()];

	return 0;
}