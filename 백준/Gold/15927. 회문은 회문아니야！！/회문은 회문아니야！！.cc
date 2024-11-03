// 전체 문자열이 회문이면 전체 문자열 길이 -1 반환하면 되고,
// 아니면 그대로 반환하면 되며,
// 모든 문자가 같은 문자열이면 -1 반환하면 된다.

#include <iostream>
using namespace std;

bool isPalindrome(string s) {
	int l = 0;
	int r = s.length() - 1;

	while (l <= r) {
		if (s[l] != s[r]) {
			return false;
		}
		l++;
		r--;
	}
	return true;
}

bool isAllSame(string s) {
	char check = s[0];
	for (auto c : s) {
		if (c != check) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	if (isPalindrome(s)) {
		if (isAllSame(s))
			cout << -1;
		else
			cout << s.length() - 1;
	}
	else
		cout << s.length();

	return 0;
}