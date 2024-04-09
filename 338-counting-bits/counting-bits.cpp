class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> dp(n+1,0);
        dp[0] = 0;
        int nearest_power_of_2 = 0;

        for(int i=1; i<n+1; ++i) {
            if( (i&(i-1)) == 0) {
                nearest_power_of_2 = i;
                dp[i] = 1;
            }
            else {
                dp[i] = dp[i - nearest_power_of_2] + 1;
            }
        }

        return dp;
        
    }
};