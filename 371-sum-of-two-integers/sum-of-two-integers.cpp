class Solution {
public:
    int getSum(int a, int b) {

        bitset<32> a_binary(a);
        bitset<32> b_binary(b);

        string num1 = a_binary.to_string();
        string num2 = b_binary.to_string();
        string ans = "";

        int carry = 0;
        
        for(int i=num1.size()-1; i>=0; i--) {
            int units_digit = (num1[i]-'0')^(num2[i]-'0')^carry;
            ans += to_string(units_digit);
            int flag = 0;
            if(num1[i] == '1') flag++;
            if(num2[i] == '1') flag++;
            if(carry == 1) flag++;

            if(flag > 1) carry = 1; else carry = 0;
        }
        
        reverse(ans.begin(),ans.end());
        bitset<32> ans_binary(ans);
        
        return ans_binary.to_ullong();
    }
};