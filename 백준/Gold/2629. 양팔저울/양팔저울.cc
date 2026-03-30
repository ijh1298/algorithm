#include <iostream>
#include <vector>

#define MAX_WEIGHT 40'000

using namespace std;

bool visited[31][MAX_WEIGHT + 1];
int weight, pearl, totalWeight;
vector<int> weights, pearls;

void input();
void getTotalWeight();
void checkWeight(int idx);
void checkPossiblePearls();

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    getTotalWeight();
    for (int i = 0; i < weight; i++) {
        checkWeight(i);
    }
    checkPossiblePearls();

    return 0;
}

void input() {
    cin >> weight;
    for (int i = 0; i < weight; i++) {
        int w;
        cin >> w;
        weights.push_back(w);
    }

    cin >> pearl;
    for (int i = 0; i < pearl; i++) {
        int p;
        cin >> p;
        pearls.push_back(p);
    }
}

void getTotalWeight() {
    int sum = 0;
    for (auto w : weights) {
        sum += w;
    }
    totalWeight = sum;
}

void checkWeight(int idx) {
    int weight = weights[idx];
    visited[idx][weight] = true;

    if (idx == 0) return;

    int prevIdx = idx - 1;
    for (int i = 1; i <= totalWeight; i++) {
        if (visited[prevIdx][i]) {
            visited[idx][i] = true;
            visited[idx][i + weight] = true;
            visited[idx][abs(i - weight)] = true;
        }
    }
}

void checkPossiblePearls() {
    for (auto pearl : pearls) {
        if (visited[weight - 1][pearl]) cout << "Y ";
        else cout << "N ";
    }
}
