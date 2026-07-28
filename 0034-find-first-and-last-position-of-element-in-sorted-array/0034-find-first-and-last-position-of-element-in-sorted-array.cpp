class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int first = -1;
        int last = -1;

        // First occurrence
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(nums[mid] == target){
                first = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        // Reset pointers 
        start = 0;
        end = n - 1;

        // Last occurrence
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(nums[mid] == target){
                last = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        return {first, last};
    }
};