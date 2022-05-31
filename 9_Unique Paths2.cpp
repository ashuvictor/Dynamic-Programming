
https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241

Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach the right-bottom cell from the top-left cell. A cell in the given maze has a value '-1' if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. Since the answer can be large, print it modulo 10^9 + 7.
For Example :
Consider the maze below :
0 0 0 
0 -1 0 
0 0 0

There are two ways to reach the bottom left corner - 

(1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
(1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)

Hence the answer for the above test case is 2.


#include <bits/stdc++.h>

using namespace std;

int mazeObstaclesUtil(int i, int j, vector<vector<int> > &maze, vector<vector<int> > 
&dp) {
  if(i>0 && j>0 && maze[i][j]==-1) return 0; 
  if(i==0 && j == 0)
    return 1;
  if(i<0 || j<0)
    return 0;
  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = mazeObstaclesUtil(i-1,j,maze,dp);
  int left = mazeObstaclesUtil(i,j-1,maze,dp);
  
  return dp[i][j] = up+left;
  
}

int mazeObstacles(int n, int m, vector<vector<int> > &maze){
    vector<vector<int> > dp(n,vector<int>(m,-1));
    return mazeObstaclesUtil(n-1,m-1,maze,dp);
    
}

int main() {

  vector<vector<int> > maze{{0,0,0},
                            {0,-1,0},
                            {0,0,0}};
                            
  int n = maze.size();
  int m = maze[0].size();
  
  cout<<mazeObstacles(n,m,maze);
}





#include <bits/stdc++.h>

using namespace std;

int mazeObstaclesUtil(int n, int m, vector<vector<int>> &maze,vector<vector<int>>
 &dp) 
{
  for(int i=0; i<n ;i++){
      for(int j=0; j<m; j++){
          
          //base conditions
          if(i>0 && j>0 && maze[i][j]==-1){
            dp[i][j]=0;
            continue;
          }
          if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
          
          int up=0;
          int left = 0;
          
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
            
          dp[i][j] = up+left;
      }
  }
  
  return dp[n-1][m-1];

  
}

int mazeObstacles(int n, int m, vector<vector<int> > &maze){
    vector<vector<int> > dp(n,vector<int>(m,-1));
    return mazeObstaclesUtil(n,m,maze,dp);
    
}

int main() {

  vector<vector<int> > maze{{0,0,0},
                            {0,-1,0},
                            {0,0,0}};
                            
  int n = maze.size();
  int m = maze[0].size();
  
  cout<<mazeObstacles(n,m,maze);
}





#include <bits/stdc++.h>

using namespace std;

int mazeObstacles(int n, int m, vector<vector<int> > &maze){

    vector<int> prev(m,0);
    for(int i=0; i<n; i++){
        vector<int> temp(m,0);
        for(int j=0; j<m; j++){
            if(i>0 && j>0 && maze[i][j]==-1){
                temp[j]=0;
                continue;
            }
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }
            
            int up=0;
            int left =0;
            
            if(i>0)
                up = prev[j];
            if(j>0)
                left = temp[j-1];
                
            temp[j] = up + left;
        }
        prev = temp;
    }
    
    return prev[n-1];

    
}

int main() {

  vector<vector<int> > maze{{0,0,0},
                            {0,-1,0},
                            {0,0,0}};
                            
  int n = maze.size();
  int m = maze[0].size();
  
  cout<<mazeObstacles(n,m,maze);
}