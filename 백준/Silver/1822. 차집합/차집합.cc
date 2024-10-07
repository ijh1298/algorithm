#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> setA, setB, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int A, B, input;
    cin >> A >> B;

    for (int i = 0; i < A; i++) {
        cin >> input;
        setA.emplace_back(input);
    }
    for (int i = 0; i < B; i++) {
        cin >> input;
        setB.emplace_back(input);
    }

    sort(setA.begin(), setA.end());
    sort(setB.begin(), setB.end());

    // 두 포인터 초기화
    int i = 0, j = 0;

    while (i < A && j < B) {
        if (setA[i] < setB[j]) {
            ans.emplace_back(setA[i]); 
            i++;
        }
        else if (setA[i] > setB[j]) {
            j++;
        }
        else {
            i++;
            j++;
        }
    }

    // setA에 남아 있는 원소들 추가
    while (i < A) {
        ans.emplace_back(setA[i]);
        i++;
    }

    if (ans.empty())
        cout << 0 << '\n';
    else {
        cout << ans.size() << '\n';
        for (auto e : ans) {
            cout << e << ' ';
        }
    }

    return 0;
}
