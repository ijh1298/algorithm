#include <iostream>
#include <vector>

//두 MBTI 간 거리 구하기
int dist(std::string first, std::string second, std::string third) {
    int d = 0;
    for (int i = 0; i < 4; ++i)
        d += (first[i] != second[i]) + (first[i] != third[i]) + (second[i] != third[i]);
    return d;
}

int main(){
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i){
        int N;
        std::cin >> N;

        int sum = 0;
        std::vector<std::string> v;

        for (int i = 0; i < N; ++i){
            std::string mbti;
            std::cin >> mbti;
            v.push_back(mbti);
        }

        /* 비둘기집 원리 :
        * n+1 마리의 비둘기가 n개의 비둘기집에 들어가려면 최소한 한 개의 비둘기집에는 두 마리 이상의 비둘기가 들어가야 한다는 원리
        * N이 33부터는 16 종류의 MBTI 중 같은 MBTI인 사람이 3명 이상 무조건 존재하게 됨
        * 따라서 N이 33 이상에서 3명의 최소 거리는 0이 됨
        */
        if (N > 16 * 2) {
            std::cout << 0 << '\n';
            continue;
        }

        int min = 9999999;
        //선형 탐색으로 3명씩 나누어 거리를 구하고 최소값을 도출
        for (int a = 0; a < N; ++a)
            for (int b = a + 1; b < N; ++b)
                for (int c = b + 1; c < N; ++c)
                    min = std::min(min, dist(v[a], v[b], v[c]));

        /* 비둘기집 원리 :
        * n+1 마리의 비둘기가 n개의 비둘기집에 들어가려면 최소한 한 개의 비둘기집에는 두 마리 이상의 비둘기가 들어가야 한다는 원리
        * N이 33부터는 16 종류의 MBTI 중 같은 MBTI인 사람이 3명 이상 무조건 존재하게 됨
        * 따라서 N이 33 이상에서 3명의 최소 거리는 0이 됨
        */
        std::cout << min << '\n';
    }

    return 0;
}