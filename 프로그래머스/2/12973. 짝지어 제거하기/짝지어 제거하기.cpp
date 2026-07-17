#include <string>
#include <vector>

using namespace std;

int solution(string str) {
    vector<char> stack;
    
    for (auto c : str) {
        if (!stack.empty() && stack.back() == c) {
            stack.pop_back();
        } else {
            stack.push_back(c);
        }
    }
    
    return stack.empty() ? 1 : 0;
}
