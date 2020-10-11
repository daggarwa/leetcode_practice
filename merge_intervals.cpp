class Solution {
public:
    
    static bool compare(const vector<int>& a,const vector<int>& b)
    {
        return a[0]<b[0];
        
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> result;
        
        if(intervals.size()<=1)
        {
            return intervals;
        }
        
        sort(intervals.begin(),intervals.end(),compare);
        result.push_back({intervals[0][0],intervals[0][1]});
        
        
        for(int i=1;i<intervals.size();i++)
        { 
            vector<int>& last_merged_meeting = result.back();
            
            if(intervals[i][0]<=last_merged_meeting[1])
            {
                last_merged_meeting[1] = std::max(last_merged_meeting[1],intervals[i][1]);
            }
            else
            {
                result.push_back({intervals[i][0],intervals[i][1]});
            }
            
        }
                         
        return result;       
        
    }
};