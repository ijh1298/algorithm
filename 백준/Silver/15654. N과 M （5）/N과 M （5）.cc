#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v;
std::vector<int> p;
bool used_index[10001];

void print(int N) {
	if (N == 0) {
		for (int i = 0; i < p.size(); ++i)
			std::cout << p[i] << ' ';
		std::cout << '\n';
		return;
	}
	for (int i = 0; i < v.size(); ++i) {
		if (!used_index[i])
			p.push_back(v[i]);
		else
			continue;

		used_index[i] = true;
		print(N - 1);
		if(!p.empty())
			p.pop_back();
		used_index[i] = false;
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int N, M;
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int number;
		std::cin >> number;
		v.push_back(number);
	}
	std::sort(v.begin(), v.end());

	print(M);

	return 0;
}