class Solution {
public:
    bool AlphaNum(char ch) {
        if ((ch >= '0' && ch <= '9') ||
            (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
            return true;
        }
        return false;
    }

    bool check(string& s, int left, int right) {
        while (left < right) {
            if (!AlphaNum(s[left])) {
                left++;
                continue;
            }

            if (!AlphaNum(s[right])) {
                right--;
                continue;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool isPalindrome(string s) {
        return check(s, 0, s.length() - 1);
    }
};