#include <iostream>
#include <stack>

// operator 우선순위 반환
int priority(char op) {
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	return 0;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	std::string s;
	std::cin >> s;

	//연산자를 담는 스택 st
	std::stack<char> st;

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] < 91 && s[i] > 64)
			std::cout << s[i];
		// 0. 닫는 괄호를 입력 받으면, 여는 괄호가 나올 때까지 stack pop
		else if (s[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				std::cout << st.top();
				st.pop();
			}
			st.pop(); // Pop '('
		}
		else if (s[i] == '(')
			st.push(s[i]);
		else {
			// 1. 마지막 op와 비교하여 우선순위가 같거나 큰 것을 입력받으면 stack pop
			while (!st.empty() && priority(st.top()) >= priority(s[i])) {
				std::cout << st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	// 2. 수식이 끝나면 stack 전부 pop
	while (!st.empty()) {
		std::cout << st.top();
		st.pop();
	}

	return 0;
}