/*

i =0 
l = 0
r = 0

0 1
b a b a d

*/

class Solution {
public:
    string longestPalindrome(string s) {
        
        int start=0,end=0;
        int len1,len2,len;
        if(s.empty() || s.size()<1)
        {
            return "";
        }
        
        for(int i=0;i<s.size();i++)
        {
            len1 = expand(s,i,i);
            len2 = expand(s,i,i+1);
            len = std::max(len1,len2);
            if(len > end-start)
            {
                start = i - (len-1)/2;
                end = i + len/2;
            }         
            
        }
        
        return s.substr(start,end-start+1);
        
    }
    
    int expand(string s, int left,int right)
    {
        if(left>right) return 0;
        while(left>=0 && right < s.size() && s[left]==s[right])
        {
            left--; // -1
            right++; // 1
        }
        
        return right-left-1;
        
    }
};