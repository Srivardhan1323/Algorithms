<<<<<<< HEAD
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
// refer https://codeforces.com/contest/1846/problem/C for betterunderstanding.
bool compare(pair<int,pii>p1,pair<int,pii>p2)
{
	if(p1.ff>p2.ff)return 1;//returning 1 means p1 should be before p2
	else if(p1.ff<p2.ff)return 0;
	else if(p1.ss.ff<p2.ss.ff)return 1;
	else if(p1.ss.ff>p2.ss.ff) return 0;
	return p1.ss.ss<p2.ss.ss;
}
void solve()
{
    int n;
    cin>>n;
	vector<pair<int,pii>>p(n);
    for(int i=0;i<n;i++)cin>>p[i].ff>>p[i].ss.ff>>p[i].ss.ss;
	sort(p.begin(),p.end(),compare);//calling comparefn
}
int32_t main()
{  
   fast;
   int t;
   cin>>t;
   //t=1;
   while(t--)
   {
   	 solve();
   }
=======
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
// refer https://codeforces.com/contest/1846/problem/C for betterunderstanding.
bool compare(pair<int,pii>p1,pair<int,pii>p2)
{
	if(p1.ff>p2.ff)return 1;//returning 1 means p1 should be before p2
	else if(p1.ff<p2.ff)return 0;
	else if(p1.ss.ff<p2.ss.ff)return 1;
	else if(p1.ss.ff>p2.ss.ff) return 0;
	return p1.ss.ss<p2.ss.ss;
}
void solve()
{
    int n;
    cin>>n;
	vector<pair<int,pii>>p(n);
    for(int i=0;i<n;i++)cin>>p[i].ff>>p[i].ss.ff>>p[i].ss.ss;
	sort(p.begin(),p.end(),compare);//calling comparefn
}
int32_t main()
{  
   fast;
   int t;
   cin>>t;
   //t=1;
   while(t--)
   {
   	 solve();
   }
>>>>>>> 7e6cd662e37840bd34f10b10c451c511b832d055
}