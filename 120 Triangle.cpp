class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0)
            return 0;
        vector<int> dp(triangle.back().size(), 0);
        dp[0] = triangle[0][0];
        int res = INT_MAX;
        int first, second;
        for(int i = 1; i < triangle.size(); i++){
            first = dp[0];
            dp[0] = dp[0] + triangle[i][0];
            //the i(th) row has i+1 element(index from 0 to i)
            //dp[1] ~ dp[i-1]
            for(int j = 1; j < triangle[i].size()-1 ; j++ ){
                second = dp[j];
                dp[j] = min(first, second) + triangle[i][j];
                first = second;
            }
            
            dp[i] = first + triangle[i][i];
        }
        for(auto it : dp)
            res = min(res, it);
        return res;
    }
};