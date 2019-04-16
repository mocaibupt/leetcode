class Solution {
public:
	int numDistinct(string s, string t) {
			vector<long> dp(t.size()+1, 0);
			dp[0] = 1;
			for(int i = 1 ; i <= s.size(); i++)
				for(int j = t.size(); j >= 1 ; j--)
					if(s[i-1] == t[j-1])
						dp[j]+=dp[j-1];
			return dp[t.size()];
		}
		
		
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if(n < m)
            return 0;
        //dp[i][j]: the number of distinct subsequences of S[0~j-1] whilch equals T[0~i-1]
        //i < j : dp[i][j] = 0
        //如果s[j-1] == t[i-1],dp[i][j] = dp[i-1][j-1] + dp[i][j-1]：
        //dp[i-1][j-1]：s[0~j-2]到t[0~i-2]的Distinct，即s[0~j-2] + s[j-1]到t[0~i-2] + t[i-1]的Distinct
        //dp[i][j-1] : 不包含s[j-1]时，s[0~j-2]到t[0~i-1]的Distinct
        vector<vector<long>> dp(m+1, vector<long>(n+1, 0));
        for(int i = 0; i <= n; i++)
            dp[0][i] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(t[i-1] == s[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1]; 
                else
                    dp[i][j] = dp[i][j-1];
				if(dp[i][j] > INT_MAX)
					dp[i][j] = INT_MAX;
            }
            
        }
        return dp[m][n];
    }
	
	int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if(n < m)
            return 0;
        vector<long> dp(n+1, 1);
        long first, second, j;
        for(int i = 1; i <= m; i++){
            j = 0;
            while( j < i){
                first = dp[j];
                cout << first << "  ";
                dp[j++] = 0;  
            }
            while(j <= n){
                second = dp[j];
                dp[j] = dp[j-1] + (s[j-1] == t[i-1] ? first : 0);
                first = second;
				if(dp[i][j] > INT_MAX)
					dp[i][j] = INT_MAX;
                cout << dp[j] << "  ";
                j++;                
            }
            cout <<endl;
        }
        return dp[n];
    }
    }
};