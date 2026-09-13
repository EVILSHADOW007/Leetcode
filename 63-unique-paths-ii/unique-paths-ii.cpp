class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& obstacleGrid, int i, int j) {
        if (i >= m || j >= n || obstacleGrid[i][j] == 1)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = solve(obstacleGrid, i + 1, j) + solve(obstacleGrid, i, j + 1);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        dp.assign(m, vector<int>(n, -1));

        return solve(obstacleGrid, 0, 0);
    }
};