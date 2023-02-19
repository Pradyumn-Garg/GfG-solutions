//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    int count=0;
	    sort(arr,arr+n);
	    for(int j=0;j<n-2;j++){
	        if(arr[j]+arr[j+1]>arr[n-1]){
	            break;
	        }
	        int curr=j+2;
	        for(int i=j+1;i<n;i++){
    	        if(arr[j]+arr[i]==arr[curr]){
    	            count++;
    	        }
    	        if(arr[j]+arr[i]>arr[curr]&&curr<n-1){
    	            curr++;
    	            i--;
    	        }
    	        if(arr[j]+arr[i]>arr[curr]&&curr==n-1){
    	            break;
    	        }
	        }
	    }
	    return count;
	}
};

//{ Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends