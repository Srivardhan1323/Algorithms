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
void yesno(int i){if(i)cout<<"YES"<<endl;else cout<<"NO"<<endl;}
/*********************************************************************************************************************
You will be given an array a of non -ve integers with size<=3e5.
 a[i]<=10^9. 
Find number of pairs such that a[i]>a[j] and i<j.
*********************************************************************************************************************/
int ans=0;
void fun(int bit,vi arr)
{
	if(arr.size()==0)return;
	int inv=0,cnt=0;
	vi arr0,arr1;
	for(auto it:arr)
	{
		if((it&(1<<bit)))
		{
			cnt++;
			arr1.pb(it);
		}
		else
		{
			inv+=cnt;
			arr0.pb(it);
		}
	}
	ans+=inv;
	if(bit==0)return;
	fun(bit-1,arr0);
	fun(bit-1,arr1);
}
void solve()
{
	int n;
	cin>>n;
	vi arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	fun(30,arr);
	cout<<ans<<endl;
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