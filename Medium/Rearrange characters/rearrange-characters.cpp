//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        vector<pair<int,char>> arr(26);
        string ans;
        for(auto i:str){
            arr[int(i)-97].second=i;
            arr[int(i)-97].first+=1;
        }
        sort(arr.begin(),arr.end());
        // int count=0;
        // for(auto i:arr){
        //     cout<<i.first<<i.second<<endl;
        // }
        // for(int i=0;i<26;i++){
        //     if(arr[i].first==0){
        //         continue;
        //     }
        //     else{
        //         count=i;
        //         break;
        //     }
        // }
        if(str.length()<((arr[25].first)*2)-1){
            return  "-1";
        }
        for(int i=0;i<arr[25].first;i++){
            ans+=arr[25].second;
        }
        // count++;
        int k=1;
        // int tempc=0;
        int n=ans.length();
        for(int i=24;i>=0;i--){
            string temp;
            temp=arr[i].second;
            for(int j=0;j<arr[i].first;j++){
                ans.insert(k,temp);
                // cout<<"here ans "<<ans<<endl;
                // cout<<"here n"<<n<<endl;
                // cout<<"here k"<<k<<endl;
                // tempc++;
                // if(tempc==10){
                //     return 0;
                // }
                ++n;
                if(k==n-1){
                    k=0;
                }
                else{
                    k+=2;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends