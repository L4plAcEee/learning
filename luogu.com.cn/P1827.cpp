#include <bits/stdc++.h>
using namespace std;

string preorder, inorder;
int node[26][2];
unordered_map<char, int> in_map;
int pre_idx = 0;

int build(int in_l, int in_r) {
    if (in_l > in_r) return -1;

    char root = preorder[pre_idx++];
    int root_pos = in_map[root];

    node[root - 'A'][0] = build(in_l, root_pos - 1);
    node[root - 'A'][1] = build(root_pos + 1, in_r);

    return root - 'A';
}

void postorder(int root) {
    if (root == -1) return;
    postorder(node[root][0]);
    postorder(node[root][1]);
    cout << (char)(root + 'A');
}

int main() {
    cin >> inorder >> preorder;
    for (int i = 0; i < inorder.size(); ++i)
        in_map[inorder[i]] = i;

    int root = build(0, inorder.size() - 1);
    postorder(root);
    cout << '\n';
}
