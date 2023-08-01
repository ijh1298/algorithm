/*
* 좌표에 해당하는 사분면으로 들어가는 재귀함수 구성
* 
* 예제)
* N = 3일 때 0 ~ 63 범위일 때 quarter를 16으로 잡고
* x = 0, y = 63으로 시작
* 제1사분면 (x ~ y - q * 3), 제2사분면 (x + q ~ y - q * 2)
* 제3사분면 (x + q * 2 ~ y - q), 제4사분면 (x + q * 3 ~ y) 으로 분기
*/

#include <iostream>
#include <cmath>

void quadrant(int n, int r, int c, int x, int y, int quarter) {
    if (n == 1) {
        std::cout << x;
        return;
    }
    quarter /= 4;
    //1사분면
    if (r < n / 2 && c < n / 2)
        quadrant(n / 2, r, c, x, y - quarter * 3, quarter);
    //2사분면
    else if (r < n / 2 && c >= n / 2)
        quadrant(n / 2, r, c - n / 2, x + quarter, y - quarter * 2, quarter);
    //3사분면 
    else if (r >= n / 2 && c < n / 2)
        quadrant(n / 2, r - n / 2, c, x + quarter * 2, y - quarter, quarter);
    //4사분면
    else if (r >= n / 2 && c >= n / 2)
        quadrant(n / 2, r - n / 2, c - n / 2, x + quarter * 3, y, quarter);

}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int N, r, c;
    std::cin >> N >> r >> c;

    int n = pow(2, N);
    quadrant(n, r, c, 0, n * n - 1, n * n);

    return 0;
}