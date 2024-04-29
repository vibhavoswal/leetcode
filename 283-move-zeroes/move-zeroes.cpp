class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // int i=0,j=nums.size()-1;
        // if(nums.size() == 1)
        //     return;

        int first_zero = nums.size();
        for(int i=0;i<nums.size();++i) {
            if(nums[i] == 0) {
                first_zero = i;
                break;
            }
        }
        if(first_zero == nums.size()) {
            return;
        }
        
        cout<<"First zero is "<<first_zero<<endl;

        for(int i=0;i<nums.size();++i) {
            if(i!=first_zero and i>first_zero) {
                swap(nums[i],nums[first_zero]);
            }

            while (first_zero<nums.size() and nums[first_zero]!=0) {
                first_zero++;
            }
            if(first_zero >= nums.size()) {
                break;
            }

            cout<<"First zero is "<<first_zero<<endl;
        }
    }
};