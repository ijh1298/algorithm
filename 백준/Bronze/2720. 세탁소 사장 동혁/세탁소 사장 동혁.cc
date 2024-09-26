#include <iostream>
using namespace std;
int T, money;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        int Q = 0;
        int D = 0;
        int N = 0;
        int P = 0;
        cin >> money;

        while (money) {
            if (money >= 25) {
                Q++;
                money -= 25;
            }
            else if (money >= 10) {
                D++;
                money -= 10;
            }
            else if (money >= 5) {
                N++;
                money -= 5;
            }
            else {
                P++;
                money -= 1;
            }
        }
        cout << Q << " " << D << " " << N << " " << P << "\n";
    }
}