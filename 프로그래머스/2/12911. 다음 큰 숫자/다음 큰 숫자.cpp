#include <string>
#include <vector>

#define MAX 1'000'001

using namespace std;

int count[MAX];

// 1비트 개수 반환
int countBit(int n) {
    int cur = n;
    int oneBitCnt = 0;
    
    while (cur != 0) {
        if (cur % 2 != 0) oneBitCnt++;
        cur >>= 1;
    }
    
    return oneBitCnt;
}

int solution(int n) {
    int target = countBit(n);
    
    for (int i = n + 1; i < MAX; i++) {
        if (target == countBit(i)) {
            return i;
        }
    }
    return 0;
}
