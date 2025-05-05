// P1328 [NOIP 2014 提高组] 生活大爆炸版石头剪刀布
// https://www.luogu.com.cn/problem/P1328
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res = {
    //  0   1   2   3   4
    {  0, -1,  1,  1, -1 }, // 0 剪刀 -> 胜布(2)、蜥蜴(3)，败石头(1)、斯波克(4)
    {  1,  0, -1,  1, -1 }, // 1 石头 -> 胜剪刀(0)、蜥蜴(3)，败布(2)、斯波克(4)
    { -1,  1,  0, -1,  1 }, // 2 布   -> 胜石头(1)、斯波克(4)，败剪刀(0)、蜥蜴(3)
    { -1, -1,  1,  0,  1 }, // 3 蜥蜴 -> 胜布(2)、斯波克(4)，败石头(1)、剪刀(0)
    {  1,  1, -1, -1,  0 }  // 4 斯波克 -> 胜石头(1)、剪刀(0)，败布(2)、蜥蜴(3)
};

int main() {
    int N, NA, NB;
    cin >> N >> NA >> NB;
    vector<int> rgA(NA, 0);
    for (int i = 0; i < NA; ++i) {
        cin >> rgA[i];
    }
    vector<int> rgB(NB, 0); 
    for (int i = 0; i < NB; ++i) {
        cin >> rgB[i];
    }
    int scoreA = 0, scoreB = 0;
    for (int round = 0; round < N; ++round) {
        int a = rgA[round % NA]; // A 的手势（循环使用）
        int b = rgB[round % NB]; // B 的手势（循环使用）
        int result = res[a][b];  // 判断胜负关系
    
        if (result == 1) {
            scoreA++;
        } else if (result == -1) {
            scoreB++;
        }
    }
    cout << scoreA << " " << scoreB << endl;    
    return 0;
}