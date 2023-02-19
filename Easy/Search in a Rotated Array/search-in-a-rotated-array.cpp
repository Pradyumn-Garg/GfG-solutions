//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int A[], int l, int h, int key){
        if (l > h)
        return -1;

        int mid = (l + h) / 2;
        if (A[mid] == key)
            return mid;
    
        /* If arr[l...mid] is sorted */
        if (A[l] <= A[mid]) {
            /* As this subarray is sorted, we can quickly
            check if key lies in half or other half */
            if (key >= A[l] && key <= A[mid])
                return search(A, l, mid - 1, key);
            /*If key not lies in first half subarray,
               Divide other half  into two subarrays,
               such that we can quickly check if key lies
               in other half */
            return search(A, mid + 1, h, key);
        }
    
        /* If arr[l..mid] first subarray is not sorted, then
        arr[mid... h] must be sorted subarray */
        if (key >= A[mid] && key <= A[h])
            return search(A, mid + 1, h, key);
    
        return search(A, l, mid - 1, key);
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends