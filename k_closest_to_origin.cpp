class Solution {
public:
    
    struct comp{
        
        bool operator() (pair<float,vector<int>>& a, pair<float,vector<int>>& b) {
            
            
            return a.first > b.first;
        }
        
    };
    
     double dist(vector<int> &point){
        int x1 = point[0];
        int y1 = point[1];
        return sqrt(x1*x1 + y1*y1);
    }
    
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        priority_queue <pair<float,vector<int>>,vector<pair<float,vector<int>>>
            ,comp> pq;
        
        vector<vector<int>> result;
        
        for(auto& p : points)
        {
            pq.push({dist(p),p});
        }
        
        for(int i =0;i<K;i++)
        {
            auto p = pq.top();
            pq.pop();
            result.push_back(p.second);
        }
        
        return result;
        
    }
};