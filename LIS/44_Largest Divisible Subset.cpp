


You are given an array of distinct numbers ‘arr’. Your task is to return the largest subset of numbers from ‘arr’, such that any pair of numbers ‘a’ and ‘b’ from the subset satisfies the following: a % b == 0 or b % a == 0.
For Example:
You are given ‘arr’ = [1, 16, 7, 8, 4] as you can the set {1, 4, 8, 16}, here you can take any pair from the set and either one of the elements from the pair will divide the other.


longest divisible subsequence
#include<bits/stdc++.h>
vector<int> divisibleSet(vector<int> &arr){
    // Write your code here.
    int n=arr.size();
    vector<int>dp(n,1),hash(n);
    int maxi=1;
    int lastIndex=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(arr[i]%arr[prev]==0 and dp[i]<dp[prev]+1)
            {
                dp[i]=1+dp[prev];
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi)
        {maxi=dp[i];lastIndex=i;
        }
        
    }
    vector<int>ans;
    ans.push_back(arr[lastIndex]);
    while(hash[lastIndex]!=lastIndex)
    {
        lastIndex=hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
    
}