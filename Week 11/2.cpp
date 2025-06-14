#include <iostream>
#include <vector>
using namespace std;

int countWaysToMakeSum(int N, vector<int>& coins) {
    vector<int> dp(N + 1, 0);
    dp[0] = 1;  // 1 way to make sum 0 (use no coins)

    for (int coin : coins) {
        for (int i = coin; i <= N; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[N];
}

int main() {
    int coinCount;
    cin >> coinCount;

    vector<int> coins(coinCount);
    for (int i = 0; i < coinCount; i++) {
        cin >> coins[i];
    }

    int targetSum;
    cin >> targetSum;

    int ways = countWaysToMakeSum(targetSum, coins);
    cout << ways << endl;

    return 0;
}
