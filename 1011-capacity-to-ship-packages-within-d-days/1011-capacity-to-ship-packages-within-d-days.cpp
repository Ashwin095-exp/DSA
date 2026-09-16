class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
         int sum = 0;
        int maxWeight = 0;

        // Find total weight and heaviest package
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            maxWeight = max(maxWeight, weights[i]);
        }

        int s = maxWeight;
        int e = sum;
        int ans = 0;

        while (s <= e) {

            int m = s + (e - s) / 2;

            int currentWeight = 0;
            int daysNeeded = 1;

            // Calculate how many days are needed
            // if ship capacity = m
            for (int i = 0; i < weights.size(); i++) {

                if (currentWeight + weights[i] <= m) {
                    // Same day
                    currentWeight += weights[i];
                }
                else {
                    // New day
                    daysNeeded++;
                    currentWeight = weights[i];
                }
            }

            // Check whether this capacity works
            if (daysNeeded <= days) {
                ans = m;
                e = m - 1;       // Try smaller capacity
            }
            else {
                s = m + 1;       // Need bigger capacity
            }
        }

        return ans;
    }
};