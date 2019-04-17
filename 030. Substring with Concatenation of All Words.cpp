class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int m = s.size(), n = words.size();
        if( m == 0 || n == 0)
            return res;
        unordered_map<string,int> dict;
        for(int i  = 0; i < n; i++)
            dict[words[i]]++;
        
        int width = words[0].size();
        unordered_map<string, int> tdict;
        for(int i = 0; i < width; i++){
            tdict.clear();
            int count = 0, left = i;
            for( int j = i; j <= m - width; j+= width){
                string strTmp = s.substr(j, width);
                if(dict.find(strTmp) != dict.end()){
                    tdict[strTmp]++;
                    if(tdict[strTmp] <= dict[strTmp])
                        count++;
                    else{
                        while(tdict[strTmp] > dict[strTmp]){
                            string strTmp1 = s.substr(left, width);
                            tdict[strTmp1]--;
                            if(tdict[strTmp1] < dict[strTmp1])
                                count--;
                            left += width;
                        }
                    }
                    if(count == n){
                        res.push_back(left);
                        tdict[s.substr(left, width)]--;
                        count--;
                        left += width;
                    }
                }
                else{
                    count = 0;
                    left = j + width;
                    tdict.clear();
                }
            }
        }
        return res;
    }
};