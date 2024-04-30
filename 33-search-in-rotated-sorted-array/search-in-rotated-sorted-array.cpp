class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size()-1;
        int mid;

        while(low<=high) {

            mid = (low+high)/2;

            if(nums[mid] == target) {
                return mid;
            }

            //Check if the left part is sorted
            if(nums[low] <= nums[mid]) {
                if( target >= nums[low] and target <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            //Check if the right part is sorted
            else {
                if( target >= nums[mid] and target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }


        return -1;
        
    }
};

/*

Sample Test Cases for n even and odd

[0 1 2 3 4 5 6 7]
[6 7 0 1 2 3 4 5]
[3 4 5 6 7 0 1 2]

[0 1 2 3 4 5 6]
[5 6 0 1 2 3 4]
[3 4 5 6 0 1 2]

*/