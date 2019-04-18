class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1,mid = 0;
        if(right == 0)
            return target == nums[0];
        while(left <= right){
            mid = left + (right - left)/2;
            if(target == nums[mid])
                return true;
            if(nums[left] < nums[mid]){
                //left [1] mid [2] Min [3] right
                if(nums[left] <=target && target < nums[mid])
                    right = mid - 1;        //[1]
                else
                    left = mid + 1;     //[2] + [3]
            }
            else if( nums[left] > nums[mid]){
                //left [1] Max [2] mid [3] right
                if(nums[mid] < target && nums[right] >= target)
                    left = mid + 1;     //[3]
                else
                    right = mid - 1;    //[1] + [2]
            }
            else
                //[left] == [mid]
                //Can't distinguish the mid positon in [left,Max] OR [Min, right]
                left = left + 1;
        }
        return false;
    }
};