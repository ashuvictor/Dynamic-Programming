
Problem Statement
Given an integer array ‘ARR’ of length ‘N’, return the number of longest increasing subsequences in it.
The longest increasing subsequence(LIS) is the longest subsequence of the given sequence such that all elements of the subsequence are in increasing order.
Note :
The subsequence should be a strictly increasing sequence.

#include<bits/stdc++.h>
int findNumberOfLIS(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
     vector<int>dp(n,1),cnt(n,1);
    int maxi=1;
     for(int i=1;i<n;i++){
     for(int j=0;j<i;j++){
         if(arr[j]<arr[i] and dp[i]<1+dp[j])
         {
             dp[i]=1+dp[j];cnt[i]=cnt[j];
         }
         else if(arr[j]<arr[i] and 1+dp[j]==dp[i])
         {
             cnt[i]+=cnt[j];
         }
     }
         maxi=max(maxi,dp[i]);
 
 }int count=0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi)
          count+=cnt[i];  
    }
    return count;
}