#include <bits/stdc++.h>
using namespace std;

int n, maxLen = 0;
string longestStr;
vector<string> words;
int used[21];

void dfs(string curr) {
    if (curr.size() > longestStr.size()) {
        longestStr = curr;
    }

    for (int i = 0; i < n; ++i) {
        if (used[i] < 2) {
            int maxOverlap = min(curr.size(), words[i].size()) - 1;
            for (int overlap = 1; overlap <= maxOverlap; ++overlap) {
                if (curr.substr(curr.size() - overlap) == words[i].substr(0, overlap)) {
                    used[i]++;
                    dfs(curr + words[i].substr(overlap));
                    used[i]--;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    words.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    char start;
    cin >> start;

    for (int i = 0; i < n; ++i) {
        if (words[i][0] == start) {
            used[i]++;
            dfs(words[i]);
            used[i]--;
        }
    }

    cout << longestStr.length() << '\n';

    return 0;
}
