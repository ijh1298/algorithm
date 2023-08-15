#include <iostream>
#include <algorithm>

int N, M;
int arr[10], num[10], check[10];

void run(int len){
    if (len == M) {
        for (int i = 0; i < M; ++i)
            std::cout << arr[i] << ' ';
        std::cout << '\n';
        return;
    }

    int last = 0;
    for (int i = 0; i < N; ++i) {
        if (check[i] == 0 && num[i] != last) {
            arr[len] = num[i];
            last = arr[len];
            check[i] = 1;
            run(len + 1);
            check[i] = 0;
        }
    }
    return;
}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; ++i)
        std::cin >> num[i];

    std::sort(num, num + N);

    run(0);

    return 0;
}