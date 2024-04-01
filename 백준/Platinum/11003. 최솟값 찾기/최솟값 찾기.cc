// 삼성 노트 참조
#include <iostream>
#include <deque>
using namespace std;

#define MAX 5000000

int arr[MAX + 1] = {};
int mins[MAX + 1] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(mins, mins + MAX, 1e9);

	int N, L;
	cin >> N >> L;

	deque<int> deq;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < L; i++)
		deq.push_back(arr[0]);

	// 슬라이딩 윈도우를 덱으로 구현
	int valid = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 1;

		mins[i] = deq.front();
		if (valid > 0) {
			deq[1] = deq.front();
			valid--;
		}
		deq.pop_front();

		// 최솟값보다 더 작은 값이 들어오면 deq 전부를 교체
		// 직접 바꾸면 시간 복잡도가 크니, valid하다면 최솟값 취급을 해줌
		if (deq.front() > arr[i]) {
			valid = deq.size() - 1;
			deq.front() = arr[i];
		}
		else {
			while (!deq.empty() && deq.back() > arr[i]) {
				deq.pop_back();
				cnt++;
			}
		}

		while (cnt--)
			deq.push_back(arr[i]);
	}
	mins[N] = deq.front();

	for (int i = 1; i <= N; i++)
		cout << mins[i] << ' ';

	return 0;
}