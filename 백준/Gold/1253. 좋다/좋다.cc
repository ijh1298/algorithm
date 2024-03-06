// 투포인터 알고리즘 숙지하기 : O(N)
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, a;
	std::cin >> N;

	std::vector<int> v;
	for (int i = 0; i < N; i++) {
		std::cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int start, end, cnt = 0;

	for (int i = 0; i < N; i++) {
		// 투포인터는 양 끝을 가리키게 함
		start = 0;
		end = N - 1;

		while (start < end) {
			// 투포인터가 자기 자신을 가리키지 못하게 예외 처리
			if (start == i) {
				start++;
				continue;
			}
			else if (end == i) {
				end--;
				continue;
			}

			// 투포인터 합이 v[i]보다 작으면 start를 오른쪽으로
			if (v[start] + v[end] < v[i]) {
				start++;
			}
			// 투포인터 합이 v[i]보다 크면 end를 왼쪽으로
			else if (v[start] + v[end] > v[i]) {
				end--;
			}
			else {
				cnt++;
				break;
			}
		}
	}
	std::cout << cnt;

	return 0;
}