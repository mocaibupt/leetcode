class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(; i < n ; i++){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i] )
                swap(nums[nums[i] - 1] , nums[i]);
        }
        
        for(i = 0; i < nums.size() ; i++){
            if(nums[i] != i + 1)
                break;
        }
        return i+1;
    }
};