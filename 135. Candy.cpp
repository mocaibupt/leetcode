class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 0 || n == 1)
            return n;
        vector<long> result(n,1);
        
        for(int i = 1; i < n; i++)
            if(ratings[i] > ratings[i-1])
                result[i] = result[i-1] + 1;
        int sum = result[n-1];
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                result[i] = max(result[i+1]+1, result[i]);
            }
            sum += result[i];
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> c;
    vector<int> R;
    void MinCandy(int l, int r)
    {
       // printf("l=%d, r=%d\n", l, r);
        if (l >= r) return;
        if (l+1 == r) 
        {
            if (R[l] < R[r]) c[r] = c[l]+1;
            else if (R[r] < R[l]) c[l] = c[r]+1;
           // printf("R[%d]=%d, R[%d]=%d\n", l, c[l], r, c[r]);
            return;
        }
        int m = (l+r)>>1;
        MinCandy(l, m);
        MinCandy(m+1, r);
        if (R[m] < R[m+1])
        {       
            int i = m+1;
            while (i <= r && R[i-1] < R[i])
            {
                c[i] = max(c[i], c[i-1]+1);
                ++i;
            }
        }
        else
        {
            int i = m;
            while (i >= l && R[i+1] < R[i])
            {
                c[i] = max(c[i], c[i+1]+1);
                --i;
            }
        }
        
        // for (int i = l; i <= r; ++i)
        // {
        //     printf("R[%d]=%d, ", i, c[i]);
        // }
        // printf("\n");
    }
    int candy(vector<int>& ratings) 
    {
        std::ios::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
        if (ratings.empty()) return 0;
        int n = ratings.size();
        c.resize(n, 1);
        R.swap(ratings);
        MinCandy(0, n-1);
        // for (auto v : c) printf("%d ", v);
        // printf("\n");
        int minCandy = accumulate(c.begin(), c.end(), 0);        
        return minCandy;
    }
};