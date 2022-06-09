



We are given two strings ‘S1’ and ‘S2’. We need to convert S1 to S2. The following three operations are allowed:

Deletion of a character.
Replacement of a character with another one.
Insertion of a character.
We have to return the minimum number of operations required to convert S1 to S2 as our answer.




ii) When the characters don’t match

if(S1[i] != S2[j]) is true, then we have to do any of three operations to match the characters. We have three options, we will analyze each of them one by one.




#include <bits/stdc++.h>
using namespace std;

int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp){
    
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
        
    if(dp[i][j]!=-1) return dp[i][j];
        
    if(S1[i]==S2[j])
        return dp[i][j] =  0+editDistanceUtil(S1,S2,i-1,j-1,dp);
        
    // Minimum of three choices
    else return dp[i][j] = 1+min(editDistanceUtil(S1,S2,i-1,j-1,dp),
    min(editDistanceUtil(S1,S2,i-1,j,dp),editDistanceUtil(S1,S2,i,j-1,dp)));
    
}

int editDistance(string& S1, string& S2){
    
    int n = S1.size();
    int m = S2.size();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return editDistanceUtil(S1,S2,n-1,m-1,dp);
    
}

int main() {

  string s1 = "horse";
  string s2 = "ros";

  cout << "The minimum number of operations required is: "<<editDistance(s1,s2);
}





#include <bits/stdc++.h>

using namespace std;


int editDistance(string& S1, string& S2){
    
    int n = S1.size();
    int m = S2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                dp[i][j] = 0+dp[i-1][j-1];
            
            else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    
    return dp[n][m];
    
}


int main() {

  string s1 = "horse";
  string s2 = "ros";

  cout << "The minimum number of operations required is: "<<editDistance(s1,s2);
}





#include <bits/stdc++.h>

using namespace std;


int editDistance(string& S1, string& S2){
    
    int n = S1.size();
    int m = S2.size();
    
    vector<int> prev(m+1,0);
    vector<int> cur(m+1,0);
    
    for(int j=0;j<=m;j++){
        prev[j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        cur[0]=i;
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                cur[j] = 0+prev[j-1];
            
            else cur[j] = 1+min(prev[j-1],min(prev[j],cur[j-1]));
        }
        prev = cur;
    }
    
    return prev[m];
    
}

int main() {

  string s1 = "horse";
  string s2 = "ros";

  cout << "The minimum number of operations required is:  "<<editDistance(s1,s2);
}