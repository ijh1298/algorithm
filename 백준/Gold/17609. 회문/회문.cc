#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		string str;
		cin >> str;

		int first = 0;
		int last = str.size() - 1;
		int type1 = 0;
		int type2 = 0;
		bool chanceUsed = false;

		// 맨 앞 인덱스와 맨 뒤 인덱스를 비교
		// 비교해서 다르면 그 다음 인덱스로 조정할 기회 한번이 있음
		while (first < last) {
			if (str[first] != str[last]) {
				if (chanceUsed == false) {
					if (str[first + 1] == str[last]) {
						chanceUsed = true;
						first += 1;
						type1 = 1;
					}
					else if (str[first] == str[last - 1]) {
						chanceUsed = true;
						last -= 1;
						type1 = 1;
					}
					else {
						type1 = 2;
						break;
					}
				}
				else {
					type1 = 2;
					break;
				}
			}
			first++;
			last--;
		}
		// if문 순서를 바꾸어서 한번 더 진행
		first = 0;
		last = str.size() - 1;
		chanceUsed = false;
		while (first < last) {
			if (str[first] != str[last]) {
				if (chanceUsed == false) {
					if (str[first] == str[last - 1]) {
						chanceUsed = true;
						last -= 1;
						type2 = 1;
					}
					else if (str[first + 1] == str[last]) {
						chanceUsed = true;
						first += 1;
						type2 = 1;
					}
					else {
						type2 = 2;
						break;
					}
				}
				else {
					type2 = 2;
					break;
				}
			}
			first++;
			last--;
		}
		cout << min(type1, type2) << '\n';
	}

	return 0;
}