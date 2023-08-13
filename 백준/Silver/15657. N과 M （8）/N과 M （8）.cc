#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> v, p;

void print(int x, int n) {
	if (n == 0) {
		for (int i = 0; i < p.size(); ++i)
			std::cout << p[i] << ' ';
		std::cout << '\n';
		return;
	}
	for (int i = x; i < v.size(); ++i) {
		p.push_back(v[i]);
		print(i, n - 1);
		p.pop_back();
	}
}
int main() {
	int N, M;
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int input;
		std::cin >> input;
		v.push_back(input);
	}
	std::sort(v.begin(), v.end());
	print(0, M);

	return 0;
}