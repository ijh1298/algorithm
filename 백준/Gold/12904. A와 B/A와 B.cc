#include <iostream>
#include <deque>
#include <string.h>

using namespace std;

int main() {
	deque<char> d;

	int p = 1; // 0 불가능, 1 가능
	bool dir = 0; // 0 정방향, 1 역방향

	char S[1000] = "";
	char T[1001] = "";

	cin >> S >> T;

	int s_len = strlen(S);
	int t_len = strlen(T);
	
	for (int i = 0; i < t_len; i++)
		d.push_back(T[i]);

	while (t_len != s_len) {
		// 정방향일 때
		if (dir == 0) {
			if (d.back() == 'A')
				d.pop_back();
			else { 
				d.pop_back();
				dir = 1; // 방향 전환
			}
		}
		// 역방향일 때
		else {
			if (d.front() == 'A')
				d.pop_front();
			else {
				d.pop_front();
				dir = 0; // 방향 전환
			}
		}
		t_len--;
	}

	if (dir == 0) {
		for (int i = 0; i < t_len; i++)
			if (S[i] != d[i]) {
				p = 0; // 불가능
				break;
			}
	}
	else {
		for (int i = 0; i < t_len; i++)
			if (S[i] != d[t_len - 1 - i]) {
				p = 0; // 불가능
				break;
			}
	}

	cout << p;

	return 0;
}