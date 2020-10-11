class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int countfresh =0;
        int minutes = 0;
        vector<vector<int>> dir {{0,1},{0,-1},{-1,0},{1,0}};
        std::queue<vector<int>> processq;
        
        for(int i =0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                // add all rotten to queue
                if(grid[i][j]==2)
                {

                    processq.emplace(vector<int> {i,j});
                }
                else if(grid[i][j]==1)
                {
                    countfresh++;
                }
            }
        }
        
        if(processq.empty() && countfresh==0)
        {
            return minutes;
        }
        
        // process rotten oranges queue
        while(!processq.empty())
        {
            int size = processq.size();
            
            for(int i=0;i<size;i++)
            {
                vector<int> coords = processq.front();
                processq.pop();
                int neigh_row = coords[0];
                int neigh_col = coords[1];
                
                for(auto d : dir)
                {
                    int next_row = d[0]+neigh_row;
                    int next_col = d[1]+neigh_col;
                    
                    if(next_row<0 || next_row>=grid.size() || next_col<0 || next_col>=grid[0].size() ||grid[next_row][next_col]!=1 )
                    {
                        continue;
                    }
                    grid[next_row][next_col]=2;
                    countfresh--;
                    processq.emplace(vector<int> {next_row,next_col};
                 }
                    
                }  
                minutes++;    
            }
             
        if(countfresh==0)
            // final iteration of while loop contains rotten oranges which will not be able to make more oranges rotten
            return minutes-1;
        return -1;
        
        
    }
};