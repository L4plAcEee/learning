#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, q;
    cin>>n>>m>>q;
    vector<int> vec(n + 1, 0);
    int num;
    int pre_num = 0;
    for(int i = 1; i < vec.size(); ++i) {
        cin>>num;
        vec[i] = num - pre_num;
        pre_num = num;
    }
    printf("打印数组：");
    for(auto it : vec) {
        printf("%d", it);
    }
    printf("\n");
    while(m--) {
        int l, r ,d;
        cin>>l>>r>>d;
        vec[l] += d;
        if(r + 1 <= n) vec[r + 1] -= d;
    }
    printf("打印数组：");
    for(auto it : vec) {
        printf("%d", it);
    }
        printf("\n");
    for(int i = 1; i < vec.size(); ++i) {
        vec[i] += vec[i - 1];
    }
    printf("打印数组：");
    for(auto it : vec) {
        printf("%d", it);
    }
        printf("\n");
    while(q--) {
        int x;
        cin>>x;
        cout<<vec[x]<<endl;
    }
}