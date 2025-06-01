#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    // 直接使用STL的next_permutation函数
    for (int i = 0; i < m; i++) {
        if (!next_permutation(sequence.begin(), sequence.end())) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << sequence[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}
