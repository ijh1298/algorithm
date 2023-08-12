#include <iostream>
#include <map>

int main() {
	int T;
	std::cin >> T;

	while (T--) {
		int n;
		std::cin >> n;
		
		std::map<std::string, int> m;

		for (int i = 0; i < n; ++i) {
			std::string value, key;
			std::cin >> value >> key;

			m[key]++;
		}

		int cnt = 1;
		for (auto i : m)
			cnt *= (i.second + 1);

		--cnt;
		std::cout << cnt << '\n';
	}
	return 0;
}