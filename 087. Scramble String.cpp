class Solution {
public:
    //isS[len][i][j] means isScramble(s1.substr(i,len), s2.substr(j,len))
	//use Dynamic progrom
    bool isScramble(string s1, string s2) {
        int sSize = s1.size(), len, i, j, k;
        if(0==sSize) return true;
        if(1==sSize) return s1==s2;
        bool isS[sSize+1][sSize][sSize];

        for(i=0; i<sSize; ++i)
            for(j=0; j<sSize; ++j)
                isS[1][i][j] = s1[i] == s2[j];
                
        for(len=2; len <=sSize; ++len)
            for(i=0; i<=sSize-len; ++i)
                for(j=0; j<=sSize-len; ++j)
                {
                    isS[len][i][j] = false;
                        for(k=1; k<len && !isS[len][i][j]; ++k)
                        {
                            isS[len][i][j] = isS[len][i][j] || 
                                                (isS[k][i][j] && isS[len-k][i+k][j+k]);
                            isS[len][i][j] = isS[len][i][j] || 
                                                (isS[k][i][j+len-k] && isS[len-k][i+k][j]);
                        }
                }
        return isS[sSize][0][0];            
    }
	
	//use backtrack
	bool isScramble(string s1, string s2){
		if(s1.size() != s2.size())
			return false;
		if(s1 == s2)
			return true;
		vector<int> cnt(26,0);
		for(int i = 0; i < s1.size(); i++){
			cnt[s1[i]]++;
			cnt[s2[i]]++;
		}
		
		for(auto num : cnt)
			if(num != 0)
				return false;
			
		for(int i = 1; i < n; i++){
			if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0,i),s2.substr(n-i)) && isScramble(s1.substr(i),s2.substr(0,n-i)))
                return true;
        }
        return false;
	}
}; 