#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;
using i64 = long long;
using f64 = double;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)

int N;

vector<int> merge(vector<int> &l, vector<int> &r) {
    int i = 0, j = 0, k = 0;
    vector<int> ret(l.size() + r.size());
    while (i < l.size() && j < r.size()) {
        if (l[i] <= r[j]) ret[k++] = l[i++];
        else ret[k++] = r[j++];
    }
    while (i < l.size()) ret[k++] = l[i++];
    while (j < r.size()) ret[k++] = r[j++];
    #ifdef LOCAL
    {
        cout << " value ret : \n";
        for (int i = 0; i < ret.size(); cout << ret[i++] << '\n');
    }
    #endif
    return ret;
}

vector<int> merge_sort(vector<int> &v, int l, int r) {
    if (l == r) return vector<int> {v[l]};

    int mid = (r - l) / 2 + l;
    vector<int> left = merge_sort(v, l, mid);
    vector<int> right = merge_sort(v, mid + 1, r);
    return merge(left, right);
}

void solve_in_merge_sort() {
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; cin >> vec[i++]);
    vec = merge_sort(vec, 0, vec.size() - 1);
    for (int i = 0; i < N; cout << vec[i++] << ' ');
}

int main() {
    solve_in_merge_sort();
    return 0;
}