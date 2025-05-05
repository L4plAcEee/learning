#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x)
#endif

// struct fastio {
//     fastio() {
//         ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     }
// } fastio;

int n;

struct player {
    string name, job;
    int score, level;
    int input_order; // 添加输入顺序
    player(string name, string job, int score, int level, int order)
        : name(name), job(job), score(score), level(level), input_order(order) {};
    player(){};
};

map<string , int> mapper = {
    {"BangZhu", 1},
    {"FuBangZhu", 2},
    {"HuFa", 3},
    {"ZhangLao", 4},
    {"TangZhu", 5},
    {"JingYing", 6},
    {"BangZhong", 7}
};

map<string, int> m = {
    // {"BangZhu", 1},
    // {"FuBangZhu", 2},
    {"HuFa", 2},
    {"ZhangLao", 4},
    {"TangZhu", 7},
    {"JingYing", 25}
    // {"BangZhong", INT_MAX}
};

void solve() {
    cin >> n;
    vector<player> v; // 初始化为空vector
    vector<player> v2;
    for (int i = 0; i < n; i++) {
        string name, job;
        int score, level;
        cin >> name >> job >> score >> level;
        if (job == "BangZhu" || job == "FuBangZhu") v2.emplace_back(name, job, score, level, i);
        else v.emplace_back(name, job, score, level, i);
    }
    #ifdef LOCAL
    {
        cout << '\n' << "--Debug--" << '\n';
        for(auto &it : v) {
            debug(it.name);
            debug(it.job);
            debug(it.score);
            debug(it.level);
            debug(it.input_order);
        }
        cout << '\n' <<"--End Debug--" << '\n';
    }
    #endif
    stable_sort(v.begin(), v.end(), [](auto const &a, auto const &b) {
        return a.score > b.score;
    });
    
    for_each(v.begin(), v.end(), [](auto &a){
        if (a.job != "BangZhu" && a.job != "FuBangZhu") {
            if (m["HuFa"]) {
                a.job = "HuFa";
                m["HuFa"]--;
            } else if (m["ZhangLao"]) {
                a.job = "ZhangLao";
                m["ZhangLao"]--;
            } else if (m["TangZhu"]) {  // 添加堂主的处理
                a.job = "TangZhu";
                m["TangZhu"]--;
            } else if (m["JingYing"]) {
                a.job = "JingYing";
                m["JingYing"]--;
            } else {
                a.job = "BangZhong";
            }
        }
    });

    stable_sort(v.begin(), v.end(), [](auto const &a, auto const &b){
        if (a.job != b.job) {
            return mapper[a.job] < mapper[b.job];
        } else if (a.level != b.level) {
            return a.level > b.level;
        } else {
            return a.input_order < b.input_order;  // 当职位和等级相同时，按输入顺序排序
        }
    });

    stable_sort(v2.begin(), v2.end(), [](auto const &a, auto const &b){
        if (a.job != b.job) {
            return mapper[a.job] < mapper[b.job];
        } else if (a.level != b.level) {
            return a.level > b.level;
        } else {
            return a.input_order < b.input_order;  // 当职位和等级相同时，按输入顺序排序
        }
    });

    for (auto &it : v2) {
        cout << it.name << ' ' <<  it.job << ' ' << it.level << '\n';
    }

    for(auto &it : v) {
        cout << it.name << ' ' <<  it.job << ' ' << it.level << '\n';
    }
}

int main() {
    #ifdef LOCAL
    cout << "-- start ! --" << '\n';
    #endif
    solve();
}