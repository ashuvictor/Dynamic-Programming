



Problem Statement
For a given array with N elements, you need to find the length of the longest subsequence from the array such that all the elements of the subsequence are sorted in strictly increasing order.
Strictly Increasing Sequence is when each term in the sequence is larger than the preceding term.
For Example:
[1, 2, 3, 4] is a strictly increasing array, while [2, 1, 4, 3] is not.



#include<bits/stdc++.h>
int solve(int ind,int prev_ind,int arr[],int n)
{
    if(ind==n)
        return 0;
    int len=0+solve(ind+1,prev_ind,arr,n);
    if(prev_ind==-1 or arr[prev_ind]<arr[ind])
        len=max(len,1+solve(ind+1,ind,arr,n));
    return len;
        
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    return solve(0,-1,arr,n);
}



#include<bits/stdc++.h>
int solve(int ind,int prev_ind,int arr[],int n,vector<vector<int>>&dp)
{
    if(ind==n)
        return 0;
    if(dp[ind][prev_ind+1]!=-1)
        return dp[ind][prev_ind+1];
    int len=0+solve(ind+1,prev_ind,arr,n,dp);
    if(prev_ind==-1 or arr[prev_ind]<arr[ind])
        len=max(len,1+solve(ind+1,ind,arr,n,dp));
    return dp[ind][prev_ind+1]=len;
        
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return solve(0,-1,arr,n,dp);
}




int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int len=0+dp[ind+1][prev_ind+1];
            if(prev_ind==-1 or arr[prev_ind]<arr[ind])
                len=max(len,1+dp[ind+1][ind+1]);
            dp[ind][prev_ind+1]=len;
        }
    }
    return dp[0][0];
}



int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int>next(n+1,0),curr(n+1,0);
     for(int ind=n-1;ind>=0;ind--)
    {
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int len=0+next[prev_ind+1];
            if(prev_ind==-1 or arr[ind]>arr[prev_ind])
                len=max(len,1+next[ind+1]);
            curr[prev_ind+1]=len;
        }
         next=curr;
}
    return next[0];
}



int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
vector<int>dp(n,1);int maxi=0;
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[prev]<arr[i])
                dp[i]=max(dp[i],1+dp[prev]);
        }
        maxi=max(maxi,dp[i]);
    }
    return maxi;
 
}
