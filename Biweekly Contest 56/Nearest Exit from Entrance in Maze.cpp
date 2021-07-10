class Solution {
public:
    vector<vector<long int>> dp;
    
    bool isExit(int i,int j,int m,int n,vector<int>& entrance)
    {
        //Exit lies at the edges of the maze and entrance can't be the exit
        if(i!=entrance[0]||j!=entrance[1])
        {
            if(i==0||j==0||i==m-1||j==n-1)
            return true;
        }
        
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int m = maze.size();
        int n = maze[0].size();
        
        dp.resize(m,vector<long int>(n,-1));
        int i = entrance[0];
        int j = entrance[1];
        
       
       
        long int res = dfs(i,j,m,n,maze,entrance);
                
        
        //If we are able to reach the exit then print the minumum no. of steps else -1
        return res>=INT_MAX ? -1 : res;
        
       
        
    }
    
    long int dfs(int i,int j,int m,int n,vector<vector<char>>& maze,vector<int>& entrance)
    {
        if(i<0||j<0||i>m-1||j>n-1||maze[i][j]=='+')
            return INT_MAX;//since we can't reach such cells
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(isExit(i,j,m,n,entrance))
        {
            
            return dp[i][j] = 0;
        }
        
        maze[i][j] = '+'; //mark this as visited
        
        long int temp = 1+min({dfs(i+1,j,m,n,maze,entrance), dfs(i-1,j,m,n,maze,entrance),dfs(i,j+1,m,n,maze,entrance),dfs(i,j-1,m,n,maze,entrance)});
        
        maze[i][j] = '.';//dfs call ended for cell(i,j)
        
        return dp[i][j] = temp;
    }
};
