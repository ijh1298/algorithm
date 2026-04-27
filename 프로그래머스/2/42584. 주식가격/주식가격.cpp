#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    deque<int> dq; // 값 대신 index 저장
    
    for (int i = 0; i < prices.size(); i++) {
        while (!dq.empty() && prices[i] < prices[dq.back()]) {
            int idx = dq.back();
            dq.pop_back();
            answer[idx] = i - idx;
        }
        dq.push_back(i);
    }
    
    while (!dq.empty()) {
        int idx = dq.back();
        dq.pop_back();
        answer[idx] = prices.size() - 1 - idx;
    }
    
    return answer;
}
