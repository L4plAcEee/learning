#include <bits/stdc++.h>
using namespace std;

// 简洁结构
using u64 = unsigned long long;
using i64 = long long;
using f64 = double;
using u32 = unsigned int;
using i32 = int;
using f32 = float;

using pii = pair<int, int>;

// 快速宏定义
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

// 快速遍历
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for (int i = (a); i >= (b); --i)
#define EACH(x, a) for (auto& x : a)

// 简洁常用结构
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

// 快速类型别名
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

// 调试输出（比赛用时建议注释掉）
#define debug(x) cerr << #x << " = " << x << '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define endl '\n'  // 替代换行，加速输出（但在调试器下慎用）
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

template<typename T>
void printVec(const vector<T>& v, char sep = ' ') {
    for (const auto& x : v) cout << x << sep;
    cout << '\n';
}

// 编译时加 -DLOCAL 就能启用调试模式。
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << '\n'
#else
#define debug(x)
#endif
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll fastpow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}


void say_hello() {
    time_t t = chrono::system_clock::to_time_t(chrono::system_clock::now());

    printf("Hello Cstdio, Current time: %s\n", ctime(&t)); // ✅ C风格输出
    cout << "Hello C++ iostream!" << endl; // ✅ C++ 风格输出
    cout << format("Hello C++20 format!\n"); // ✅ C++20 格式化输出
}


int main() {
    i32 a = 1;
    cin >> a;
    cout << " a = " << a << '\n';
    FAST_IO;
    say_hello();

    return 0;
}

