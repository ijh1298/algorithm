#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int N, K;

int main() {
    int cnt = 0;
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            v.emplace_back(i);
           ++cnt;
        }
    }
    
    if (cnt < K) cout << 0;
    else cout << v[K - 1];
    
    return 0;
}