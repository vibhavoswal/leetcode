class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int i=0;
        // while(i<nums.size()) {
        //     if(nums[i]==0) {
        //         break;
        //     }
        // }
        int j=0;
        // while(j<nums.size()) {
        //     if(nums[j]!=0) {
        //         break;
        //     }
        // }
        while(i<nums.size() and j<nums.size()) {

            swap(nums[i],nums[j]);
            
            while(i<nums.size() and nums[i]!=0) {
                i++;
            }

            j=i+1;
            while(j<nums.size() and nums[j]==0) {
                j++;
            }            
        }


    }
};