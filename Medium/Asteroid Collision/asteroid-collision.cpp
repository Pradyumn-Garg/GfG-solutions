//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        stack<int> st;
        vector<int> ans;
        
        int i = 0;
        while(i < N){
            if(st.empty()){
                st.push(asteroids[i]);
                ++i;
            }
            else{
                if((asteroids[i] > 0 && st.top() > 0) || 
                (asteroids[i] < 0 && st.top() < 0) ||
                (asteroids[i] > 0 && st.top() < 0)){
                    st.push(asteroids[i]);
                    ++i;
                }
                else if(asteroids[i] < 0 && st.top() > 0){
                    int a = st.top();
                    st.pop();
                    
                    if(a == abs(asteroids[i]))
                        ++i;
                    else if(a > abs(asteroids[i])){
                        st.push(a);
                        ++i;
                    }
                    else if(a < abs(asteroids[i])){
                        continue;
                    }
                }
            }
        }
        
        while(!st.empty()){
            int a = st.top();
            st.pop();
            ans.push_back(a);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends