//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=l;i<=r;i++){
            low=min(low,arr[i]);
            high=max(high,arr[i]);
        }
        while(low<high){
            int mid=(low+high)/2;
            int res=check(arr,mid,r+1,k);
            if(res==1){
                return mid;
            }
            if(res==-1){
                low=mid+1;
                continue;
            }
            if(res==0){
                high=mid-1;
                continue;
            }
        }
    }
    
    int check(int arr[], int x, int n, int k){
        int count_low=0,count_eq=0;
        for(int i=0;i<n;i++){
            if(arr[i]<x){
                count_low++;
            }
            if(arr[i]==x){
                count_eq++;
            }
        }
        if(count_low>=k){
            return 0;
        }
        if(count_low+count_eq>=k){
            return 1;
        }
        return -1;
    }
    
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends