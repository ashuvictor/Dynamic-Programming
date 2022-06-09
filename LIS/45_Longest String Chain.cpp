



Practice
Guided Paths
Interview Prep
Challenges
New

Knowledge Centre
New

Community
New

 













Longest String Chain

Problem Statement
You are given an array ‘ARR’ of strings, where each string consists of English lowercase letters.
Let’s say a string ‘A’ is a predecessor of string ‘B’ if and only if we can add exactly one letter anywhere in ‘A’ to make it equal to ‘B’. For example “abd” is a predecessor of “abcd”, we can add “c” in “abd” to make a string “abcd”
A string chain is a sequence of strings where for every ‘i’ in [1 . . . (K - 1)], ‘Si’ is the predecessor of ‘Si+1’. And the length of such a string chain is ‘K’.
Now your task is to find the length of the longest possible string chain.
For Example :
Let ‘ARR’ = ["x", “xx”, “y”, “xyx”] 
The longest possible string chain is “x” -> “xx” -> “xyx”
The length of the given chain is 3, hence the answer is 3.






#include<bits/stdc++.h>
bool solve(string x ,string y)
{
    if(x.size()!=y.size()+1)
        return false;
    int first=0;
    int second=0;
    while(first<x.size())
    {
        if(x[first]==y[second])
        {
            first++;second++;
        }
        else
        {
            first++;
        }
    }
    if(first==x.size() and second==y.size())
        return true;
    else
        return false;
}
static bool comp(string x,string y){
    return x.size()<y.size();
}
int longestStrChain(vector<string> &arr)
{  int n=arr.size(); vector<int>dp(n,1);
 int maxi=1;
 sort(arr.begin(),arr.end(),comp);
 for(int i=1;i<n;i++){
     for(int j=0;j<i;j++){
         if(solve(arr[i],arr[j]) and dp[i]<1+dp[j])
         {
             dp[i]=1+dp[j];
         }
     }
   maxi=max(maxi,dp[i]);  
 }
 
 return maxi;
    // Write your code here.
}





