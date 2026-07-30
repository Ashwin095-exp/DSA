class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] > nums[e]) {
                // Minimum is in the right half
                s = mid + 1;
            } else {
                // Minimum is at mid or in the left half
                e = mid;
            }
        }

        return nums[s];
    }
};