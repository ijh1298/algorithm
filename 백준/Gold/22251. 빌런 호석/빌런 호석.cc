#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool bit[10][7] = {
    {1, 1, 1, 0, 1, 1, 1}, // 0
    {0, 0, 0, 0, 0, 1, 1}, // 1
    {0, 1, 1, 1, 1, 1, 0}, // 2
    {0, 0, 1, 1, 1, 1, 1}, // 3
    {1, 0, 0, 1, 0, 1, 1}, // 4
    {1, 0, 1, 1, 1, 0, 1}, // 5
    {1, 1, 1, 1, 1, 0, 1}, // 6
    {0, 0, 1, 0, 0, 1, 1}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 0, 1, 1, 1, 1, 1}, // 9
};
int N, K, P, X, answer = 0;
int change[10][10]; // i -> j 되기 위해 필요한 반전 수 change[i][j]

void bitDiffCount();
void compareFloor();

int main() {
    ios::sync_with_stdio(); cin.tie(0); cout.tie(0);
    
    cin >> N >> K >> P >> X;
    
    bitDiffCount();
    compareFloor();
    cout << answer << '\n';
    
    return 0;
}

void bitDiffCount() {
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            int diff = 0;
            
            for (int k = 0; k < 7; k++) {
                if (bit[i][k] != bit[j][k]) diff++;
            }
            change[i][j] = diff;
        }
    }
}

void compareFloor() {
    string curFloor = to_string(X);
    while (curFloor.length() < K) curFloor = "0" + curFloor;

    for (int i = 1; i <= N; i++) {
        if (i == X) continue;

        string targetFloor = to_string(i);
        while (targetFloor.length() < K) targetFloor = "0" + targetFloor;

        int count = 0;
        for (int k = 0; k < K; k++) {
            count += change[curFloor[k] - '0'][targetFloor[k] - '0'];
        }
        if (count <= P) answer++;
    }
}
