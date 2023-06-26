#include <bits/stdc++.h>
using namespace std;
#define int long long
/*******************************************************************************************************************************
 a%m     = (a%m + m)%m ->if a is negative
(a+b)%m = (a%m+b%m)%m
(a-b)%m = (a%m-(b%m)+m)%m
(a*b)%m = ((a%m)*(b%m))%m;
(a/b)%m = ((a%m)*(b^-1%m))%m
********************************************************************************************************************************/
int mod=1e9+7;
int binexp(int x,int n)   // O(logn)
{
	int res=1;
	while(n!=0){
		if(n%2==1){
			res = ((res%mod)*(x%mod))%mod;
		}
		x = ((x%mod)*(x%mod))%mod;
		n/=2;
	}
	return res;
}
int32_t main()
{
   
}