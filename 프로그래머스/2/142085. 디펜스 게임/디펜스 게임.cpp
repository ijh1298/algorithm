#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 그리디 : n보다 enemy 총합이 커지면 가장 큰 enemy 제거 후 무적권 개수 감소
priority_queue<int> pq;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    int totalEnemy = 0;
    for (int i = 0; i < enemy.size(); i++) {
        totalEnemy += enemy[i];
        pq.push(enemy[i]);
        
        if (totalEnemy > n) {
            if (k > 0) {
                k--;
                totalEnemy -= pq.top();
                pq.pop();
            } else {
                // 무적권 다 사용했을 경우 종료
                return i;
            }
        }
    }
    return enemy.size();
}
