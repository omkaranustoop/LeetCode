class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)return 0;
        // Defining DP Array
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2,0)));
        // Initializing buy states of DP array as INT_MIN to ensure transactions happen
        for(int i = 0;i<n;i++){
            dp[i][0][0] = INT_MIN;
            dp[i][1][0] = INT_MIN;
        }
        // Base value initialization
        dp[0][0][0] = -1*prices[0];
        int ans = INT_MIN;
        // DP looping
        for(int i = 1;i < n;i++){
            dp[i][0][0] = max(-1*prices[i], dp[i-1][0][0]);
            dp[i][0][1] = max(prices[i] + dp[i-1][0][0], dp[i-1][0][1]);
            dp[i][1][0] = max(dp[i-1][0][1] - prices[i], dp[i-1][1][0]);
            dp[i][1][1] = max(dp[i-1][1][0] + prices[i], dp[i-1][1][1]);
            ans = max({ans, dp[i][1][1], dp[i][0][1]});
        }
        return ans;
    }
};