#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int x;
	vector<int> pv, nv;
	// pv 양수 거리를 담는 vector
	// nv 음수 거리를 담는 vector
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x > 0)
			pv.push_back(x);
		else
			nv.push_back(x);
	}

	int ans = 0;
	int pLen = 0, nLen = 0;

	if (!pv.empty()) {
		sort(pv.begin(), pv.end());
		pLen = pv.size() - 1;
		for (int i = pLen; i >= 0; i -= M)
			ans += pv[i] * 2;
		// 최대 책 수 M권의 범위 만큼 왔다 갔다 이동
		// M이 3이라면, pv[0]~pv[2], pv[3]~pv[5], ...이므로 pv[0] + pv[3] + pv[6] + ...의 거리를 더함
	}

	if (!nv.empty()) {
		sort(nv.begin(), nv.end());
		nLen = nv.size() - 1;
		for (int j = 0; j <= nLen; j += M)
			ans -= nv[j] * 2;
	}

	// 양수 음수 중 왕복하지 않을 마지막 방향 결정
	int pMax = pv.empty() ? 0 : pv.back();
	int nMax = nv.empty() ? 0 : nv.front();

	if (pMax + nMax > 0) // 양수의 끝이 더 크면 양수 마지막 거리를 빼기
		ans -= pMax;
	else
		ans -= -nMax;	 // 음수의 끝이 더 크면 음수 마지막 거리를 빼기

	cout << ans;

	return 0;
}