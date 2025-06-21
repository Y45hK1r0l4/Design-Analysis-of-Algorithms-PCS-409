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






#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCutting(const vector<int>& price, int N) {
    vector<int> dp(N + 1, 0);  // dp[i] = max value for rod of length i

    for (int len = 1; len <= N; ++len) {
        for (int cut = 1; cut <= len; ++cut) {
            dp[len] = max(dp[len], price[cut - 1] + dp[len - cut]);
        }
    }

    // Print the DP table
    cout << "\nDP table:\n";
    for (int i = 0; i <= N; i++)
        cout << "dp[" << i << "] = " << dp[i] << "\n";

    return dp[N];
}

int main() {
    int N;
    cout << "Enter the length of the rod: ";
    cin >> N;

    vector<int> price(N);
    cout << "Enter the price for each length from 1 to " << N << ":\n";
    for (int i = 0; i < N; ++i)
        cin >> price[i];

    int maxValue = rodCutting(price, N);
    cout << "\nMaximum obtainable value = " << maxValue << endl;

    return 0;
}

