class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = 1;
        int e = INT_MIN;
        int ans = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            e = max(e, bloomDay[i]);
        }
        if (bloomDay.size() < (long long)m * k) {
            return -1;
        }

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int count = 0;
            int bouquets = 0;
            for (int i = 0; i < bloomDay.size(); i++) {
                if (bloomDay[i] <= mid) {
                    count++;

                    if (count == k) {
                        bouquets++;
                        count = 0;
                    }

                } else {
                    count = 0;
                }
            }

            if (bouquets >= m) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};