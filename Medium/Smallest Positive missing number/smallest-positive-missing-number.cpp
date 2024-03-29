//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    {
        int s=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=0){
                arr[i]+=arr[s];
                arr[s]=arr[i]-arr[s];
                arr[i]-=arr[s];
                s++;
            }
        }
        for(int i=s;i<n;i++){
            if(abs(arr[i])<=n-s&&arr[s+abs(arr[i])-1]>0){
                arr[s+abs(arr[i])-1]=-arr[s+abs(arr[i])-1];
            }
        }
        for(int i=s;i<n;i++){
            if(arr[i]>0){
                return i-s+1;
            }
        }
        return n-s+1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends