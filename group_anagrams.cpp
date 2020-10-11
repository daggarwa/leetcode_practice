class Solution {
public:
    
    void sortString(string &str) 
    { 
      sort(str.begin(), str.end()); 
    } 
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result;
        unordered_map<string,vector<string>> map;
        string s;
        
        for(auto&str : strs)
        {
            s = str;
            sortString(s);
            map[s].push_back(str);
            
        }
        
        for(auto [k,v] : map)
        {
            result.push_back(v);
        }
        
        return result;
        
        
                
        
        
        
    }
};