#include <iostream>
#include <vector>
using namespace std;

/*	규칙
*	1. 자기 자리에 있는 수는 움직일 필요 없음
*	2. 자기 자리로 바로 가지 못하면, 제 위치가 아닌 다른 수 중 하나를 옮기면 그 다음엔 갈 수 있음
*/

int main(int argc, char** argv) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, tc;
	cin >> T;

	int place[501] = {};	// 보관함

	for (int tc = 1; tc <= T; tc++) {
		vector<int> ans;
		int N;
		cin >> N;			// 상자 개수

		int input;
		for (int i = 1; i <= N; i++) {
			cin >> input;
			place[i] = input;
		}		

		bool flag = true;
		bool needCheck = true; // 다음에 옮겨야 해서 종료 판단을 할 필요 없는 경우엔 false
		int emptyIndex = N + 1;
		while (flag) {
			// 0. 정렬이 잘 되어 있으면 while문 종료
			bool check = false;
			if (needCheck) {
				check = true;
				for (int i = 1; i <= N; i++) {
					if (place[i] != i) {
						check = false;
						break;
					}
				}
			}
			if (check) {
				flag = false;
				break;
			}

			needCheck = true;
			bool found = false;		// found : 옮길 수 있는 수를 찾았는지
			// 1. 제자리수가 아니면서, 제자리로 옮겨지는 수를 찾기
			for (int i = 1; i <= N + 1; i++) {
				if (place[i] != i && place[i] == emptyIndex) {
					place[emptyIndex] = place[i];
					place[i] = 0;
					emptyIndex = i;
					ans.push_back(i);
					found = true;
					break;
				}
			}
			if (found) 
				continue;
			// 2. 바로 옮길 수가 없다면 제자리가 아닌 다른 수를 빈칸으로 옮기기
			if (!found) {
				for (int i = 1; i <= N + 1; i++) {
					if (place[i] != i) {
						place[emptyIndex] = place[i];
						place[i] = 0;
						emptyIndex = i;
						ans.push_back(i);
						needCheck = false;
						break;
					}
				}
			}
		}
		if (ans.empty())
			cout << "0\n\n";
		else {
			cout << ans.size() << "\n";
			for (int a : ans) {
				cout << a << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}