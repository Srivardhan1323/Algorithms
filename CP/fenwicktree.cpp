/*If we need to caluclate the sum in range[L,R] in a static array 
the we can use prefix sums...
But if we are updating the array we can't do it using prefix sums ..(TLE)
So we need to use Fenwick trees.
Fenwick tree update the prefix sum's in O(logN) and find the result in O(logN);
*/
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


int n;
vi v(2e5+1),bit(2e5+1,0);
void update(int i,int val)
{
	if(i>n)return;
	bit[i]+=val;
	update(i+(i&(-i)),val);
    //i&(-i) gives Least significant bit
}

int pre(int i)
{
	if(i==0)return 0;
	return bit[i]+pre(i-(i&(-i)));
}

void solve()
{
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		update(i,v[i]);
	}
	while(q--)
	{
		int t,l,r;
		cin>>t>>l>>r;
		if(t==1)
		{
			update(l,r-v[l]);
			v[l]=r;
		}
		else
		{
		   cout<<pre(r)-pre(l-1)<<endl;	
		}
	}
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