#include <iostream>
#include <vector>
using namespace std;

int N;
int nums[101];
bool visit[101];
bool done[101];

void init_visit() {
	for (int i = 1; i <= N; i++)
		visit[i] = false;
}

void add_answers() {
	for (int i = 1; i <= N; i++)
		if (visit[i])
			done[i] = true;
}

void dfs(int origin, int to) {
	if (nums[to] == origin) {
		add_answers();
		return;
	}

	if (!visit[nums[to]] && !done[nums[to]]) {
		visit[nums[to]] = true;
		dfs(origin, nums[to]);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> nums[i];

	for (int i = 1; i <= N; i++) {
		visit[i] = true;
		dfs(i, i);
		init_visit();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (done[i])
			ans++;
	}

	cout << ans << '\n';
	for (int i = 1; i <= N; i++)
		if (done[i])
			cout << i << '\n';

	return 0;
}