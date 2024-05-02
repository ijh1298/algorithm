#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<int> numbers;
stack<pair<int, int>> stk;
int NGE[1'000'000] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		numbers.push_back(input);
	}
	for (int i = 0; i < N; i++) {
		while (!stk.empty() && stk.top().first < numbers[i]) {
			NGE[stk.top().second] = numbers[i];
			stk.pop();
		}
		stk.push({ numbers[i], i });
	}
	for (int i = 0; i < N; i++)
		if (NGE[i] == 0) NGE[i] = -1;

	for (int i = 0; i < N; i++)
		cout << NGE[i] << " ";

	return 0;
}