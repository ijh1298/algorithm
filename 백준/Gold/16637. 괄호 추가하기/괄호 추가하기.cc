#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, ans = INT_MIN;
string expression;

vector<int> number = { 0 };
vector<char> oper = { 0 };
int pair_result[11] = {}; // pair_result[1] = number[1] oper[1] number[2]의 결과
vector<int> combination;

void parse() {
	for (int i = 0; i < expression.length(); i++) {
		if (i % 2 == 0)
			number.emplace_back(expression[i] - '0');
		else
			oper.emplace_back(expression[i]);
	}
}

void make_pair_result() {
	for (int i = 1; i < oper.size(); i++) {
		int first = number[i];
		int second = number[i + 1];

		if (oper[i] == '+')
			pair_result[i] = first + second;
		else if (oper[i] == '-')
			pair_result[i] = first - second;
		else
			pair_result[i] = first * second;
	}
}

void backtrack() {
	// 현재 조합으로 연산
	bool onParenthesis[11] = {};
	for (auto c : combination)
		onParenthesis[c] = true;

	int sum = number[1];
	bool nextSkip = false;
	if (onParenthesis[1]) {
		sum = pair_result[1];
		nextSkip = true;
	}

	for (int i = 1; i < oper.size(); i++) {
		if (nextSkip) {
			nextSkip = false;
			continue;
		}

		if (onParenthesis[i + 1]) {
			if (oper[i] == '+')
				sum += pair_result[i + 1];
			else if (oper[i] == '-')
				sum -= pair_result[i + 1];
			else
				sum *= pair_result[i + 1];
			nextSkip = true;
		}
		else {
			if (oper[i] == '+')
				sum += number[i + 1];
			else if (oper[i] == '-')
				sum -= number[i + 1];
			else
				sum *= number[i + 1];
		}
	}

	ans = max(ans, sum);

	if (combination.empty()) return;

	// 다음 조합 추가하고 호출
	for (int i = combination.back() + 2; i < number.size() - 1; i++) {
		combination.emplace_back(i);
		backtrack();
		combination.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> expression;

	parse();
	make_pair_result();
	backtrack();
	for (int i = 1; i < number.size() - 1; i++) {
		combination.emplace_back(i);
		backtrack();
		combination.clear();
	}
	cout << ans;

	return 0;
}