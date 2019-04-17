class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
		if(left == right)
            return nums[0];
        if(nums[left] < nums[right])
            return nums[left];
        if( nums[right] < nums[right-1])
            return nums[right];
        //left...Min...right
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[right] < nums[mid]){
                //left.[1].mid.[2].Min.[3].right
                left = mid + 1;
            }
            else{
                //left.[1].Min.[2].mid.[3].right
                right = mid;
            }
        }
        return nums[left];
    }
	
	int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            if(nums[left] <= nums[right])
                return nums[left];
            
            int mid = (left + right) / 2;
            
            // If the left range is sorted
            if(nums[left] <= nums[mid])
                left = mid + 1;
            // If the right range is sorted
            else
            {
                if(nums[mid] < nums[mid - 1])
                    return nums[mid];
                right = mid - 1;
            }
        }
        
        return INT_MAX;
    }
};