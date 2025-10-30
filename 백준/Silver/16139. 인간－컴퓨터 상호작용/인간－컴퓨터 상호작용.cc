#include <iostream>
using namespace std;

int alphabet[26][200'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string name;
    int N;
    cin >> name >> N;

    // 문자 등장 횟수 저장
    alphabet[name[0] - 'a'][0]++;
    for (int i = 1; i < name.length(); i++) {
        // 이전 값 누적
        for (int j = 0; j < 26; j++) {
            alphabet[j][i] = alphabet[j][i - 1];
        }
        char c = name[i];
        alphabet[c - 'a'][i]++;
    }

    while (N--) {
        char c;
        int l, r;
        cin >> c >> l >> r;

        int ans;
        if (l == 0) {
            ans = alphabet[c - 'a'][r];
        } else {
            ans = alphabet[c - 'a'][r] - alphabet[c - 'a'][l - 1];
        }
        cout << ans << '\n';
    }
    return 0;
}
