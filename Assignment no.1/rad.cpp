#include <bits/stdc++.h>
using namespace std;

int minCostPath(vector<vector<int>>& grid, int n, int m) {
    const int INF = 1e9;
    vector<vector<int>> dp(n, vector<int>(m, INF));

    dp[0][0] = grid[0][0];

    for (int j = 1; j < m; j++) {
        if (dp[0][j-1] != INF)
            dp[0][j] = dp[0][j-1] + grid[0][j];
    }


    for (int i = 1; i < n; i++) {
        if (dp[i-1][0] != INF)
            dp[i][0] = dp[i-1][0] + grid[i][0];
    }


    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

         
            if (dp[i-1][j] != INF)
                dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);

            if (dp[i][j-1] != INF)
                dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);

            if ((grid[i-1][j-1] + grid[i][j]) % 2 == 0 &&
                dp[i-1][j-1] != INF) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + grid[i][j]);
            }
        }
    }

    return (dp[n-1][m-1] == INF) ? -1 : dp[n-1][m-1];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    cout << minCostPath(grid, n, m) << endl;

    return 0;
}