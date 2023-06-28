/* DFS 
  TC O(V+E)
  SC O(V)auxilary stack space+O(V)
*/
void dfs(int node ,int par)
{
    for(auto it:adj[node])
    {
        if(it!=par)dfs(it,node);
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