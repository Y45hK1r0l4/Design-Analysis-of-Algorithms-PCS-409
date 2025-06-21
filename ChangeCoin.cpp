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






#include <iostream>
#include <vector>
using namespace std;

int countPermutations(int x, const vector<int>& coins) {
    vector<int> dp(x + 1, 0);
    dp[0] = 1;  // Base case: one way to make sum 0

    for (int i = 1; i <= x; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] += dp[i - coin];
            }
        }
    }

    return dp[x];
}

int main() {
    int n, x;
    cout << "Enter number of coins: ";
    cin >> n;
    
    vector<int> coins(n);
    cout << "Enter coin values:\n";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter target sum: ";
    cin >> x;

    int result = countPermutations(x, coins);
    cout << "Total number of permutations to make " << x << " = " << result << endl;

    return 0;
}
