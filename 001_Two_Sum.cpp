class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int> ref;
        int tmp;
        ref[target- nums[0]] = 0;
        for(int i = 1; i < nums.size(); i++){
            auto search = ref.find(nums[i]);
            if( search != ref.end()){
                res.push_back(search->second);
                res.push_back(i);
                return res;
            }
            else
                ref[target - nums[i]] = i;
        }
        return res;
    }
};