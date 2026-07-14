#include <string>
#include <vector>

using namespace std;

vector<string> v;

bool isLowercase(char c) {
    return c >= 'a' && c <= 'z';
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// 대문자일 때만 소문자로 변경
char toLowercase(char c) {
    if (c == ' ' || isLowercase(c) || isDigit(c)) return c;
    return c - ('A' - 'a');
}

string solution(string s) {
    string answer = "";
    
    bool isFirst = true;
    for (auto c : s) {
        if (isFirst) {
            isFirst = false;
            
            if (isLowercase(c)) {
                answer += c + ('A' - 'a');
            } else {
                answer += c;
            }
        } else {
            answer += toLowercase(c);
        }
        
        if (c == ' ') isFirst = true;
    }
    
    return answer;
}
