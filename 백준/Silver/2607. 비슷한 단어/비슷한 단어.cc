#include <iostream>
#include <string>
#include <queue>

using namespace std;

int alpha[26];
int N;
int cnt = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    string str;
    cin >> str;
    for (auto c : str) {
        alpha[c - 'A']++;
    }

    for (int i = 0; i < N - 1; i++) {
        int curAlpha[26] = {};

        string curStr;
        cin >> curStr;

        for (auto c : curStr) {
            curAlpha[c - 'A']++;
        }

        queue<pair<char, int>> q;

        for (int j = 0; j < 26; j++) {
            int diff = alpha[j] - curAlpha[j];
            if (diff == 0) continue;

            q.push({'A' + j, diff});
        }

        // 문자 하나 바꾼 경우
        if (q.size() == 2) {
            int first = q.front().second; q.pop();
            int second = q.front().second;

            if ((first == 1 && second == -1) || (first == -1 && second == 1))
                cnt++;
        } 
        // 문자 하나 추가/제거 된 경우
        else if (q.size() == 1 && (q.front().second == 1 || q.front().second == -1)) {
            cnt++;
        }
        // 동일 구성
        else if (q.size() == 0) {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
