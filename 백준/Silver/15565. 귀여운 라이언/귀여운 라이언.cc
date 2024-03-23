#include <iostream>
#include <vector>
using namespace std;

bool doll[1000001] = {};

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> doll;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		if (input == 1)
			doll.push_back(i);
	}

	int min = 1e9;
	int len = doll.size();
	for (int i = K - 1; i < len; i++) {
		if (min > doll[i] - doll[i - (K - 1)] + 1)
			min = doll[i] - doll[i - (K - 1)] + 1;
	}
	
	if (min != 1e9)
		cout << min;
	else
		cout << -1;

	return 0;
}