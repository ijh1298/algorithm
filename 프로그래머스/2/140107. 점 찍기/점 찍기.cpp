#include <string>
#include <vector>
#include <cmath>

#define MAX 1'000'000

using namespace std;

long long solution(int k, int d) {
    long long cnt = 0;
    
    long long kSquare = (long long)k * k;
    long long dSquare = (long long)d * d;
    
    for (long long x = 0; x <= MAX; x++) {
        long long xSquare = x * x * kSquare;
        
        if (xSquare > dSquare) break; // 조기 종료
        
        long long ySquareMax = dSquare - xSquare;
        long long y = sqrt(ySquareMax / kSquare);
        cnt += y + 1; // 0부터 시작하기 때문에 +1
    }
    return cnt;
}
