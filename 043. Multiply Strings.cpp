class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ires(num1.size() + num2.size() , 0);
        for( int i = num1.size() -1 ; i >= 0; i--){
            for(int j = num2.size() -1 ; j >= 0; j--){
                int tmp = (num1[i] - '0') * (num2[j] - '0');
                int sum = tmp + ires[i+j+1];
                ires[i+j] += sum/10;
                ires[i+j+1] = sum%10;
            }
        }
        
        string res;
        for(int i = 0; i <ires.size(); i++){
            if(res.empty() && ires[i] == 0)
                continue;
            res.push_back('0'+ires[i]);
        }
        return res.length() == 0 ? "0" : res;
    }
};