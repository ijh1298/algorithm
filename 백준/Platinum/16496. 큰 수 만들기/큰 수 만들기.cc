#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
vector<string> strings;

// 두 문자열 a와 b를 연결했을 때 더 큰 문자열 순으로 정렬
bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    string num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        strings.push_back(num);
    }
    
    sort(strings.begin(), strings.end(), compare);
    int len = strings.size();

    // 모든 값이 0인 경우 한 번만 출력하기
    bool flag = false;
    for (int i = 0; i < len; i++) {
        if (strings[i] != "0") {
            flag = true;
            break;
        }
    }   

    if (flag == false)
        cout << 0;
    else
        for (int i = 0; i < len; i++)
            cout << strings[i];

    return 0;
}