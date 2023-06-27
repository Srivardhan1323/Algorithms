
void dfs(int node ,int par)
{
    for(auto it:adj[node])
    {
        if(it!=par)dfs(it,node);
    }
}
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