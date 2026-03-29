#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1'000'000'000
#define MAX_VISIT 1'000'001

int N, S;
int visitable_front = MAX, visitable_end = 0; // 접근 가능한 position의 시작과 끝
vector<int> positions, fuels;
bool visitable[MAX_VISIT]; // 연결된 커넥트카 확인

void input();
void checkVisitable(int curIdx);
void checkBothSide(int curIdx);
void output();

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    checkVisitable(S - 1);
    checkBothSide(S - 1);
    output();

    return 0;
}

void input() {
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
}

// 접근 가능한 positions를 갱신
void checkVisitable(int curIdx) {
    visitable[curIdx] = true;

    int curPos = positions[curIdx];
    int curFuel = fuels[curIdx];

    if (curPos - curFuel > 0) {
        visitable_front = min(visitable_front, curPos - curFuel);
    } else {
        visitable_front = 0;
    }
    
    if (curPos + curFuel < MAX) {
        visitable_end = max(visitable_end, curPos + curFuel);
    } else {
        visitable_end = MAX;
    }
}

// 투포인터로 연결되는 커넥티드 카 확인
void checkBothSide(int curIdx) {
    int leftIdx = curIdx;
    int rightIdx = curIdx;

    bool changed = true;
    while (changed) {
        // 더 이상 연결되지 않으면 종료
        changed = false;
        // 왼쪽 차가 접근 가능한 범위인 동안
        while (leftIdx > 0 && positions[leftIdx - 1] >= visitable_front) {
            leftIdx--;
            checkVisitable(leftIdx);
            changed = true;
        }

        // 오른쪽 차가 접근 가능한 범위인 동안
        while (rightIdx < N - 1 && positions[rightIdx + 1] <= visitable_end) {
            rightIdx++;
            checkVisitable(rightIdx);
            changed = true;
        }
    }
}

void output() {
    for (int i = 0; i < N; i++) {
        if (visitable[i]) {
            cout << i + 1 << " ";
        }
    }
}
