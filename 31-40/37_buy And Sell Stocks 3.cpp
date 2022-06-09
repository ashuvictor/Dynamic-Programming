


You are Harshad Mehta’s friend. He told you the price of a particular stock for the next ‘N’ days. You can either buy or sell a stock. Also, you can only complete at most 2-transactions. Find the maximum profit that you can earn from these transactions. You can take help from Mr. Mehta as well.
Note
1. Buying a stock and then selling it is called one transaction. 
2. You are not allowed to do multiple transactions at the same time. This means you have to sell the stock before buying it again. 

#include<bits/stdc++.h>
int solve(int ind,int buy,int cap,vector<int>&prices,int n){
    if(ind==n)
        return 0;
    if(cap==0)
        return 0;
    long profit=0;
    if(buy)
    {
        profit=max(-prices[ind]+solve(ind+1,0,cap,prices,n),solve(ind+1,1,cap,prices,n));
    }
    else{
        profit=max(prices[ind]+solve(ind+1,1,cap-1,prices,n),solve(ind+1,0,cap,prices,n));
    }
    return profit;
}
int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    return solve(0,1,2,prices,n);
}





#include<bits/stdc++.h>
int solve(int ind,int buy,int cap,vector<int>&prices,int n,
         vector<vector<vector<int>>>&dp){
    if(ind==n)
        return 0;
    if(cap==0)
        return 0;
    if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];
    long profit=0;
    if(buy)
    {
        profit=max(-prices[ind]+solve(ind+1,0,cap,prices,n,dp),solve(ind+1,1,cap,prices,n,dp));
    }
    else{
        profit=max(prices[ind]+solve(ind+1,1,cap-1,prices,n,dp),solve(ind+1,0,cap,prices,n,dp));
    }
    return dp[ind][buy][cap]=profit;
}
int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return solve(0,1,2,prices,n,dp);
}



#include<bits/stdc++.h>

int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                int profit=0;
                  
    if(buy)
    {
        profit=max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
    }
    else{
        profit=max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
    }
     dp[ind][buy][cap]=profit;
            }
        }
    }
    return dp[0][1][2];
}



#include<bits/stdc++.h>

int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
   vector<vector<int>>after(2,vector<int>(3,0));
    vector<vector<int>>curr(2,vector<int>(3,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                int profit=0;
                  
    if(buy)
    {
        profit=max(-prices[ind]+after[0][cap],after[1][cap]);
    }
    else{
        profit=max(prices[ind]+after[1][cap-1],after[0][cap]);
    }
    curr[buy][cap]=profit;
            }
        }
        after=curr;
    }
    return after[1][2];
}