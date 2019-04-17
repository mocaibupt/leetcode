class Solution {
public:
	int minDistance(string word1, string word2){
		int n = word1.size();
        int m = word2.size();
        if( n == 0)
            return m;
        if( m == 0)
            return n;
        //dp[i][j]: minDistance(word1.substr(0,i),word2.substr(0,j))
        vector<vector<int>> dp(n+1,vector<int>(m+1, 0));
        for(int i= 1; i <= m; i++)
            dp[0][i] = i;
		for(int i= 1; i <= n; i++)
            dp[i][0] = i;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j], dp[i][j-1])) + 1;
                pre = tmp;
            }
        }
        return dp[m];
	}
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if( n == 0)
            return m;
        if( m == 0)
            return n;
        
        vector<int> dp(m+1, 0);
        int pre = 0, tmp;
        for(int i= 1; i <= m; i++)
            dp[i] = i;
        for(int i = 1; i <= n; i++){
            pre = dp[0];
            dp[0] = i;
            for(int j = 1; j <= m; j++){
                tmp = dp[j];
                if(word1[i-1] == word2[j-1])
                    dp[j] = pre;
                else
                    dp[j] = min(pre, min(dp[j], dp[j-1])) + 1;
                pre = tmp;
            }
        }
        return dp[m];
    }
};