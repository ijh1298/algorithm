#include <iostream>
using namespace std;

int arr[1001], N, M;
int ans = 0;
int k = 1;

int main() {
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= i; j++) {
			arr[k] = i;
			if (k > 1000) {
				break;
			}
			k++;
		}
	}
	cin >> N >> M;
	for (int i = N; i <= M; i++) {
		ans += arr[i];
	}
	cout << ans;
	return 0;
}