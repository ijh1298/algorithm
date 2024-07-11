#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int T, test_case;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int unused;
		cin >> unused;

		int scores[101] = {};
		int input;
		for (int i = 0; i < 1000; i++) {
			cin >> input;
			scores[input]++;
		}

		int max = 0;
		int maxIndex = 0;
		for (int i = 100; i >= 0; i--) {
			if (scores[i] > max) {
				max = scores[i];
				maxIndex = i;
			}
		}
		cout << "#" << test_case << " " << maxIndex << '\n';
	}
	return 0;
}