class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        int first, second;
        if(rowIndex < 2)
            return res;
        for(int i = 2; i <= rowIndex; i++ ){
            first = 1;
            for(int j = 1; j < i; j++){
                second = res[j];
                res[j] = first + res[j];
                first = second;
            }                
        }
        return res;
    }
};