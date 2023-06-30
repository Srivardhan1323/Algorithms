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


vvi adj(1e5+1);//assuming no of vertices<=1e5
int n;//no of vertices

/* DFS 
  TC O(V+E)
  SC O(V)auxilary stack space+O(V)
*/
void dfs(int node ,vi &vis)
{
    for(auto it:adj[node])
    {
        if(vis[it]==0){vis[it]=1;dfs(it,vis);}
    }
}
/* BFS 
   TC O(V+E)
   SC O(V)
*/
void bfs(int node)
{
    queue<int>q;
    vector<int>visited(n,0);
    q.push(node);
    visited[node]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto it:adj[x])
        {
           if(!visited[it])
           {
              visited[it]=1;
              q.push(it);
           }
        }
    }
}
/* DIJKISTRA 
  TC O(V+Elog(E))
  SC O(V);
  DIJKISTRA IS VALID ONLY FOR GRAPHS WITH NON NEGATIVE EDGES.
*/
vi dij(vector<vector<pair<int,int>>>adj,int node)
{
	vi ans(adj.size(),1e9);
	ans[node]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,node});
	while(!pq.empty())
	{
		pair<int,int>p=pq.top();
		pq.pop();
        if(p.ff>ans[p.ss]){continue;}
        /*THERE IS A WAY TO REACH NODE P IN SMALLER DISTANCE.
        SO SKIP IT.*/
		for(auto it:adj[p.ss])
		{
			if(ans[it.ff]>p.ff+it.ss)
			{
				ans[it.ff]=p.ff+it.ss;
				pq.push({ans[it.ff],it.ff});
			}
		}
	}
	return ans;
}
/*
   FLOYD WARSHALLS ALGORITHM
   TC O(N^3)
   SC O(N^2)
   Used to find shortest path to every node from every node
   Can be used to find if there is anynegative cycle present .
   If negative cycle is present then dist[i][i] becomes negative for some node
*/
vvi floyd(vvi adj)
{
    vvi dist(n+1,vi(n+1,1e9));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)dist[i][j]=0;
            else if(adj[i][j]!=-1)dist[i][j]=adj[i][j];
        }
    }
    for(int via=1;via<=n;via++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
            }
        }
    }
    return dist;
}
vi toposort(vvi adj)
{
    vi indeg(n+1,0);
    for(int i=1;i<=n;i++)
    {
        for(auto it:adj[i])indeg[it]++;
    }
    queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(indeg[i]==0)q.push(i);
	}
	vi ans;
	while(q.size())
	{
		int x=q.front();
		q.pop();
		ans.pb(x);
		for(auto it:adj[x])
		{
			indeg[it]--;
			if(indeg[it]==0)q.push(it);
		}
	}
    int n1=ans.size();
	if(n1!=n){return {-1};}
    //It is not possible i.e there is a cycle detected somewhere in a graph
	return ans;
}
int32_t main()
{  
   //take inputs of vertices and adjacency list;
}