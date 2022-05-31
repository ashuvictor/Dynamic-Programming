
https://takeuforward.org/data-structure/wildcard-matching-dp-34/


For every index of string S1, we have different options to match that index with string S2. Therefore, we can think in terms of string matching path as we have done already in previous questions.

Either the characters match already.
Or, if there is a ‘?’, we can explicitly match a single character.
For a ‘*’, the following figure explains the scenario.



Step 1: Express the problem in terms of indexes.

We are given two strings. We can represent them with the help of two indexes i and j. Initially, i=n-1 and j=m-1, where n and m are lengths of strings S1 and S2. Initially, we will call f(n-1,m-1), which means whether string S1[0…n-1] matches with string S2[0…m-1].


Step 2: Try out all possible choices at a given index.

Now, i and j represent two characters from strings S1 and S2 respectively. There are only two options that make sense: either the characters represented by i and j match or they don’t.

(i) When the characters match

if(S1[i]==S2[j]), 

If this is true, the characters at i and j match, we can simply move to the next characters of both the strings. So we will just decrement both i and j by 1 and recursively find the answer for the remaining string portions. We return f(i-1,j-1). The following figure makes it clear.

(ii) When the characters don’t match

If the characters don’t match, there are three possible scenarios:

S1[i] == ‘?’
S1[i] == ‘*’
S1[i] is some other character
Let us discuss them one by one:

(i) If S1[i] == ‘?’

In this case, we can explicitly match ‘?’ at index i of S1 with the corresponding character at index j of S2. And then recursively call f(i-1,j-1) to check for the remaining string.

(ii) If S1[i] == ‘*’

This is an interesting case as now ‘*’ can be replaced with any sequence of characters( of length 0 or more) from S2.

We will revisit this example:




To summarise:

If S1[i] == ‘?’, return f(i-1,j)
Else if S1[i] == ‘*’, return f(i-1,j) || f(i,j-1)
Else return false
Step 3: Return logical OR (||) of all the choices

If any of the cases return true, we can say that strings do match. We can use OR operator (||) with the recursive calls.

Base Cases:

We are reducing i and j in our recursive relation, there can be two possibilities, either i becomes -1 or j becomes -1., i,e we exhaust either S1 or S2 respectively.

(i) When S1 is exhausted:

When S1 is exhausted (i<0), we know that in order for the strings to match, String S2 should also exhaust simultaneously. If it does, we return true, else we return false.

We can say:

if(i<0 && j<0), return true.
if(i<0 && j>=0), return false.
(ii) When S2 is exhausted:

When S2 is exhausted(j<0) and S1 has not, there is only one pattern that can account for true(matching of strings). It is if S1 is like this “*”,”****”,”***”, i.e: S1 contains only stars. Then we can replace every star with a sequence of length 0 and say that the string match.

If S1 is all-stars, we return true, else return false.

The final pseudocode after steps 1, 2, and 3:




#include <bits/stdc++.h>

using namespace std;

bool isAllStars(string & S1, int i) {
  for (int j = 0; j <= i; j++) {
    if (S1[j] != '*')
      return false;
  }
  return true;
}

bool wildcardMatchingUtil(string & S1, string & S2, int i, int j, vector < vector < bool >> & dp) {

  //Base Conditions
  if (i < 0 && j < 0)
    return true;
  if (i < 0 && j >= 0)
    return false;
  if (j < 0 && i >= 0)
    return isAllStars(S1, i);

  if (dp[i][j] != -1) return dp[i][j];

  if (S1[i] == S2[j] || S1[i] == '?')
    return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);

  else {
    if (S1[i] == '*')
      return wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
    else return false;
  }
}

bool wildcardMatching(string & S1, string & S2) {

  int n = S1.size();
  int m = S2.size();

  vector < vector < bool >> dp(n, vector < bool > (m, -1));
  return wildcardMatchingUtil(S1, S2, n - 1, m - 1, dp);

}

int main() {

  string S1 = "ab*cd";
  string S2 = "abdefcd";

  if (wildcardMatching(S1, S2))
    cout << "String S1 and S2 do match";
  else cout << "String S1 and S2 do not match";
}




#include <bits/stdc++.h>

using namespace std;

bool isAllStars(string & S1, int i) {

  // S1 is taken in 1-based indexing
  for (int j = 1; j <= i; j++) {
    if (S1[j - 1] != '*')
      return false;
  }
  return true;
}

bool wildcardMatching(string & S1, string & S2) {

  int n = S1.size();
  int m = S2.size();

  vector < vector < bool >> dp(n + 1, vector < bool > (m, false));

  dp[0][0] = true;

  for (int j = 1; j <= m; j++) {
    dp[0][j] = false;
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = isAllStars(S1, i);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {

      if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];

      else {
        if (S1[i - 1] == '*')
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

        else dp[i][j] = false;
      }
    }
  }

  return dp[n][m];

}

int main() {

  string S1 = "ab*cd";
  string S2 = "abdefcd";

  if (wildcardMatching(S1, S2))
    cout << "String S1 and S2 do match";
  else cout << "String S1 and S2 do not match";
}




#include <bits/stdc++.h>

using namespace std;

bool isAllStars(string & S1, int i) {

  // S1 is taken in 1-based indexing
  for (int j = 1; j <= i; j++) {
    if (S1[j - 1] != '*')
      return false;
  }
  return true;
}

bool wildcardMatching(string & S1, string & S2) {

  int n = S1.size();
  int m = S2.size();

  vector < bool > prev(m + 1, false);
  vector < bool > cur(m + 1, false);

  prev[0] = true;

  for (int i = 1; i <= n; i++) {
    cur[0] = isAllStars(S1, i);
    for (int j = 1; j <= m; j++) {

      if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
        cur[j] = prev[j - 1];

      else {
        if (S1[i - 1] == '*')
          cur[j] = prev[j] || cur[j - 1];

        else cur[j] = false;
      }
    }
    prev = cur;
  }

  return prev[m];

}

int main() {

  string S1 = "ab*cd";
  string S2 = "abdefcd";

  if (wildcardMatching(S1, S2))
    cout << "String S1 and S2 do match";
  else cout << "String S1 and S2 do not match";
}