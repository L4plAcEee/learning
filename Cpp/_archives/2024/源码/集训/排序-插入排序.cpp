#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void _sort(vector<int> &vec) {
    if(vec.size() < 2) return;
    for(int i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        int j = i - 1;
        while(j >= 0 && vec[j] >= key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key; 
    }
}

void test_insert_sort() {
    vector<int> vec{1,3,2,6,9,7,5};
    vector<int> exp{1,2,3,5,6,7,9};
    _sort(vec);
    assert(exp == vec);
}

int main() {
    test_insert_sort();
    cout << "所有测试用例均通过！" << endl;
}