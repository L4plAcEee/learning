#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 输入桶的容量和初始牛奶量
    vector<int> capacity(3), milk(3);
    for (int i = 0; i < 3; ++i) {
        cin >> capacity[i] >> milk[i];
    }
    
    // 进行100次倒牛奶操作
    for (int i = 0; i < 100; ++i) {
        int from = i % 3;       // 当前操作的源桶
        int to = (i + 1) % 3;   // 当前操作的目标桶
        
        // 计算倒奶量
        int pour_amount = min(milk[from], capacity[to] - milk[to]);
        
        // 更新桶中的牛奶量
        milk[from] -= pour_amount;
        milk[to] += pour_amount;
    }
    
    // 输出结果
    for (int i = 0; i < 3; ++i) {
        cout << milk[i] << endl;
    }
    return 0;
}
