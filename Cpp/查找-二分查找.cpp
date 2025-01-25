#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == target) {
            return mid;
        }
        else if(arr[mid] < target) {
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

void test_binarySearch() {
    vector<int> sortedVec = {1, 3, 3, 7, 7, 10, 500, 1000};
    assert(binarySearch(sortedVec, 7) == 3);
    assert(binarySearch(sortedVec, 10) == 5);
    assert(binarySearch(sortedVec, 1) == 0);
    assert(binarySearch(sortedVec, 1000) == 7);
    assert(binarySearch(sortedVec, 4) == -1);
}

int main() {
    test_binarySearch();
    cout << "所有测试用例均通过！" << endl;
}