// 갤럭시 노트 그림 참조
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5

int main() {
	long long N;
	int dice[6];
	cin >> N;
	for (int i = 0; i < 6; i++)
		cin >> dice[i];

	long long min3 = INT_MAX;
	// 3면이 이어지게 고르는 방법
	// 선택된 면의 반대쪽 면은 피하기
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (i + j == 5)						// 합이 5면 (반대쪽 면이면 SKIP)
				continue;
			for (int k = j + 1; k < 6; k++) {
				if (j + k == 5 || i + k == 5)
					continue;
				if (min3 > dice[i] + dice[j] + dice[k])
					min3 = dice[i] + dice[j] + dice[k];
			}
		}
	}

	long long min2 = INT_MAX;
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (i + j == 5)
				continue;
			if (min2 > dice[i] + dice[j])
				min2 = dice[i] + dice[j];
		}
	}

	long long min1 = dice[A];
	for (int i = 1; i < 6; i++) {
		if (min1 > dice[i])
			min1 = dice[i];
	}	

	long long ans = 0;
	int max = 0;
	if (N == 1) {
		int sum = 0;
		for (int i = 0; i < 6; i++) {
			sum += dice[i];
			if (max < dice[i])
				max = dice[i];
		}
		ans = sum - max;
	}
	else {
		ans = min3 * 4 + (N - 1) * min2 * 4 + (N - 2) * min2 * 4 + (((N - 2) * (N - 2) + (N - 2)) * 4 + (N - 2) * (N - 2)) * min1;
	}
	cout << ans;

	return 0;
}