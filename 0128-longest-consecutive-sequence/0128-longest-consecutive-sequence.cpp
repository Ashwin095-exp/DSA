class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
        }
        int maxcount = 0;
        for (int x : st) {
            if (st.count(x - 1) == 0) {
                int current = x;
                int count = 1;
                while (st.count(current + 1)) {
                    current++;
                    count++;
                    
                }
                maxcount = max(maxcount, count);
            }
        }

        return maxcount;
    }
};