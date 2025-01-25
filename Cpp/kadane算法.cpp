#include <iostream>
#include <vector>

using namespace std;

//最大子数组和
int kadane(vector<int> const& vec) {
    int max_sum = 0, current_sum = 0;
    for(int i = 0; i < vec.size(); ++i) {
        current_sum += vec[i];
        current_sum = current_sum < 0 ? 0 : current_sum;
        max_sum = max_sum < current_sum ? current_sum : max_sum;
    }
    return max_sum;
}

int main() {
    int n;
    cin>>n;
    vector<int> vec(n, 0);
    for(int i = 0; i < n; ++i) {
        int num = 0;
        cin>>num;
        vec[i] = num;
    }
    cout<<kadane(vec)<<endl;
}