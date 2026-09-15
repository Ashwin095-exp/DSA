class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int s = 1;
        int e = x;
        int ans = 1;

        while (s <= e) {
            int m = s + (e - s) / 2;

            if ((long long)m*m <= x) {   // avoids m*m overflow
                ans = m;
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }

        return ans;
    }
};