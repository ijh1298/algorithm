#include <string>
#include <vector>

#define MAX 10001

using namespace std;

int acc_sum[MAX];

int solution(int n) {
    int answer = 0;
    
    // 누적합 생성
    for (int i = 0; i < MAX; i++) {
        acc_sum[i] = i;
    }
    for (int i = 1; i < MAX; i++) {
        acc_sum[i] += acc_sum[i - 1];
    }
    
    // 투포인터
    int l = 1, r = 1;
    
    while (l <= r) {
        int result = acc_sum[r] - acc_sum[l - 1];
        
        if (result == n) {
            answer++; l++; r++;
        }
        else if (result > n) l++;
        else r++;
    }
    
    return answer;
}
