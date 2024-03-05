#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
char num[500001] = {};

int main() {
    int N, K;
    vector<char> v;

    cin >> N >> K;
    cin >> num;

    int len = strlen(num);

    v.push_back(num[0]);

    for (int i = 1; i < len; i++) {
        int cur = v.size() - 1;

        // stack의 첫 값과 비교하는 경우
        if (v.size() == 1) {
            if (v.front() < num[i]) {
                if (K == 0)
                    break;
                v.pop_back();
                v.push_back(num[i]);
                K--;
            }
            else
                v.push_back(num[i]);
        }
        // stack의 중간에서 비교하는 경우
        // stack 마지막 값이 그 전 값보다 작거나 같고, 지금 들어갈 값(num[i])보다도 작거나 같을 때
        else if (v[cur] <= v[cur - 1] && v[cur] <= num[i]) {
            while (v.size() > 0 && v.back() < num[i]) {
                if (K == 0)
                    break;
                v.pop_back();
                K--;
            }
            v.push_back(num[i]);
        }
        else
            v.push_back(num[i]);
    }

    // 다 지우지 못한 경우 맨 뒤에서 지우기
    while (K != 0) {
        v.pop_back();
        K--;
    }

    for (int i = 0; i < v.size(); i++)
       cout << v[i];

    return 0;
}