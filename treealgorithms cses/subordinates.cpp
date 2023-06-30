#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define ff first
#define ss second
#define pb(x) push_back(x)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
vvi adj(2e5+1);
vi dp(2e5+1,0);
int dfs(int node)
{
	int n=adj[node].size();
	if(n==0 || dp[node])return dp[node];
	for(auto it:adj[node])
	{
		dp[node]+=1+dfs(it);
	}
	return dp[node];
}
int32_t main()
{  
   fast;
   int n;
   cin>>n;
   
   int x;
   for(int i=2;i<=n;i++)
   {
	   	 cin>>x;
	   	 adj[x].pb(i);
   }
   
   dfs(1);
   for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
   cout<<endl;
}