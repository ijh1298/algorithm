#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int answer = 0;
    
    while (!pq.empty()) {
        int bottom1 = pq.top(); pq.pop();
        
        if (bottom1 >= K) break;
        if (pq.empty()) return -1;
        
        int bottom2 = pq.top(); pq.pop();
        
        pq.push(bottom1 + bottom2 * 2);
        answer++;
    }
    
    return answer;
}
