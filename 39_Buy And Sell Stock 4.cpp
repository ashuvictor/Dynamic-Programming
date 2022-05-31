



You are given a list of stock prices, ‘prices’. Where ‘prices[i]’ represents the price on ‘i’th day. Your task is to calculate the maximum profit you can earn by trading stocks if you can only hold one stock at a time. After you sell your stock on the ‘i’th day, you can only buy another stock on ‘i + 2’ th day or later.
For Example:
You are given prices = {4, 9, 0, 4, 10}, To get maximum profits you will have to buy on day 0 and sell on day 1 to make a profit of 5, and then you have to buy on day 3  and sell on day 4 to make the total profit of 11. Hence the maximum profit is 11.


same as buy and sell


#include<bits/stdc++.h>
int solve(int ind,int buy,vector<int>prices){
    if(ind>=prices.size())
        return 0;
    int profit=0;
    if(buy==1)
    {
        profit=max(-prices[ind]+solve(ind+1,0,prices),solve(ind+1,1,prices));
    }
    else
    {
        profit=max(prices[ind]+solve(ind+2,1,prices),solve(ind+1,0,prices));
    }
    return profit;
}
int stockProfit(vector<int> &prices){
    // Write your code here.
    return solve(0,1,prices);
}



#include<bits/stdc++.h>
int solve(int ind,int buy,vector<int>prices,vector<vector<int>>&dp){
    if(ind>=prices.size())
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    int profit=0;
    if(buy==1)
    {
        profit=max(-prices[ind]+solve(ind+1,0,prices,dp),solve(ind+1,1,prices,dp));
    }
    else
    {
        profit=max(prices[ind]+solve(ind+2,1,prices,dp),solve(ind+1,0,prices,dp));
    }
    return dp[ind][buy]=profit;
}
int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return solve(0,1,prices,dp);
}



int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
                if(buy==1)
    {
        profit=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
    }
    else
    {
        profit=max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
    }
            dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}




#include<bits/stdc++.h>

int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));
    for(int ind=n-1;ind>=0;ind--){
       
    
        dp[ind][1]=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
   
       dp[ind][0]=max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
    
        
    }
    return dp[0][1];
}
