#include <iostream>
#include <vector>
using namespace std;

int countWays(vector<int>& coins, int sum) {
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;  // One way to make 0: use no coins

    for (int coin : coins) {
        for (int i = coin; i <= sum; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[sum];
}

int main() {
    vector<int> coins = {1, 2, 3};
    int sum = 4;

    cout << "Number of ways: " << countWays(coins, sum) << endl;
    return 0;
}
