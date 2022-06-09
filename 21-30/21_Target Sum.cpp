

We are given an array ‘ARR’ of size ‘N’ and a number ‘Target’. Our task is to build an expression from the given array where we can place a ‘+’ 
or ‘-’ sign in front of an integer. We want to place a sign in front of every integer of the array and get our required target.
 We need to count the number of ways in which we can achieve our required target.


 #include <bits/stdc++.h>

using namespace std;

int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector<int>> 
&dp){

     if(ind == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = countPartitionsUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = countPartitionsUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken);
}

int targetSum(int n,int target, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-target<0) return 0;
    if((totSum-target)%2==1) return 0;
    
    int s2 = (totSum-target)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return countPartitionsUtil(n-1,s2,arr,dp);
}

int main() {

  vector<int> arr = {1,2,3,1};
  int target=3;
                     
  int n = arr.size();            
  cout<<"The number of ways found is " <<targetSum(n,target,arr);
}




#include <bits/stdc++.h>

using namespace std;

int mod =(int)1e9+7;

int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken)%mod;
        }
    }
    return dp[n-1][tar];
}

int targetSum(int n, int target, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<n;i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-target <0 || (totSum-target)%2 ) return 0;
    
    return findWays(arr,(totSum-target)/2);
}
  

int main() {

  vector<int> arr = {1,2,3,1};
  int target=3;
                     
  int n = arr.size();            
  cout<<"The number of ways found is " <<targetSum(n,target,arr);
}





#include <bits/stdc++.h>

using namespace std;

int mod =(int)1e9+7;

int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<int> prev(tar+1,0);
    
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(tar+1,0);
        for(int target= 0; target<=tar; target++){
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= (notTaken + taken)%mod;
        }
        prev = cur;
    }
    return prev[tar];
}

int targetSum(int n, int target, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<n;i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-target <0 || (totSum-target)%2 ) return 0;
    
    return findWays(arr,(totSum-target)/2);
}
  

int main() {

  vector<int> arr = {1,2,3,1};
  int n = arr.size();
  int target=3;
                                 
  cout<<"The number of subsets found is " <<targetSum(n,target,arr);
}