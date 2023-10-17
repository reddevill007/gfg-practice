//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    int dp[100001];
    
    int solve(int arr[], int idx, int n) {
        if(idx >= n) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int steal = arr[idx] + solve(arr, idx + 2, n);
        int skip = solve(arr, idx + 1, n);
        
        return dp[idx] = max(steal, skip);
    }
    public:
    int FindMaxSum(int arr[], int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(arr, 0, n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends