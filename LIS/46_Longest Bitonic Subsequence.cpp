


You are given an array/list 'ARR' consisting of 'N' positive integers. A subsequence of 'ARR' is called bitonic if it is first increasing and then decreasing.
For Example:
An example of a bitonic sequence will be 1 < 2 < 3 < 4 > 2 > 1.
Your task is to return the length of the longest bitonic sequence of 'ARR'.
A subsequence of an array is an ordered subset of the array's elements having the same sequential ordering as the original array.
For Example:
Let ARR = [1, 2, 1, 2, 1]

One of the bitonic subsequences for this array will be [1, 2, 2, 1].




#include<bits/stdc++.h>
int longestBitonicSequence(vector<int>& arr, int n) {
	 
    vector<int>dp(n,1);
    vector<int>dp1(n,1);
    
    for(int i=1;i<n;i++){
     for(int j=0;j<i;j++){
         if(arr[j]<arr[i] and dp[i]<1+dp[j])
         {
             dp[i]=1+dp[j];
         }
     }
 
 }
    
      for(int i=n-1;i>=0;i--){
     for(int j=n-1;j>i;j--){
         if(arr[j]<arr[i] and dp1[i]<1+dp1[j])
         {
             dp1[i]=1+dp1[j];
         }
     }
 
 }
    int maxi=1;
    for(int i=0;i<n;i++){
        maxi=max(maxi,dp[i]+dp1[i]-1);
    }
    return maxi;
    
} 