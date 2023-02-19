//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string> ans;
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    sort(S.begin(),S.end());
		    int n=S.length();
		    string temp=S;
		    x(0,n,temp,S);
		    auto i=0;
		    while(i!=ans.size()){
		        auto j=i+1;
		        while(j!=ans.size()){
		            if(ans[j]==ans[i]){
		                ans.erase(ans.begin()+j);
		                continue;
		            }
		            else{
		               	j++;
		            }
		        }
		        i++;
		    }
		    return ans;
		}

		void x(int i,int n,string temp,string S){
		    int a=0;
		        while(a!=n){
		            if(S[a]=='0'){
		                a++;
		                continue;
		            }
		            temp[i]=S[a];
		            S[a]='0';
		            if(i==n-1){
		                ans.push_back(temp);
		                S[a]=temp[i];
		                return;
		            }
		            else{
		                x(i+1,n,temp,S);
		            }
		            S[a]=temp[i];
		            a++;
		        }
		    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends