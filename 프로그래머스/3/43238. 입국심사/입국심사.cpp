#include <vector>
#include <algorithm>

using namespace std;

long long answer = 1e18;

// bTime 기준 몇 명까지 처리하는지 반환
long long getN(long long bTime, vector<int>& times) {
    long long N = 0;
    for (auto time : times) {
        N += bTime / time;
    }
    return N;
}

// 1e18 이하의 time을 이분 탐색
void bsearch(int n, long long l, long long r, vector<int>& times) {    
    if (l >= r) return;
    
    long long mid = (l + r) / 2;
    
    long long N = getN(mid, times);
    
    // 목표 n보다 처리 가능 인원이 작을 때
    if (n > N) {
        bsearch(n, mid + 1, r, times);
    } 
    // 목표 n보다 처리 가능 인원이 클 때
    else {
        answer = min(answer, mid);
        // 더 작은 값 있는지 탐색
        bsearch(n, l, mid, times);
    }
}

long long solution(int n, vector<int> times) {
    bsearch(n, 0, 1e18, times);
    return answer;
}
