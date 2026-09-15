class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = INT_MIN;
        int ans = 0;
        for(int i = 0;i< nums.size();i++){
            e = max(e,nums[i]);
        }

        while(s <= e){
            int m = s + (e-s)/2;
            int sum = 0;
            for(int i = 0;i<nums.size();i++){
                sum+=(nums[i]+m-1)/m;
            }

            if(sum <= threshold){
                ans = m;
                e = m-1;
            }else{
                s = m+1;
            }
        }

        return ans;
    }
};