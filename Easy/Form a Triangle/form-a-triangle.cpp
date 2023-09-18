//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int noOfTriangles( vector<int> v, int n)
    {
        sort(v.begin(),v.end());
        int count = 0;
        for(int i = n-1;i>=2;i--)
        {
            // 2 pointer game
            int low = 0;
            int high = i-1;
            while(low < high)
            {
                if(v[low] + v[high] > v[i])
                {
                    count += high - low;
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> v(n);
	    
	    for(int i = 0; i < n; i++)
	        cin >> v[i];
	    Solution ob;
	    cout << ob.noOfTriangles(v, n) << endl;
	}
	return 0;
}
// } Driver Code Ends