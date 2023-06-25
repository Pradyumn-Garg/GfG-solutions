//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0,flag=0,n=grid.size(),m=grid[0].size();
        while(flag==0){
            flag=1;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]!=0&&grid[i][j]!=1&&grid[i][j]!=20+ans){
                        if(i-1>=0&&grid[i-1][j]==1){
                            flag=0;
                            grid[i-1][j]=20+ans;
                        }
                        if(i+1<n&&grid[i+1][j]==1){
                            flag=0;
                            grid[i+1][j]=20+ans;
                        }
                        if(j-1>=0&&grid[i][j-1]==1){
                            flag=0;
                            grid[i][j-1]=20+ans;
                        }
                        if(j+1<m&&grid[i][j+1]==1){
                            flag=0;
                            grid[i][j+1]=20+ans;
                        }
                    }
                }
            }
            if(flag==0){
                ++ans;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends