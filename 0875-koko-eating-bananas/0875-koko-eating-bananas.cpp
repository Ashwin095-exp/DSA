class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = INT_MIN;
        int ans = 0;
        for (int i = 0; i < piles.size(); i++) {
            e = max(piles[i], e);
        }

        while (s <= e) {
            int m = s + (e - s) / 2;
            long long hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                hours += (piles[i] + m - 1) / m;
            }

            if (hours <= h) {
                ans = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }

        return ans;
    }
};