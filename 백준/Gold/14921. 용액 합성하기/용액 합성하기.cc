#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.emplace_back(x);
	}

	int minValue = 1e9;
	for (int i = 0; i < N; i++) {
		int l = i + 1;
		int r = N - 1;

		while (l <= r) {
			int mid = (l + r) / 2;
			if (v[i] + v[mid] < 0) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
			if (abs(v[i] + v[mid]) < abs(minValue))
				minValue = v[i] + v[mid];
		}
	}
	cout << minValue;

	return 0;
}