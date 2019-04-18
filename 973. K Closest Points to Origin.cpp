class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int,int>> result;
        for(int i = 0; i < K; i++){
            result.push_back({points[i][0]*points[i][0] + points[i][1]*points[i][1],i});
        }
        make_heap(result.begin(), result.end() ,[](const pair<int,int> &l, const pair<int,int> &r)
                                                        { return l.first < r.first;});
        for(int i = K; i < points.size(); i++){
            int tmp = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if(tmp < result[0].first){
                pop_heap(result.begin(),result.end());
                result.back() = make_pair(tmp,i);
                push_heap(result.begin(),result.end());
            }
        }
        vector<vector<int>> tmp;
        for(int i = 0; i < K; i++){
            tmp.push_back(points[result[i].second]);
        }
        return tmp;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partition(points, 0, points.size() - 1, K);
        vector<vector<int> > ret(points.begin(), points.begin() + K);
        return ret;
    }
    
    void partition(vector<vector<int>>& points, int start, int end, int K){
        if(start >= end){
            return;
        }
        
        int i = start, j = end;
        vector<int> & pivotP = points[i];
        int disSquare = distSquare(pivotP);
        while(i <= j){
            while(i <= j && distSquare(points[i]) < disSquare){
                ++i;
            }
            while(i <= j && distSquare(points[j]) > disSquare){
                --j;
            }
            if(i <= j){
                //swap
                swap(points[i], points[j]);
                ++i;
                --j;
            }
        }
        if(K <= j){
            return partition(points, start, j, K);
        }
        if(K >= i){
            return partition(points, i, end, K);
        }
    }
    
    int distSquare(vector<int> &point){
        return point[0] * point[0] + point[1] * point[1];
    }
};