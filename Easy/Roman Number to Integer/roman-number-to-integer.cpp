//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        int ans=0;
        for(int i=str.length()-1;i>=0;i--){
            if(str[i]=='I'){
                ans=ans+1;
                continue;
            }
            if(str[i]=='V'){
                if(str[i-1]=='I'){
                    ans=ans+4;
                    i--;
                    continue;
                }
                else{
                    ans=ans+5;
                    continue;
                }
            }
            if(str[i]=='X'){
                if(str[i-1]=='I'){
                    ans=ans+9;
                    i--;
                    continue;
                }
                else{
                    ans=ans+10;
                    continue;
                }
            }
            if(str[i]=='L'){
                if(str[i-1]=='X'){
                    ans=ans+40;
                    i--;
                    continue;
                }
                else{
                    ans=ans+50;
                    continue;
                }
            }
            if(str[i]=='C'){
                if(str[i-1]=='X'){
                    ans=ans+90;
                    i--;
                    continue;
                }
                else{
                    ans=ans+100;
                    continue;
                }
            }
            if(str[i]=='D'){
                if(str[i-1]=='C'){
                    ans=ans+400;
                    i--;
                    continue;
                }
                else{
                    ans=ans+500;
                    continue;
                }
            }
            if(str[i]=='M'){
                if(str[i-1]=='C'){
                    ans=ans+900;
                    i--;
                    continue;
                }
                else{
                    ans=ans+1000;
                    continue;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends