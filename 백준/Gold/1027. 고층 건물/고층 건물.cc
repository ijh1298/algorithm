#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer = 0;
vector<int> heights;

void input();
int count(int start);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    for (int i = 0; i < N; i++) {
        answer = max(answer, count(i));
    }
    cout << answer << '\n';

    return 0;
}

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        heights.emplace_back(h);
    }
}

int count(int start) {
    int count = 0;

    int curHeight = heights[start];
    double leftInclination = 0; // 왼쪽 기울기

    // 좌 탐색
    for (int i = start - 1; i >= 0; i--) {
        if (i == start - 1 || heights[i] > leftInclination * (start - i) + curHeight) {
            leftInclination = (double)(heights[i] - curHeight) / (start - i);
            count++;
        }
    }

    double rightInclination = 0; // 오른쪽 기울기
    // 우 탐색
        for (int i = start + 1; i < N; i++) {
        if (i == start + 1 || heights[i] > rightInclination * (i - start) + curHeight) {
            rightInclination = (double)(heights[i] - curHeight) / (i - start);
            count++;
        }
    }

    return count;
}
