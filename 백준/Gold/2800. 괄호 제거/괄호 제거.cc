#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

string s;
int exceptPos[201];
vector<pair<int, int>> pos; // pair (괄호의 시작 위치, 닫히는 위치)
set<string> ans; // 중복 없고, 사전 정렬되도록 set 자료구조

void init_exceptPos() {
	for (int i = 0; i < s.length(); i++) {
		exceptPos[i] = false;
	}
}

void divide() {
	stack<pair<int, char>> st; // index, 괄호
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			st.emplace(i, '(');
		if (s[i] == ')') {
			auto pair = st.top(); st.pop();
			pos.emplace_back(pair.first, i);
		}
	}
}

void bruteforce_with_comb() {
	for (int i = 1; i <= pos.size(); i++) {
		vector<bool> comb(pos.size(), true);
		fill(comb.begin(), comb.end() - i, false);

		do {
			for (int j = 0; j < pos.size(); j++) {
				if (comb[j]) {
					exceptPos[pos[j].first] = true;
					exceptPos[pos[j].second] = true;
				}
			}
			string newString;
			for (int j = 0; j < s.length(); j++) {
				if (!exceptPos[j])
					newString += s[j];
			}
			ans.insert(newString);
			init_exceptPos();

		} while (next_permutation(comb.begin(), comb.end()));
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s;
	divide();
	bruteforce_with_comb();

	for (auto e : ans)
		cout << e << '\n';

	return 0;
}