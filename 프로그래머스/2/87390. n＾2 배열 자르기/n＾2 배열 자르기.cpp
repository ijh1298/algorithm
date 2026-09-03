#include <vector>

using namespace std;

vector<int> answer;

// left(right)를 x행 y번으로 변환해서 반환
pair<int, int> lrToPoint(int n, long long lr) {
    pair<int, int> p = { lr / n, lr % n };
    return p;
}

// idx행 배열의 수 리스트를 answer vector에 저장
void addRow(int n, int idx, int start, int end) {
    int cur = idx + 1;
    
    for (int i = 0; i < n; i++) {
        if (i >= start && i <= end) answer.push_back(cur);        
        if (i + 1 == cur) cur++;
    }
}

vector<int> solution(int n, long long left, long long right) {
    pair<int, int> leftP = lrToPoint(n, left);
    pair<int, int> rightP = lrToPoint(n, right);
    
    if (leftP.first == rightP.first) {
        addRow(n, leftP.first, leftP.second, rightP.second);
    }
    else {
        addRow(n, leftP.first, leftP.second, n);
        for (int i = leftP.first + 1; i < rightP.first; i++) {
            addRow(n, i, 0, n);
        }
        addRow(n, rightP.first, 0, rightP.second);
    }
    
    return answer;
}
