/*

Hashmap : 
priority queue with custom comparator

*/

class Solution {
public:
    
    struct comp{
        
        bool operator() (const pair<int,string>& a, const pair<int,string>& b) {
            if(a.first == b.first)
            {
               return a.second > b.second;
            }
            return a.first < b.first;
        }
        
    };
    
   
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string,int> frequencyMap;
        vector<string> result;
                        
        for(auto &s: words)
        {
            if(frequencyMap.count(s)>0)
            {
                frequencyMap[s] = frequencyMap[s] + 1 ;
            }
            else
            {
                frequencyMap[s]=1;
            }
         }
        
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> pq;
        
        for(auto &p: frequencyMap)
        {
            pq.push({p.second,p.first});
            
        }
        
        for(int i =0;i<k;i++)
        {
            auto s = pq.top();
            pq.pop();
            result.push_back(s.second);
        }
        
        return result;
 }
};