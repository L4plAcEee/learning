#include <bits/stdc++.h>
using namespace std;

string A, B;
vector<pair<string, string>> rules;

void bfs() {
    int depth = 0;
    queue<string> q;
    unordered_set<string> visited;
    q.push(A);
    visited.insert(A);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            string s = q.front();q.pop();
            for (auto &rule : rules) {
                auto [pattern, replacement] = rule;

                for (size_t pos = s.find(pattern); pos != string::npos; pos = s.find(pattern, pos + 1)) {
                    string new_str = s;
                    new_str.replace(pos, pattern.length(), replacement);

                    if (new_str == B) {
                        cout << depth + 1 << '\n';
                        return;
                    }

                    if (visited.find(new_str) == visited.end()) {
                        visited.insert(new_str);
                        q.push(new_str);
                    }
                }        
            }
        }
        depth++;
        if (depth > 10) break;
    }
    cout << "NO ANSWER!" << '\n';
}

int main() {
    cin >> A >> B;

    string line;
    while (getline(cin, line)) {
        istringstream ls(line);
        string a, b;
        if (ls >> a >> b) {
            rules.emplace_back(a, b);
        }
    }
    bfs();
}