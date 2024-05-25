class Solution {
public:
    int computeAll(int start, int sell, int state, vector<int>& prices, vector<vector<vector<int>>>& dp, int curr){
        if(start >= prices.size() || sell == 0)return curr;
        if(dp[start][sell][state] != INT_MIN){
            return curr + dp[start][sell][state];
        }
        int opn1 = INT_MIN, opn2 = INT_MIN;
        // First possibility is we need to do a buy
        if(state == 0){
            opn1 = -1*prices[start] + computeAll(start+1,sell,1,prices,dp,0);
            opn2 = computeAll(start+1,sell,0,prices,dp,0);
        }
        // Second possibility is we need to do a sell
        else if(state == 1){
            opn1 = prices[start] + computeAll(start+1,sell-1,0,prices,dp,0);
            opn2 = computeAll(start+1,sell,1,prices,dp,0);
        }
        dp[start][sell][state] = max({opn1, opn2});
        return dp[start][sell][state];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int sell = k;
        // Initialize DP Array
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1, vector<int>(2,INT_MIN)));
        int maxAns = 0;
        return computeAll(0,k,0,prices,dp,0);
    }
};