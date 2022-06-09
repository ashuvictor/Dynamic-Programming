Given a number of stairs. Starting from the 0th stair we need to climb to the “Nth” stair.
 At a time we can climb either one or two steps. We need to return the total number of distinct ways to reach from 0th to Nth stair.


 When we see a problem, it is very important to identify it as a dynamic programming problem. Generally (but not limited to) if the problem statement asks for the following:

Count the total number of ways
Given multiple ways of doing a task, which way will give the minimum or the maximum output.
We can try to apply recursion. Once we get the recursive solution, we can go ahead to convert it to a dynamic programming one.


Once the problem has been identified, the following three steps comes handy in solving the problem:

Try to represent the problem in terms of indexes.
Try all possible choices/ways at every index according to the problem statement.
If the question states
Count all the ways – return sum of all choices/ways.
Find maximum/minimum- return the choice/way with maximum/minimum output.


#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=3;
  vector<int> dp(n+1,-1);
  
  dp[0]= 1;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}