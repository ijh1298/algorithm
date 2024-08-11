#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	while (true) {
		stack<char> stk;
		string input;
		getline(cin, input);

		if (input == ".")
			break;

		for (auto c : input) {
			if (c == '(' || c == ')' || c == '[' || c == ']') {
				if (!stk.empty() && ((c == ')' && stk.top() == '(' || (c == ']' && stk.top() == '[')))) {
					stk.pop();
				}
				else {
					stk.push(c);
				}
			}
		}
		stk.empty() ? cout << "yes\n" : cout << "no\n";
	}

	return 0;
}