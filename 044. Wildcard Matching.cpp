class Solution {
public:
	bool isMatch(string s, string p) {
        unsigned int n = s.length(), m = p.length();
        unsigned int i = 0, j = 0;
        unsigned int s_tmp = 0, p_tmp = -1;
        while(i < n){
            if(j < m && s[i] == p[j] || p[j] == '?'){
                i++;
                j++;
            }
            else if( j < m && p[j] == '*'){
                //'*' match empty sequence
                s_tmp = i;
                p_tmp = j++;
            }
            else if(p_tmp != -1){
                //the number of sequence of '*' match ++
                i = ++s_tmp;
                j = p_tmp + 1;
            }
            else
                return false;
        }
        
        while(j < m && p[j] == '*')
            j++;
        
        return i==n&&j==m;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
		int i_mark = -1, j_mark = -1;
		int i  = 0, j = 0;
		while( i < n){
			if( j < m){
				if(s[i] == p[j] || p[j] == '?'){
					i++;
					j++;
				}
				else if(p[j] == '*'){
					//i_mark指向上一个s[i-1]字符
					//j_mark指向'*'后一个字符
					i_mark = i-1;
					j_mark = j++;
				}
				else{
					//不匹配时，如果j_mark为-1，即未遇到*，return false；
					if(j_mark != -1){
						i = ++i_mark;
						j = j_mark + 1;
					}
					else
						return false;
				}
			}
			else{
				if(j_mark != -1){
						i = ++i_mark;
						j = j_mark + 1;
					}
				else
					return false;
			}
		}
		while( j < p.size() ) {
            if( p[j] != '*' ) {
                return false;
            }
            j++;
        }
        return true;
    }
};