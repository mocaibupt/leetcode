class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int count = 0, num = pow(2,n);
        while(count < num){
            res.push_back((count >> 1) ^ count);
            count++;
        }
        
        return res;
    }
	
	//对于i，已存在的2^i个数的第i位均为0。将已存在的翻转并置i位为1，得新的
	vector<int> grayCode(int n) {
        vector<int> res;
        res.push(0);
		for(int i = 0; i < n; i++){
			for(int j = res.size() - 1; j >= 0; i--){
				res.push_back(res[j] | (1 << i));
			}
		}        
        return res;
    }
};