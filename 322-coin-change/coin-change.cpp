class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);

        dp[0] = 0;
        
        for(auto coin: coins) {
            if(coin <= amount) {
                dp[coin] = 1;
            }
        }

        for(int i=1; i<=amount; ++i) {
            for(auto coin: coins) {
                if(i-coin > 0) {
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }

        if(dp[amount] != 1e9) return dp[amount];
        else return -1;
    }
};