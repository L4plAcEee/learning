#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int N, M, cache[MAXN] = {0};
queue<int> q;

int main() {
    cin >> M >> N;
    int word, cnt = 0;
    while (N--) {
        cin >> word;
        if (cache[word]) continue;
        else {
            cnt++;
            if (q.size() == M) {
                cache[q.front()] = 0;
                q.pop();
                q.push(word);
            } else {
                q.push(word);
            }
            cache[word] = 1;
        }
    }
    cout << cnt << '\n';
}