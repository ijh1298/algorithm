#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int zeroNum = 0;
	int oneNum = 0;

	if (s[0] == '0')
		zeroNum++;
	else
		oneNum++;

	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] != s[i]) {
			if (s[i] == '0') zeroNum++;
			else oneNum++;
		}
	}

	if (zeroNum == 0 || oneNum == 0)
		cout << 0;
	else
		cout << min(zeroNum, oneNum);

	return 0;
}