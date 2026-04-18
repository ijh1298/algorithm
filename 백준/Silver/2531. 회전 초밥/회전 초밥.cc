#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int N, d, k, c;
int visited[30'001];
vector<int> sushi;

void input();
void solve();
void addSushi(int type);
void removeSushi(int type);
void renewAnswer();

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    input();
    solve();
    cout << answer << '\n';
    
    return 0;
}

void input() {
    cin >> N >> d >> k >> c;
    
    for (int i = 0; i < N; i++) {
        int s;
        cin >> s;
        sushi.emplace_back(s);
    }
    
    // 원형 벨트 처리를 위해 앞쪽 k-1개를 뒤에 복사
    for (int i = 0; i < k - 1; i++) {
        sushi.emplace_back(sushi[i]);
    }
}

bool isCouponSushi = false; // 쿠폰 초밥 포함 여부
int cnt = 0;

void solve() {
    // init
    for (int i = 0; i < k; i++) {
        addSushi(sushi[i]);
    }
    renewAnswer();
    
    for (int i = k; i < sushi.size(); i++) {
        addSushi(sushi[i]);
        removeSushi(sushi[i - k]);
        renewAnswer();
    }
}

void addSushi(int type) {
    if (type == c) isCouponSushi = true;
    if (visited[type] == 0) cnt++;
    visited[type]++;
}

void removeSushi(int type) {
    visited[type]--;
    if (visited[type] == 0) {
        cnt--;
        if (type == c) isCouponSushi = false;
    }
}

void renewAnswer() {
    if (isCouponSushi) {
        answer = max(answer, cnt);
    } else {
        answer = max(answer, cnt + 1);
    }
}
