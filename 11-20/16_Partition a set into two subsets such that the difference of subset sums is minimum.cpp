


https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

You are given an array containing N non-negative integers. Your task is to partition this array into two subsets such that the absolute
 difference between subset sums is minimum.
You just need to find the minimum absolute difference considering any valid division of the array elements.


The array will have an index but there is one more parameter “target”. We are given the initial problem to find whether there exists in the whole array a subsequence whose sum is equal to the target.

So, we can say that initially, we need to find(n-1, target) which means that we need to find whether there exists a subsequence in the array 
from index 0 to n-1, whose sum is equal to the target. Similarly, 
we can generalize it for any index ind as follows


If target == 0, it means that we have already found the subsequence from the previous steps, so we can return true.
If ind==0, it means we are at the first element, so we need to return arr[ind]==target. If the element is equal to the target we return true else false.



Exclude the current element in the subsequence: We first try to find a subsequence without considering the current index element. For this, we will make a recursive call to f(ind-1,target).
Include the current element in the subsequence: We will try to find a subsequence by considering the current index as element as part of subsequence. As we have included arr[ind], the updated target which we need to find in the rest if the array will be target – arr[ind]. Therefore, we will call f(ind-1,target-arr[ind]).


As we are looking for only one subset, if any of the one among taken or not taken returns true, we can return true from our function. Therefore, we return ‘or(||)’ of both of them.

The final pseudocode after steps 1, 2, and 3:




#include <bits/stdc++.h>

using namespace std;

bool subsetSumUtil(int ind, int target, vector < int > & arr, vector < vector 
< int >> & dp) {
  if (target == 0)
    return dp[ind][target]=true;

  if (ind == 0)
    return dp[ind][target] = arr[0] == target;

  if (dp[ind][target] != -1)
    return dp[ind][target];

  bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

  bool taken = false;
  if (arr[ind] <= target)
    taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

  return dp[ind][target] = notTaken || taken;
}

int minSubsetSumDifference(vector < int > & arr, int n) {

  int totSum = 0;

  for (int i = 0; i < n; i++) {
    totSum += arr[i];
  }

  vector < vector < int >> dp(n, vector < int > (totSum + 1, -1));

  for (int i = 0; i <= totSum; i++) {
    bool dummy = subsetSumUtil(n - 1, i, arr, dp);
  }

  int mini = 1e9;
  for (int i = 0; i <= totSum; i++) {
    if (dp[n - 1][i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
    }
  }
  return mini;

}

int main() {

  vector < int > arr = {1,2,3,4};
  int n = arr.size();

  cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);

}



#include <bits/stdc++.h>

using namespace std;

int minSubsetSumDifference(vector < int > & arr, int n) {
  int totSum = 0;

  for (int i = 0; i < n; i++) {
    totSum += arr[i];
  }

  vector < vector < bool >> dp(n, vector < bool > (totSum + 1, false));

  for (int i = 0; i < n; i++) {
    dp[i][0] = true;
  }

  if (arr[0] <= totSum)
    dp[0][totSum] = true;

  for (int ind = 1; ind < n; ind++) {
    for (int target = 1; target <= totSum; target++) {

      bool notTaken = dp[ind - 1][target];

      bool taken = false;
      if (arr[ind] <= target)
        taken = dp[ind - 1][target - arr[ind]];

      dp[ind][target] = notTaken || taken;
    }
  }

  int mini = 1e9;
  for (int i = 0; i <= totSum; i++) {
    if (dp[n - 1][i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
    }
  }
  return mini;
}

int main() {

  vector<int> arr = {1,2,3,4};
  int n = arr.size();

  cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);
}
Output:

The minimum absolute difference is: 0

Time Complexity: O(N*totSum) +O(N) +O(N)

Reason: There are two nested loops that account for O(N*totSum), at starting we are running a for loop to calculate totSum and at last a for loop to traverse the last row.

Space Complexity: O(N*totSum)

Reason: We are using an external array of size ‘N * totSum’. Stack Space is eliminated.




#include <bits/stdc++.h>

using namespace std;

int minSubsetSumDifference(vector < int > & arr, int n) {
  int totSum = 0;

  for (int i = 0; i < n; i++) {
    totSum += arr[i];
  }

  vector < bool > prev(totSum + 1, false);

  prev[0] = true;

  if (arr[0] <= totSum)
    prev[arr[0]] = true;

  for (int ind = 1; ind < n; ind++) {
    vector < bool > cur(totSum + 1, false);
    cur[0] = true;
    for (int target = 1; target <= totSum; target++) {
      bool notTaken = prev[target];

      bool taken = false;
      if (arr[ind] <= target)
        taken = prev[target - arr[ind]];

      cur[target] = notTaken || taken;
    }
    prev = cur;
  }

  int mini = 1e9;
  for (int i = 0; i <= totSum; i++) {
    if (prev[i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
    }
  }
  return mini;
}

int main() {

  vector<int> arr = {1,2,3,4};
  int n = arr.size();

  cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);
}