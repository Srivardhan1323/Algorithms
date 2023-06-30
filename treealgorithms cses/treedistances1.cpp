#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
void yesno(int i){if(i)cout<<"YES"<<endl;else cout<<"NO"<<endl;}
 vector<int>disti;
 int bfs(int i,vector<vector<int>>adj)
{
	
	int n=adj.size()-1;
	disti.resize(n+1);
	vector<int>visited(n+1,0);
	visited[i]=1;
	queue<int>q;
	q.push(i);
	disti[i]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto it:adj[x])
		{
			if(visited[it]==0)
			{
				visited[it]=1;
				disti[it]=disti[x]+1;
				q.push(it);
			}
		}
	}
	int temp=-1,dist=-1;
	for(int i=1;i<=n;i++)
	{
		if(disti[i]>=dist)
		{
			dist=disti[i];
			temp=i;
		}
	}
	return temp;
}
void solve()
{
	int n;
	cin>>n;
	vector<vector<int>>adj(n+1);
	int u,v;
	for(int i=1;i<=n-1;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int>dist1(n+1),dist2(n+1);
	int corner1=bfs(1,adj);
	int corner2=bfs(corner1,adj);
	dist1=disti;
	bfs(corner2,adj);
	dist2=disti;
	for(int i=1;i<=n;i++)cout<<max(dist1[i],dist2[i])<<" ";
	cout<<endl;
}
int32_t main()
{  
   fast;
   int t;
   //cin>>t;
   t=1;
   while(t--)
   {
     solve();
   }
}