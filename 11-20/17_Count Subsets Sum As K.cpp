
You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the 
array are there such that the sum of chosen elements is equal to the target number “tar”.


#include<bits/stdc++.h>
int solve(int ind,int tar,vector<int>&nums,vector<vector<int>>&dp){
    if(tar==0)
        return 1;
    if(ind==0)
        return nums[0]==tar;
    if(dp[ind][tar]!=-1)
        return dp[ind][tar];
    int notTake=solve(ind-1,tar,nums,dp);
    int take=0;
    if(nums[ind]<=tar)
        take=solve(ind-1,tar-nums[ind],nums,dp);
    return dp[ind][tar]=take+notTake;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here..
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    return solve(n-1,tar,num,dp);
}