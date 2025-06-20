#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int unboundedKnapsack(int W, const vector<int>& wt, const vector<int>& val) {
    vector<int> dp(W + 1, 0);

    for (int w = 0; w <= W; w++) {
        for (int i = 0; i < wt.size(); i++) {
            if (wt[i] <= w) {
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
    }

    // Print DP table for visualization
    cout << "DP table: ";
    for (int i = 0; i <= W; i++)
        cout << dp[i] << " ";
    cout << endl;

    return dp[W];
}

int main() {
    vector<int> wt = {2, 3, 4};
    vector<int> val = {40, 50, 100};
    int W = 6;

    int result = unboundedKnapsack(W, wt, val);
    cout << "Maximum value in unbounded knapsack of capacity " << W << " = " << result << endl;

    return 0;
}
