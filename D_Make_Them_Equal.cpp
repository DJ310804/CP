#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_B = 1000;

vector<int> compute_min_steps() {
    vector<int> dp(MAX_B + 1, 1e9);
    dp[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int x = 1; x <= u; ++x) {
            int step = u / x;
            if (step == 0) continue;
            int v = u + step;
            if (v > MAX_B) continue;
            if (dp[v] > dp[u] + 1) {
                dp[v] = dp[u] + 1;
                q.push(v);
            }
        }
    }
    return dp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto dp = compute_min_steps();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> b(n);
        for (auto &x : b) cin >> x;
        vector<int> c(n);
        for (auto &x : c) cin >> x;

        vector<pair<int, int>> items;
        int sum_steps = 0;
        int total_c = 0;

        for (int i = 0; i < n; ++i) {
            int target = b[i];
            int steps = dp[target];
            if (steps > k) continue;
            items.emplace_back(steps, c[i]);
            sum_steps += steps;
            total_c += c[i];
        }

        if (sum_steps <= k) {
            cout << total_c << '\n';
            continue;
        }

        vector<int> knapsack(k + 1, 0);
        for (auto &item : items) {
            int s = item.first;
            int val = item.second;
            for (int j = k; j >= s; --j) {
                knapsack[j] = max(knapsack[j], knapsack[j - s] + val);
            }
        }

        int ans = *max_element(knapsack.begin(), knapsack.end());
        cout << ans << '\n';
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>
// using namespace std;
 
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     cin >> t;
//     const int MAX = 1000;
    
//     // Precompute minimum operations from 1 to any value up to MAX.
//     // dp[v] = minimum operations to reach exactly v starting from 1.
//     vector<int> dp(MAX + 1, INT_MAX);
//     dp[1] = 0;
//     for (int a = 1; a <= MAX; a++){
//         if(dp[a] == INT_MAX) continue;
//         // For each valid x from 1 to a:
//         for (int x = 1; x <= a; x++){
//             int add = a / x;  // floor(a/x)
//             int next = a + add;
//             if(next <= MAX){
//                 dp[next] = min(dp[next], dp[a] + 1);
//             }
//         }
//     }
    
//     while(t--){
//         int n, k;
//         cin >> n >> k;
//         vector<int> b(n), c(n);
//         for (int i = 0; i < n; i++){
//             cin >> b[i];
//         }
//         for (int i = 0; i < n; i++){
//             cin >> c[i];
//         }
        
//         // For each index, the cost is the precomputed dp[b[i]].
//         // Since dp[b[i]] is small, the maximum total cost if we take all indices is small.
//         int totalCost = 0;
//         for (int i = 0; i < n; i++){
//             totalCost += dp[b[i]];
//         }
//         // The effective capacity we need is the minimum between k and totalCost.
//         int cap = min(k, totalCost);
        
//         // 0/1 knapSack DP: dp_knap[j] is the maximum coins achievable with j operations.
//         vector<int> dp_knap(cap + 1, 0);
//         for (int i = 0; i < n; i++){
//             int cost = dp[b[i]];
//             int value = c[i];
//             // Traverse backwards so that each item is used at most once.
//             for (int j = cap; j >= cost; j--){
//                 dp_knap[j] = max(dp_knap[j], dp_knap[j - cost] + value);
//             }
//         }
//         cout << dp_knap[cap] << "\n";
//     }
    
//     return 0;
// }
