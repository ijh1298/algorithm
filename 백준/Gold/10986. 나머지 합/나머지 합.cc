#include <iostream>
#include <vector>

using namespace std;

int N, M;
long long ans = 0;
int dp[1'000'001];
int rems[1001]; // rems[i] : 누적합 배열을 i로 나머지 연산을 했을 때, 나머지가 i인 값의 개수
vector<int> nums = { 0 };

void input();
void count();

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    input();
    
    // 누적합
    for (int i = 1; i <= N; i++) {
        dp[i] = (dp[i - 1] + nums[i]) % M; // M으로 나머지 연산
    }
    
    for (int i = 1; i <= N; i++) {
        rems[dp[i]]++;
    }
    
    count();
    cout << ans;
    
    return 0;
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        nums.push_back(n);
    }
}

void count() {
    rems[0]++;

    for (int i = 0; i < M; i++) {
        // 나머지가 같은 것 중 2개를 고르는 조합: nC2 = n*(n-1)/2
        ans += (long long)rems[i] * (rems[i] - 1) / 2;
    }
}
