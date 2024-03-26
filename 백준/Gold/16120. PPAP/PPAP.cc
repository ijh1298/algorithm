#include <iostream>
#include <string.h>
using namespace std;

int main() {
	string str;
	cin >> str;

	bool isNP = false;
	bool needToCheck = false;
	int stack = 1;	
	int len = str.size();

	if (str[0] == 'P') {
		for (int i = 1; i < len; i++) {
			if (str[i] == 'P') {
				needToCheck = false;
				if (str[i - 1] == 'A' && stack >= 3)
					stack -= 2;							// PPAP가 완성되면 스택에 넣지 않고 두 개 pop
				else
					stack++;
			}
			else if (str[i] == 'A') {
				if (stack <= 1 || str[i - 1] == 'A') {	// P가 2개가 안 쌓였거나 A가 연속으로 오면 NP
					isNP = true;
					break;
				}
				else
					stack++;
			}
		}
	}
	else
		isNP = true;

	// 결과적으로 P 하나로 치환되느냐
	if (stack != 1)
		isNP = true;

	isNP ? cout << "NP" : cout << "PPAP";

	return 0;
}