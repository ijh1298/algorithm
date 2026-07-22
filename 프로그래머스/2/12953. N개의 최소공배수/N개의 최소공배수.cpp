#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    int GCD = gcd(a, b);
    return (a * b) / GCD;
}

int solution(vector<int> arr) {
    int LCM = lcm(arr[0], arr[1]);
    for (int i = 2; i < arr.size(); i++) {
        LCM = lcm(LCM, arr[i]);
    }
    return LCM;
}
