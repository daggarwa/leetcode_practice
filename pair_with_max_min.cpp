class Solution {
public:
    
   
    
    int maximumMinimumPath(vector<vector<int>>& A) {
        
        auto compare = [&,A] (const std::pair<int,int>& a,const std::pair<int,int>& b){
        
        return A[a.first][a.second] < A[b.first][b.second];
        };
        
        array<array<int,2>,4> dir {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
        
        const int inp_rows = A.size(), inp_cols = A[0].size();
        vector<vector<bool>> visited(inp_rows,vector<bool>(inp_cols,false));
        
        vector<bool> visited2(inp_rows*inp_cols,false);
        
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,decltype(compare)> pq(compare);
        int score = numeric_limits<int>::max();
        
        pq.push(make_pair(0,0));
        
        while(pq.size()>0)
        {
            auto coords = pq.top();
            auto row = coords.first;
            auto col = coords.second;
            std::cout<<"row: "<<row<<"col: "<<col<<"val: "<< A[row][col]<<std::endl;
            pq.pop();
            visited2[row*inp_cols + col] = true;
            score = min(score,A[row][col]);
            
            if(row== inp_rows-1 && col == inp_cols-1)
            {
                return score;
            }
            
            for(auto& coord : dir)
            {
                int new_row = row+coord[0];
                int new_col = col+coord[1];
                
                if(new_row>=0 && new_row<inp_rows && new_col>=0 && new_col<inp_cols && !visited2[new_row*inp_cols + new_col])
                {
                    pq.push(make_pair(new_row,new_col));
                }
                
            }
            
        }
        
        return score;    
        
    }
};