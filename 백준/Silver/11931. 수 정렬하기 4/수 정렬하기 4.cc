#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int x;
	vector<int> v;
	while (N--) {
		cin >> x;
		v.emplace_back(x);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (auto e : v)
		cout << e << '\n';
	return 0;
}