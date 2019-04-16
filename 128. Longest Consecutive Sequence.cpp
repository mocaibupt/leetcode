class Solution {
public:
	//Time complexity : O(n).
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> tick(nums.begin(), nums.end());
        int longestVal = 0;
        for (int num : tick) {
            if ( tick.find(num-1) == tick.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (tick.find(currentNum+1) != tick.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestVal = max(longestVal, currentStreak);
            }
        }
        return longestVal;
    }
};