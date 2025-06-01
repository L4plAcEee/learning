#include <bits/stdc++.h>
using namespace std;

struct Coin {
    int mass;
    int value;
    double unit_value;
};

int main() {
    int N, T;
    cin >> N >> T;

    vector<Coin> coins(N);
    for (int i = 0; i < N; ++i) {
        cin >> coins[i].mass >> coins[i].value;
        coins[i].unit_value = 1.0 * coins[i].value / coins[i].mass;
    }

    sort(coins.begin(), coins.end(), [](const Coin &a, const Coin &b) {
        return a.unit_value > b.unit_value;
    });

    double ans = 0;
    int weight = 0;
    for (int i = 0; i < N && weight < T; ++i) {
        int take = min(coins[i].mass, T - weight);
        ans += take * coins[i].unit_value;
        weight += take;
    }

    cout << fixed << setprecision(2) << ans << '\n';
    return 0;
}
