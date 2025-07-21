 #include <vector>
using namespace std;


int getnCk(int n, int k, vector<vector<int>> & dp) {
  
    // k can not be grater then k so we
  	// return 0 here
    if (k > n)
        return 0;
  
  	// base condition when k and n are 
  	// equal or k = 0
    if (k == 0 || k == n)
        return 1;
	
  	// Check if pair n and k is already 
  	// calculated then return it from here
  	if(dp[n][k] != -1) return dp[n][k];
  
    // Recurvie add the value and store to memorize table
    return dp[n][k] = getnCk(n - 1, k - 1, dp) 
      					+ getnCk(n - 1, k, dp);
}
int binomialCoeff(int n, int k) {
  	
  	// Create table for memorization
	vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
  
  	return getnCk(n, k, dp);
}