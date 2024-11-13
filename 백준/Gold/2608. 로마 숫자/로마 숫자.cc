#include <iostream>
using namespace std;

string s1, s2;

int romeToArabic(string r) {
	int result = 0;
	for (int i = 0; i < r.size(); i++) {
		if (r[i] == 'I')
			result += 1;
		else if (r[i] == 'V') {
			if (i > 0 && r[i - 1] == 'I')
				result += 3;
			else
				result += 5;
		}
		else if (r[i] == 'X') {
			if (i > 0 && r[i - 1] == 'I')
				result += 8;
			else
				result += 10;
		}
		else if (r[i] == 'L') {
			if (i > 0 && r[i - 1] == 'X')
				result += 30;
			else
				result += 50;
		}
		else if (r[i] == 'C') {
			if (i > 0 && r[i - 1] == 'X')
				result += 80;
			else
				result += 100;
		}
		else if (r[i] == 'D') {
			if (i > 0 && r[i - 1] == 'C')
				result += 300;
			else
				result += 500;
		}
		else if (r[i] == 'M') {
			if (i > 0 && r[i - 1] == 'C')
				result += 800;
			else
				result += 1000;
		}
	}
	return result;
}

string arabicToRome(int a) {
	int nums[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string rome[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	string result = "";
	int cur = a;

	while (cur != 0) {
		for (int i = 0; i < 13; i++) {
			if (cur >= nums[i]) {
				cur -= nums[i];
				result += rome[i];
				break;
			}
		}
	}
	return result;
}

int main() {
	cin >> s1 >> s2;

	int ans = romeToArabic(s1) + romeToArabic(s2);
	cout << ans << '\n';
	cout << arabicToRome(ans);

	return 0;
}