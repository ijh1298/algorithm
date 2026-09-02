#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> pq(works.begin(), works.end());
    
    // 최댓값 감소시키기
    while (n--) {
        int top = pq.top();
        pq.pop();
        
        if (top == 0) return 0;
        
        pq.push(top - 1);
    }
    
    long long answer = 0;
    while (!pq.empty()) {
        answer += (long long) pq.top() * pq.top();
        pq.pop();
    }
    return answer;
}
