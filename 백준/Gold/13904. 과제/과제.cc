#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

priority_queue<pair<int, int>> pq;
vector<int> dayCheck;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, d, w, answer = 0;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> d >> w;
		pq.push({ w, d });	// 가치, 마감일 순
	}
	
	while (!pq.empty()) {
		int w = pq.top().first;
		int d = pq.top().second;
		pq.pop();

		dayCheck.push_back(d);
		sort(dayCheck.begin(), dayCheck.end());
		int len = dayCheck.size();
		int curDay = 1;

		// feasibility 확인
		bool flag = true;
		int target = 0;
		for (int i = 0; i < len; i++) {
			if (dayCheck[i] < curDay) {
				flag = false;
				target = i;
				break;
			}
			curDay++;
		}
		if (flag)
			answer += w;
		else // 할 수 없는 과제 날짜는 dayCheck에서 제거
			dayCheck.erase(dayCheck.begin() + target);
	}
	cout << answer;
	return 0;
}