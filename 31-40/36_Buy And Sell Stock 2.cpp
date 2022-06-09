



You have been given stock values/prices for N number of days. Every i-th day signifies the price of a stock on that day. Your task is to find the maximum profit which you can make by buying and selling the stocks.
 Note :
You may make as many transactions as you want but can not have more than one transaction at a time i.e, if you have the stock, you need to sell it first, and then only you can buy it again.




#include<bits/stdc++.h>
long solve(int ind,int buy,long *values,int n){
    if(ind==n)
        return 0;
    long profit=0;
    if(buy){
        profit=max(-values[ind]+solve(ind+1,0,values,n),0+solve(ind+1,1,values,n));
    }
    else{
        profit=max(values[ind]+solve(ind+1,1,values,n),solve(ind+1,0,values,n));
    }
}
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    return solve(0,1,values,n);
}




#include<bits/stdc++.h>
long solve(int ind,int buy,long *values,int n,vector<vector<long>>&dp){
    if(ind==n)
        return 0;
    long profit=0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    if(buy){
        profit=max(-values[ind]+solve(ind+1,0,values,n,dp),0+solve(ind+1,1,values,n,dp));
    }
    else{
        profit=max(values[ind]+solve(ind+1,1,values,n,dp),solve(ind+1,0,values,n,dp));
    }
    return dp[ind][buy]=profit;
}
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    vector<vector<long>>dp(n,vector<long>(2,-1));
    return solve(0,1,values,n,dp);
}



#include<bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    vector<vector<long>>dp(n+1,vector<long>(2,0));
    dp[n][0]=dp[n][1]=0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit=0;
             if(buy){
        profit=max(-values[ind]+dp[ind+1][0],0+dp[ind+1][1]);
    }
    else{
        profit=max(values[ind]+dp[ind+1][1],dp[ind+1][0]);
    }
 dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}


#include<bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
    vector<long>ahead(2,0),curr(2,0);
    ahead[0]=ahead[1]=0;
    
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            long profit=0;
             if(buy){
        profit=max(-values[ind]+ahead[0],0+ahead[1]);
    }
    else{
        profit=max(values[ind]+ahead[1],ahead[0]);
    }
 curr[buy]=profit;
        }
        ahead=curr;
        } 
    return ahead[1];
}




#include<bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
  long aHeadNotBuy,aHeadBuy,curBuy,curNotBuy;
    aHeadNotBuy=aHeadBuy=0;
    for(int ind=n-1;ind>=0;ind--){
      
        curNotBuy=max(values[ind]+aHeadBuy,0+aHeadNotBuy);
        curBuy=max(-values[ind]+aHeadNotBuy,0+aHeadBuy);
        aHeadBuy=curBuy;
        aHeadNotBuy=curNotBuy;
    }
return aHeadBuy;
}