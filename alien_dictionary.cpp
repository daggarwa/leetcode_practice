class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        //array<int,26> charOrder;
        int charOrder[26];
        
        // making ordering array for the order sequence
        for(int i=0;i<26;i++)
        {
            charOrder[order[i]-'a'] = i;            
            
        }
        
        for(int i=0;i<words.size()-1;i++)
        {
            string currentWord = words[i];
            string nextWord = words[i+1];
            
            int len = min(currentWord.size(),nextWord.size());
            
            for(int j=0;j<len;j++)
            {
                if(charOrder[currentWord[j]-'a'] < charOrder[nextWord[j]-'a'])
                {
                    std::cout<< " curr: "<<currentWord[j] <<" next: "<<nextWord[j]<<std::endl;
                    break;
                }
                    
                else if (charOrder[currentWord[j]-'a'] > charOrder[nextWord[j]-'a'])
                {
                    std::cout<< " curr greater: "<<currentWord[j] <<" next: "<<nextWord[j]<<std::endl;
                    return false;

                }
                    
                else if(j == len-1 && nextWord.size() < currentWord.size())
                {
                    std::cout<< " curr greter in len: "<<currentWord[j] <<" next: "<<nextWord[j]<<std::endl;
                    return false;
                }
                
            }            
                    
                    
        }
        
        return true;
    }
};