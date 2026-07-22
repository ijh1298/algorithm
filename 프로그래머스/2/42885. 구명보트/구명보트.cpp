#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) { 
    vector<int> sorted = people;
    sort(sorted.begin(), sorted.end());
    deque<int> dq(sorted.begin(), sorted.end());
    
    int answer = 0;
    while (!dq.empty()) {
        if (dq.size() == 1) {
            dq.pop_back();
        } else {
            if (dq.front() + dq.back() > limit) {
                dq.pop_back();
            } else {
                dq.pop_back();
                dq.pop_front();
            }
        }
        answer++;
    }
    
    return answer;
}
