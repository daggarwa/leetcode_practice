class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict (wordList.begin(),wordList.end());
        if(dict.count(endWord)==0)
            return 0;
        
        int level =1;
        queue<string> bfs_queue;
        bfs_queue.push(beginWord);
        
        while(!bfs_queue.empty())
        {   
            int size = bfs_queue.size();
            
            for(int i=0;i<size;i++)
            {
                string word = bfs_queue.front();
                bfs_queue.pop();
                // if next neighbour is the endword return from current level only
                // no need to process further since goal is reached
                if(word.compare(endWord)==0)
                {
                    return level;
                }
                
                for(int j =0 ;j<word.size() ;j++)
                {
                    char c= word[j];
                    // make permutations of word
                    for(int k =0;k<26; k++)
                    {
                        word[j] = 'a' + k;
                        // if word permutation exists in dictionary add permutation as next neighbor to q and
                        // delete word from dict since we already found it 
                        if(dict.count(word) >0 )
                        {
                            bfs_queue.push(word);
                            dict.erase(word);
                        }
                    }
                    
                    // original word back
                    word[j] = c;   
                }
                
              }
            
            ++level;
        }
        
        return 0;    
    }
};