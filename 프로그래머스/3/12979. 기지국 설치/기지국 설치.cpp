#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w) {
    int l, r, answer = 0;
    
    l = 1; 
    r = stations[0] - w - 1;
    if (l <= r) {
        // (r - l + 1) / (1 + 2 * w) : l ~ r 구간에 필요한 기지국 개수
        answer += (r - l + 1) / (1 + 2 * w);
        // 나누어 떨어지지 않을 경우 +1
        if ((r - l + 1) % (1 + 2 * w) != 0) answer++;
    }
    
    for (int i = 0; i < stations.size() - 1; i++) {
        l = stations[i] + w + 1;
        r = stations[i + 1] - w - 1;
        
        if (l > r) continue;
        
        answer += (r - l + 1) / (1 + 2 * w);
        if ((r - l + 1) % (1 + 2 * w) != 0) answer++;
    }
    
    l = stations[stations.size() - 1] + w + 1;
    r = n;
    if (l <= r) {
        answer += (r - l + 1) / (1 + 2 * w);
        if ((r - l + 1) % (1 + 2 * w) != 0) answer++;
    }

    return answer;
}
