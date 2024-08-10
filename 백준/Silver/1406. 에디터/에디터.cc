#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    // 연결 리스트 선언
    list<char> l;

    // 초기 문자열 입력
    for (auto c : str)
        l.push_back(c);

    int T;
    cin >> T;

    auto cur = l.end(); // 현재 커서 위치
    while (T--) {
        char cmd, c;
        cin >> cmd;

        switch (cmd) {
        case 'L':
            if (cur != l.begin())
                cur--;
            break;
        case 'D':
            if (cur != l.end())
                cur++;
            break;
        case 'B': {
            if (cur != l.begin()) {
                cur = l.erase(--cur);
            }
            break;
        }
        case 'P': {
            cin >> c;
            l.insert(cur, c);
        }
        }
    }
    for (auto c : l)
        cout << c;

    return 0;
}
