class Solution {
public:
    int numDecodings(string s) {

        vector<int> dp(s.size()+1, 0);
        
        //base case 1 with string length 1
        dp[0] = 1;

        if(s[0] == '0') 
            dp[1] = 0;
        else 
            dp[1] = 1;


        for(int i=1; i<s.size(); ++i) {
                
            if(s[i]!='0') {
                dp[i+1] = dp[i];
            }

            int num = stoi(s.substr(i-1,2));
            cout<<"num is "<<num<<endl;

            if(num >= 10 and num <= 26) {
                if(num == 10 or num == 20) {
                    dp[i+1] = dp[i-1];
                }
                else dp[i+1] += dp[i-1];
            }
 
        }

        return dp[s.size()];
    }
};