#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int r, c, k;
int rNum = 3, cNum = 3; // 행, 열 개수
int freq[101]; // 한 줄의 자연수 등장 개수
int matrix[101][101];

void input() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> matrix[i][j];
}

void init_matrix() {
	fill(&matrix[0][0], &matrix[0][0] + 101 * 101, -1);
}

void init_freq() {
	fill(freq, freq + 101, 0);
}

void r_operate() {
	int maxRowLen = 0;

	for (int i = 1; i <= rNum; i++) {
		// 0. freq 초기화
		init_freq();

		// 1. 행에서 개수 쌍 추출
		for (int j = 1; j <= cNum; j++)
			freq[matrix[i][j]]++; 

		// 2. pq 생성
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (빈도, 숫자)
		for (int j = 1; j <= 100; j++) {
			if (freq[j] > 0)
				pq.emplace(freq[j], j);
		}

		// 3. 정렬된 형태로 overwrite
		int len = 1;
		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();
			matrix[i][len++] = cur.second; // 숫자
			matrix[i][len++] = cur.first; // 빈도
			
			maxRowLen = max(maxRowLen, len - 1);
			if (len > 100) break;
		}

		// 4. 사용하지 않은 부분은 -1로 설정
		for (int j = len; j <= 100; j++)
			matrix[i][j] = -1;
	}

	// 5. 최대 길이 만큼 빈 값 0으로 설정
	for (int i = 1; i <= rNum; i++)
		for (int j = 1; j <= maxRowLen; j++)
			if (matrix[i][j] == -1)
				matrix[i][j] = 0;

	cNum = maxRowLen;
}

void c_operate() {
	int maxColLen = 0;

	for (int i = 1; i <= cNum; i++) {
		init_freq();

		for (int j = 1; j <= rNum; j++)
			freq[matrix[j][i]]++;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for (int j = 1; j <= 100; j++) {
			if (freq[j] > 0)
				pq.emplace(freq[j], j);
		}

		int len = 1;
		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();
			matrix[len++][i] = cur.second;
			matrix[len++][i] = cur.first;

			maxColLen = max(maxColLen, len);
			if (len > 100) break;
		}

		for (int j = len; j <= 100; j++)
			matrix[j][i] = -1;
	}

	for (int i = 1; i <= cNum; i++)
		for (int j = 1; j <= maxColLen; j++)
			if (matrix[j][i] == -1)
				matrix[j][i] = 0;

	rNum = maxColLen;
}

void solve() {
	int cnt = 0;
	while (cnt <= 100) {
		if (matrix[r][c] == k) {
			cout << cnt;
			return;
		}

		if (rNum >= cNum)
			r_operate();
		else
			c_operate();
		++cnt;
	}
	cout << -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solve();

	return 0;
}