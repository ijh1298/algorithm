#include <iostream>
#include <vector>
using namespace std;

#define MAX 4000001
bool prime[MAX];
vector<int> p, acc_sum;
// 에라토스테네스의 체
void get_prime() {
	int cur = 2;
	while (cur < MAX) {
		p.emplace_back(cur);
		for (int i = cur; i < MAX; i += cur)
			prime[i] = true;
	
		bool flag = true;
		for (int i = cur + 1; i < MAX; i++)
			if (!prime[i]) {
				cur = i;
				flag = false;
				break;
			}
	
		if (flag) // 찾을 수 없으면 종료
			break;
	}
}

// 누적합 구하기
void get_acc_sum() {
	acc_sum = p;
	int T = acc_sum.size();
	for (int i = 1; i < T; i++) {
		acc_sum[i] += acc_sum[i - 1];
	}
}

// 투 포인터
int solve(int goal) {
	if (goal == 2)
		return 1;

	int ans = 0;
	int l = 0;
	int r = 0;
	int limit = p.size();

	while (l < limit && r < limit) {
		int cur;
		if (l == r)
			cur = p[l];
		else {
			if (l == 0)
				cur = acc_sum[r];
			else
				cur = acc_sum[r] - acc_sum[l - 1];
		}

		if (cur < goal)
			r++;
		else if (cur > goal)
			l++;
		else {
			ans++;
			l++;
		}
	}

	return ans;
}

int main() {
	int N;
	cin >> N;

	get_prime();
	get_acc_sum();
	cout << solve(N);

	return 0;
}