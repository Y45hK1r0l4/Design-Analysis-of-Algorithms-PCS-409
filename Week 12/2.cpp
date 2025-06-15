
#include <iostream>
#include <vector>
using namespace std;

void knapsack01(int n, vector<int>& weights, vector<int>& values, int W) {
    // Create DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Maximum value
    cout << "Value = " << dp[n][W] << endl;

    // Trace back to find selected items
    int w = W;
    vector<int> selectedWeights, selectedValues;

    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedWeights.push_back(weights[i - 1]);
            selectedValues.push_back(values[i - 1]);
            w -= weights[i - 1];
        }
    }

    // Output selected weights
    cout << "Weights selected : ";
    for (int i = selectedWeights.size() - 1; i >= 0; i--) {
        cout << selectedWeights[i] << " ";
    }
    cout << endl;

    // Output selected values
    cout << "Values of selected weights : ";
    for (int i = selectedValues.size() - 1; i >= 0; i--) {
        cout << selectedValues[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> weights(n), values(n);
    for (int i = 0; i < n; i++) cin >> weights[i];
    for (int i = 0; i < n; i++) cin >> values[i];

    int W;
    cin >> W;

    knapsack01(n, weights, values, W);

    return 0;
}
