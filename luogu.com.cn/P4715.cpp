#include <bits/stdc++.h>
using namespace std;

const int MAXN = 7;
int n;
int a[1 + (1 << MAXN)]; // 能力值，下标从1开始
int node_val[1 << (MAXN + 1)]; // 每个节点存储胜者的编号

// 递归建树，返回当前节点的胜者编号
int build_tree(int id, int l, int r) {
    if (l == r) {
        node_val[id] = l; // 叶子节点存国家编号
        return node_val[id];
    }
    int mid = (l + r) / 2;
    int left = build_tree(id * 2, l, mid);
    int right = build_tree(id * 2 + 1, mid + 1, r);

    // 比较能力值，选出胜者编号
    node_val[id] = (a[left] > a[right] ? left : right);
    return node_val[id];
}

int main() {
    cin >> n;
    int total = 1 << n;

    for (int i = 1; i <= total; ++i)
        cin >> a[i];

    int champion = build_tree(1, 1, total); // 构建树并得到冠军编号

    // 亚军是倒数第二场的败者，即根节点两个子树中落败的那个
    int left = node_val[2], right = node_val[3];
    int runner_up = (a[left] > a[right] ? right : left);

    cout << runner_up << endl;
    return 0;
}
