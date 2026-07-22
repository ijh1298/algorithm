#include <vector>
#include <algorithm>

using namespace std;

int path[100'000][4];

int solution(vector<vector<int> > land) {
    for (int i = 0; i < 4; i++) {
        path[0][i] = land[0][i];
    }
    
    // 자기 열을 제외한 다음 행의 다른 열들에게 자기 값을 합산
    for (int i = 0; i < land.size() - 1; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (j != k) {
                    path[i + 1][k] = max(path[i + 1][k], path[i][j] + land[i + 1][k]);
                }
            }
        }
    }
    
    // 마지막 행에서 최댓값 찾기
    int max = 0;
    for (int i = 0; i < 4; i++) {
        if (max < path[land.size() - 1][i]) max = path[land.size() - 1][i];
    }

    return max;
}
