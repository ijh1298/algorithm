#include <iostream>
#include <queue>
using namespace std;

int main() {
	int TC;
	cin >> TC;

	// 덱 자료구조 이용하기
	for (int test_case = 1; test_case <= TC; ++test_case) {
		string S, E;
		cin >> S >> E;

		deque<char> deq;

		// E 문자열을 덱에 push
		for (char c : E)
			deq.push_back(c);

		int sLen = S.length();
		int eLen = E.length();
		bool isFlipped = false;

		while (sLen != eLen) {
			// 뒤집혔을 때
			if (isFlipped) {
				if (deq.front() == 'Y')
					isFlipped = false;
				deq.pop_front();
			}
			// 뒤집히지 않았을 때
			else {
				if (deq.back() == 'Y')
					isFlipped = true;
				deq.pop_back();
			}
			eLen--;
		}
		
		// 동일한 문자열인지 확인
		bool flag = true;
		if (isFlipped) {
			for (int i = 0; i < eLen; ++i) {
				if (deq[eLen - 1 - i] != S[i]) {
					flag = false;
					break;
				}
			}
		}
		else {
			for (int i = 0; i < eLen; ++i) {
				if (deq[i] != S[i]) {
					flag = false;
					break;
				}
			}
		}
		if (flag)
			cout << "#" << test_case << " Yes\n";
		else
			cout << "#" << test_case << " No\n";
	}
	return 0;
}