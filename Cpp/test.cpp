#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 贪心算法
void greedyRefuel(vector<int>& stations, int capacity) {
    int n = stations.size();
    int currentFuel = capacity;
    int currentPos = 0;
    vector<int> refuelStations;
    
    for (int i = 0; i < n; i++) {
        int distance = (i == 0) ? stations[i] : stations[i] - stations[i-1];
        
        if (distance > capacity) {
            cout << "无法到达目的地" << endl;
            return;
        }
        
        currentFuel -= distance;
        
        if (i < n-1 && currentFuel < stations[i+1] - stations[i]) {
            refuelStations.push_back(i);
            currentFuel = capacity;
        }
    }
    
    cout << "贪心算法结果:" << endl;
    cout << "加油次数: " << refuelStations.size() << endl;
    cout << "加油站位置: ";
    for (int station : refuelStations) {
        cout << stations[station] << " ";
    }
    cout << endl;
}

// 动态规划
void dpRefuel(vector<int>& stations, int capacity) {
    int n = stations.size();
    vector<int> dp(n, INT_MAX);
    vector<int> prev(n, -1);
    
    // 初始化
    dp[0] = 0;
    
    for (int i = 1; i < n; i++) {
        int lastFuel = capacity;
        for (int j = i-1; j >= 0; j--) {
            int distance = stations[i] - (j == 0 ? 0 : stations[j]);
            if (distance > capacity) break;
            
            if (dp[j] != INT_MAX && dp[j] + 1 < dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }
    
    cout << "\n动态规划结果:" << endl;
    if (dp[n-1] == INT_MAX) {
        cout << "无法到达目的地" << endl;
        return;
    }
    
    cout << "最少加油次数: " << dp[n-1] << endl;
    
    // 重建路径
    vector<int> path;
    int curr = n-1;
    while (prev[curr] != -1) {
        path.push_back