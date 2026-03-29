#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000000000

int visit_front = MAX, visit_end = 0; // 방문 가능한 pos의 시작과 끝
int N, S;
bool visited[1000001];
vector<int> positions, fuels;

// 현재 연료양에 따라 방문 가능 지점을 갱신
bool checkVisitable(int curIdx) {
    if (visited[curIdx])
        return false;
        
    visited[curIdx] = true;
    int fuel = fuels[curIdx];
    int pos = positions[curIdx];

    if (pos - fuel < 0) {
        visit_front = 0;
    } else {
        visit_front = min(visit_front, pos - fuel);
    }

    if (pos + fuel > MAX) {
        visit_end = MAX;
    } else {
        visit_end = max(visit_end, pos + fuel);
    }
    return true;
}

// 투포인터로 확인
void checkBothSide(int curIdx) {
    int leftIdx = curIdx;
    int rightIdx = curIdx;

    bool changed = true;
    while (changed) {
        changed = false;

        while (leftIdx > 0 && positions[leftIdx - 1] >= visit_front) {
            leftIdx--;
            checkVisitable(leftIdx);
            changed = true;
        }

        while (rightIdx < N - 1 && positions[rightIdx + 1] <= visit_end) {
            rightIdx++;
            checkVisitable(rightIdx);
            changed = true;
        }
    };
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // 입력
    cin >> N >> S;
    
    for (int i = 0; i < N; i++) {
        int position;
        cin >> position;
        positions.push_back(position);
    }
    
    for (int i = 0; i < N; i++) {
        int fuel;
        cin >> fuel;
        fuels.push_back(fuel);
    }
    
    // DFS
    checkVisitable(S - 1);
    checkBothSide(S - 1);
    
    // 출력
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}
