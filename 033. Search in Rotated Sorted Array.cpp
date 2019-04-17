class Solution {
public:
	//第一版
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        if(left > right)
            return -1;
		if(left == right && nums[0] == target)
            return 0;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[left] == target)
                return left;
            else if(nums[right] == target)
                return right;
            else{
                if(nums[left] < nums[mid]){
                    //left.[1].mid.[2].Max.[3].right
                    if(target > nums[mid])
                        left = mid + 1;     //[2]
                    else if(target > nums[left])
                        right = mid - 1;    //[1]
                    else
                        left = mid + 1;     //[3]
                }
                else{
                    //left.[1].Max.[2].min.[3].right
                    if(target > nums[right])
                        right = mid - 1;    //[1]
                    else if(target > nums[mid])
                        left = mid + 1;     //[3]
                    else
                        right = mid -1;     //[2]
                }
            }
        }
        return -1;
    }
	
	//第二版
	int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        if(left > right)
            return -1;
		if(left == right && nums[0] == target)
            return 0;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[left] == target)
                return left;
            else if(nums[right] == target)
                return right;
            else{
                if(nums[left] < nums[mid]){
                    //left.[1].mid.[2].Max.[3].right
                    if(target > nums[mid] || target < nums[left])
                        left = mid + 1;     //[2]  [3]
                    else if(target > nums[left])
                        right = mid - 1;    //[1]
                }
                else{
                    //left.[1].Max.[2].min.[3].right
                    if(target > nums[right] || target < nums[mid])
                        right = mid - 1;    //[1]	[2]
                    else if(target > nums[mid])
                        left = mid + 1;     //[3]
                }
            }
        }
        return -1;
    }
	
	//others solution:
	int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        if(nums.size() == 1){
            if(nums[0] == target)
                return 0;
            else
                return -1;
        }
        if(nums.size() == 2){
            if(nums[0] == target){
                return 0;
            }else if(nums[1] == target){
                return 1;
            }else{
                return -1;
            }
        }
        
        int start=0, end=nums.size()-1;
        while(start < end){
            int mid = (start + end)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[start] == target){
                return start;
            }else if(nums[end] == target){
                return end;
            }else{
                if(target < nums[start] && target < nums[mid] && nums[start] <= nums[mid]){
                    start = mid+1;
                }else if(target > nums[start] && target > nums[mid] && nums[start] <= nums[mid]){
                    start = mid+1;
                }else if(target > nums[mid] && target < nums[end] && nums[mid] <= nums[end]){
                    start = mid+1;
                }else if(target > nums[start] && target < nums[mid] && nums[start] <= nums[mid]){
                    end = mid-1;
                }else if(target < nums[mid] && target < nums[end] && nums[mid] <= nums[end]){
                    end = mid-1;
                }else if(target > nums[mid] && target > nums[end] && nums[mid] <= nums[end]){
                    end = mid-1;
                }else{
                    return -1;
                }
            }
        }
        return -1;
    }
};