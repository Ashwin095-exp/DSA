class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxdepth = INT_MIN;
        for (char ch : s) {
            if (ch == '(') {
                depth++;
            } else if (ch == ')') {
                depth--;
            }
            maxdepth = max(maxdepth, depth);
        }

        return maxdepth;
    }
};