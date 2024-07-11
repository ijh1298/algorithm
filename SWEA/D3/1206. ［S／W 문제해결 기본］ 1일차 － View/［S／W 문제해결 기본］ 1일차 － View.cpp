#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int tc = 1; tc <= 10; tc++) {
		int T;
		cin >> T;

		int buildings[1001] = {};
		int ans = 0;
		for (int i = 0; i < T; i++) {
			int b;
			cin >> b;
			buildings[i] = b;
		}
		// 2번 건물부터 7번 건물까지 조망권 확인
		for (int i = 2; i < T - 2; i++) {
			int cur = buildings[i];
			int first = buildings[i - 2];
			int second = buildings[i - 1];
			int third = buildings[i + 1];
			int fourth = buildings[i + 2];
			
			if (first >= cur || second >= cur || third >= cur || fourth >= cur)
				continue;
			
			// 인접한 네 빌딩 중 가장 격차가 작은 값이 조망권 확보된 세대 수
			ans += min(min(cur - first, cur - second), min(cur - third, cur - fourth));
		}
		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}