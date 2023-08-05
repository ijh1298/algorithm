#include <iostream>
#include <vector>
 
/* v : 각 sec에 해당하는 상태를 담는 vector 
* e.g.)
* type a 1 : { 1, "a" }
* type b 2 : { 2, "ab" } */
std::vector<std::pair<int, std::string>> v;

int findMax(int n) {
	int max = 0;
	int index = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].first < n && v[i].first > max) {
			max = v[i].first;
			index = i;
		}
	}
	return index;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int N;
	std::cin >> N;

	int sec_last = 0;

	v.push_back({ 0, "" });

	for (int i = 0; i < N; ++i) {
		int sec;
		std::string cmd;
		std::cin >> cmd;

		if (cmd == "type") {
			std::string x;
			std::cin >> x >> sec;

			std::string input;
			input = v.back().second;
			input.append(x);
			v.push_back({ sec, input });
		}
		else if (cmd == "undo") {
			//undo
			//(sec - sec_sub - 1) 상태로 돌아가면 undo 한 것과 같음
			//
			//e.g.) v가 {0, ""}, {1, "a"}, {2, "ab"} 라고 가정하면
			//undo 1 2 >> (3 - 1 - 1) == 1 초 상태인 "a"로 돌아감
			//undo 2 2 >> (3 - 2 - 1) == 0 초 상태인 ""로 돌아감
			int sec_sub;
			std::cin >> sec_sub >> sec;

			if (v.empty())
				continue;

			if (sec - sec_sub > sec_last)
				//(sec - sec_sub - 1)이 마지막 상태보다 클 때, 마지막 상태로 저장함
				//e.g.) 마지막에 {3, "abc"}가 저장 되어 있을 때, undo 10 1000를 입력받으면
				//989초의 상태를 저장해야 하므로 (989 > 3)
				//3과 989초 사이는 없었으니, 3초 상태와 같다고 저장함 
				v.push_back({ sec, v.back().second});
			else
				//e.g.) 989초를 마지막으로 저장하고, undo 50 1010을 입력받으면
				//마지막 상태는 989초지만, 959(1010 - 50 - 1)의 상태를 저장해야 하므로,
				//v에서 959보다 작지만 가장 큰 값({3, "abc"})을 저장함
				v.push_back({ sec, v[findMax(sec - sec_sub)].second });
		}
		sec_last = sec;
	}
	if(!v.empty())
		std::cout << v.back().second;

	return 0;
}