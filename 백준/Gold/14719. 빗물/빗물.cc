/*
* 빗물 알고리즘
* 
* 1. 첫 번째 기둥을 A라고 잡는다.
* 2-1. (남은 기둥 중에 A보다 큰 게 있으면) 그것이 기둥 B가 된다. 
* 2-2. (남은 기둥 중에 A보다 큰 게 없으면) 남은 것 중 가장 큰 게 기둥 B가 된다.
* 3. A ~ B 구간을 더한다. 기둥 B는 다음 차례의 기둥 A가 된다.
* 4. 반복
*/
#include <iostream>
#include <vector>

std::vector<int> v;
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int H, W;
    std::cin >> H >> W;

    for (int i = 0; i < W; ++i) {
        int input;
        std::cin >> input;
        v.push_back(input);
    }

    std::pair<int, int> A, B;

    //기둥 A 설정
    for (int i = 0; i < W; ++i) {
        if (v[i]) {
            A.first = i;
            A.second = v[i];
            break;
        }
    }

    int sum = 0;

    while (B.first != W - 1) {
        bool type = 1;
        //기둥 B 설정 
        //1. 기둥 A보다 크거나 같은 지점이 있는가
        for (int i = A.first + 1; i < W; ++i) {
            if (A.second <= v[i]) {
                B.first = i;
                B.second = v[i];

                for (int j = A.first + 1; j < B.first; ++j)
                    sum += (std::min(A.second, B.second) - v[j]);

                A.first = B.first;
                A.second = B.second;

                type = 0;

                break;
            }
        }

        //기둥 B 설정 
        //2. 기둥 A보다 큰 게 없다면, 남은 기둥 중 최대 높이인 기둥을 B 설정
        if (type) {
            B = { 0, 0 };
            for (int i = A.first + 1; i < W; ++i)
                if (v[i] > B.second) {
                    B.first = i;
                    B.second = v[i];
                }

            for (int i = A.first + 1; i < B.first; ++i)
                sum += (std::min(A.second, B.second) - v[i]);

            //될 수 있는 B 기둥이 없다면
            if (!B.first)
                break;

            A.first = B.first;
            A.second = B.second;
        }
    }

    std::cout << sum;

    return 0;
}