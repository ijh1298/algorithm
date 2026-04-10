#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> answer;

void backtrack(int n, int sum, int cur, int prev, int length, string path);
void printAnswer();

int main() {
    ios::sync_with_stdio(); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        backtrack(n, 1, 2, 1, 1, "1");
        printAnswer();
    }
    
    return 0;
}

void backtrack(int n, int sum, int cur, int prev, int length, string path) {
    if (length == n) {
        if (sum == 0) {
            answer.emplace_back(path);
        }
        return;
    }
    
    // +
    backtrack(n, sum + cur, cur + 1, cur, length + 1, path + "+" + to_string(cur));
    // -
    backtrack(n, sum - cur, cur + 1, -cur, length + 1, path + "-" + to_string(cur));
    
    // 이어 붙이기
    // 이전 연산이 음수
    if (prev < 0) {
        int connected = prev * 10 - cur;
        backtrack(n, sum + -prev + connected, cur + 1, connected, length + 1, path + " " + to_string(cur));
    }
    // 이전 연산이 양수
    else {
        int connected = prev * 10 + cur;
        backtrack(n, sum - prev + connected, cur + 1, connected, length + 1, path + " " + to_string(cur));
    }
}

void printAnswer() {
    sort(answer.begin(), answer.end());
    for (auto a : answer) {
        cout << a << '\n';
    }
    cout << '\n';
    answer.clear();
}
