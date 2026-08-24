class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int canditate = 0;
        int count = 0;

        for(int num: nums){
            if(count == 0){
                canditate = num;
            }

            if(num == canditate){
                count++;
            }else{
                count--;
            }
        }
        return canditate;
    }
};