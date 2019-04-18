class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 =  0,x2 = 0, mark;
        for(int i = 0;i < nums.size(); i++){
            x2 ^= (x1 & nums[i]);
            x1 ^= nums[i];
            mark = ~(x1 & x2);
            x2 &= mark;
            x1 &= mark;
        }
        return x1;
    }
	

	int singleNumber(std::vector<int> &nums) {
		int ones(0), twos(0);
		for (int &i : nums) {
		  ones ^= i & ~twos;
		  twos ^= i & ~ones;
		}
		return ones;
	  }
};