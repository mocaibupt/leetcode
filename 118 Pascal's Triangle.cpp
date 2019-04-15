class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0)
            return res;
        for(int i = 1; i <= numRows; i++){
            vector<int> ref(i,1);
            for(int j = 1; j < (i-1); j++){
                ref[j] = res[i-2][j-1] + res[i-2][j];
            }            
            res.push_back(ref);
        }
        return res;
    }
};