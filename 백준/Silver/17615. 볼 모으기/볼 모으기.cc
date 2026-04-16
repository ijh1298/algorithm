#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string str;

int caseRightR();
int caseRightB();
int caseLeftR();
int caseLeftB();

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> str;
    
    int ans = 1e9;
    ans = min(ans, caseRightR());
    ans = min(ans, caseRightB());
    ans = min(ans, caseLeftR());
    ans = min(ans, caseLeftB());
    
    if (ans == 1e9) cout << 0 << '\n';
    else cout << ans << '\n';
    
    return 0;
}

// 오른쪽으로 R을 넘기는 경우
int caseRightR() {
    bool first = true;
    int cnt = 0;

    for (int i = str.length() - 1; i >= 0; i--) {
        if (first && str[i] == 'B') {
            first = false;
        } else if (!first && str[i] == 'R') {
            cnt++;
        }
    }
    return cnt;
}

// 오른쪽으로 B를 넘기는 경우
int caseRightB() {
    bool first = true;
    int cnt = 0;

    for (int i = str.length() - 1; i >= 0; i--) {
        if (first && str[i] == 'R') {
            first = false;
        } else if (!first && str[i] == 'B') {
            cnt++;
        }
    }
    return cnt;
}

// 왼쪽으로 R을 넘기는 경우
int caseLeftR() {
    bool first = true;
    int cnt = 0;

    for (int i = 0; i < str.length(); i++) {
        if (first && str[i] == 'B') {
            first = false;
        } else if (!first && str[i] == 'R') {
            cnt++;
        }
    }
    return cnt;
}

// 오른쪽으로 B를 넘기는 경우
int caseLeftB() {
    bool first = true;
    int cnt = 0;

    for (int i = 0; i < str.length(); i++) {
        if (first && str[i] == 'R') {
            first = false;
        } else if (!first && str[i] == 'B') {
            cnt++;
        }
    }
    return cnt;
}
