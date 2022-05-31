

We are given ‘n’ distinct numbers. Their denomination is represented by the ‘arr’ array. So clearly one parameter will be ‘ind’, i.e index up to which the array items are being considered.

There is one more parameter “T”. We need to know the given target that we want to achieve.

So, we can say that initially, we need to find f(n-1, T) where T is the initial target given to us. f(n-1, T) means we are finding the minimum number of coins required to form the target sum by considering coins from index 0 to n-1.



You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.
Note:
You have an infinite number of elements of each type.
For Example
If N=3 and X=7 and array elements are [1,2,3]. 
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.


If ind==0, it means we are at the first item, so in that case, the following cases can arise:

arr[0] = 4 and T = 12
In such a case where the target is divisible by the coin element, we will return T%arr[0].

arr[0] =4 and T=1 , arr[0]=3 T=10
 In all other cases, we will not be able to form a solution, so we will return a big number like 1e9




 #include <bits/stdc++.h>

using namespace std;

int minimumElementsUtil(vector<int>& arr, int ind, int T, vector<vector<int>>& dp){

    if(ind == 0){
        if(T%arr[0] == 0) return T/arr[0];
        else return 1e9;
    }
    
    if(dp[ind][T]!=-1)
        return dp[ind][T];
        
    int notTaken = 0 + minimumElementsUtil(arr,ind-1,T,dp);
    
    int taken = 1e9;
    if(arr[ind] <= T)
        taken = 1 + minimumElementsUtil(arr,ind,T-arr[ind],dp);
        
    return dp[ind][T] = min(notTaken,taken);
}


int minimumElements(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,-1));
    int ans =  minimumElementsUtil(arr, n-1, T, dp);
    if(ans >= 1e9) return -1;
    return ans;
}

int main() {

  vector<int> arr ={1,2,3};
  int T=7;
                                 
  cout<<"The minimum number of coins required to form the target sum is " 
  <<minimumElements(arr,T);
}





#include <bits/stdc++.h>

using namespace std;

int minimumElements(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
}

int main() {

  vector<int> arr ={1,2,3};
  int T=7;
                                 
  cout<<"The minimum number of coins required to form the target sum is " 
  <<minimumElements(arr,T);
}





#include <bits/stdc++.h>

using namespace std;

int minimumElements(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<int> prev(T+1,0), cur(T+1,0);
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            prev[i] = i/arr[0];
        else prev[i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + prev[target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + cur[target - arr[ind]];
                
             cur[target] = min(notTake, take);
        }
        prev = cur;
    }
    
    int ans = prev[T];
    if(ans >=1e9) return -1;
    return ans;
}


int main() {

  vector<int> arr ={1,2,3};
  int T=7;
                                 
  cout<<"The minimum number of coins required to form the target sum is " 
  <<minimumElements(arr,T);
}