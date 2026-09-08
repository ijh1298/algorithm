#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    queue<int> qa, qb;
    
    for (auto a : A) qa.push(a);
    for (auto b : B) qb.push(b);
    
    int answer = 0;
    while (true) {
        if (qa.empty() || qb.empty()) break;
        
        int qb_front = qb.front();
        qb.pop();
        
        if (qa.front() < qb_front) {
            answer++;
            qa.pop();
        } 
    }
    return answer;
}
