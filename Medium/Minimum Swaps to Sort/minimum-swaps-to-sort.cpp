//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int, int>> pr;
	    
	    for(int i = 0; i < nums.size(); i++) {
	        pr.push_back({nums[i], i});
	    }
	    
	    sort(pr.begin(), pr.end());
	    bool vis[nums.size()];
	    
	    int swaps = 0;
	    
	    for(int i = 0; i < nums.size(); i++) {
	        auto it = pr[i];
	        int idx = it.second;
	        
	        if(pr[i].second != i) {
	            swaps++;
	            swap(pr[i], pr[idx]);
	            i--;
	        }
	    }
	    
	    return swaps;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends