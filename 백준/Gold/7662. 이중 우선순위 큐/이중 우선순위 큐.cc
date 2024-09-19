#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        multiset<int> tree;
        for (int j = 0; j < N; j++) {
            char operation;
            int num;
            cin >> operation >> num;

            if (operation == 'I') {
                tree.insert(num);
            }
            else if (tree.size() != 0) {    
                if (num == -1)
                    tree.erase(tree.begin());
                else
                    tree.erase(prev(tree.end()));
            }
        }
        if (tree.empty()) cout << "EMPTY\n";
        else
            cout << *prev(tree.end()) << " " << *tree.begin() << "\n";
    }

    return 0;
}