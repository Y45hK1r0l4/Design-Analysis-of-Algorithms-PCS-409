
#include <iostream>
#include <vector>

using namespace std;

int matrixChainMultiplication(vector<int>& dims){
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int gap = 1; gap < n; gap++){
        for(int i = 0; i < n - gap; i++){
            int j = i + gap;
            dp[i][j] = INT_MAX;

            for(int k = i; k < j; k++){
                int cost = dp[i][k] + dp[k+1][j] + dims[i]*dims[k+1]*dims[j+1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> dims;

    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (i == 0) dims.push_back(a);
        dims.push_back(b);
    }

    int result = matrixChainMultiplication(dims);
    cout << result << endl;

    return 0;
}
