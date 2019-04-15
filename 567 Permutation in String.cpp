class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> ref(26,0);
        int n = s1.size(), m = s2.size(), sum = 0;
        if(n > m)
            return false;
        for(int i = 0; i < n; i++)
            ref[s1[i] - 'a']++;
        for(int i = 0; i < n; i++){
            sum = sum +(ref[s2[i]-'a'] > 0 ? 1 : 0);
            ref[s2[i]-'a']--;  
            if(sum == n)
                return true;
        }
        for(int i = n; i < m; i++){
            ref[s2[i-n] - 'a']++;
            if(ref[s2[i-n] - 'a'] > 0)
                sum--;
            if(ref[s2[i]-'a'] > 0)
                sum++;
            ref[s2[i]-'a']--;  
            if(sum == n)
                return true;
        }
        return false;
    }
};