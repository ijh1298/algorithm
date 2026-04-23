#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> nums;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    // 입력
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        nums.push_back(n);
    }

    sort(nums.begin(), nums.end());

    // 투포인터
    int l = 0, r = nums.size() - 1;
    int answer = 0;

    while (l < r) {
        if (nums[l] + nums[r] >= M) {
            answer++;
            l++;
            r--;
        } else if (nums[l] + nums[r] < M) {
            l++;
        }
    }

    cout << answer << '\n';

    return 0;
}
