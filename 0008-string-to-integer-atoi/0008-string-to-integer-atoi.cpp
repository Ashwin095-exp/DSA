class Solution {
public:
    int myAtoi(string s) {

        int i = 0;

        // 1. Skip leading spaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        int sign = 1;

        if (i < s.length() && s[i] == '-') {
            sign = -1;
            i++;
        } else if (i < s.length() && s[i] == '+') {
            i++;
        }

        // 3. Read digits
        long long ans = 0;

        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {

            int digit = s[i] - '0';

            ans = ans * 10 + digit;

            // 4. Check overflow
            if (sign * ans > INT_MAX) {
                return INT_MAX;
            }

            if (sign * ans < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        // 5. Return result
        return sign * ans;
    }
};