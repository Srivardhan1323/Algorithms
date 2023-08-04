#include <bits/stdc++.h>
using namespace std;
void quicksort(int left,int right,vector<int>&v)
{
    if(left>=right)return ;
    int pivot=left;
    int l=left,r=right;
    while(l<r)
    {
        if(v[l]>pivot && v[r]<v[pivot])
        {
            swap(v[l],v[r]);
        }
        if(v[l]<v[pivot])l++;
        if(v[r]>=v[pivot])r--;
    }
    swap(v[pivot],v[l]);
    quicksort(left,l-1,v);
    quicksort(l+1,right,v);
}
int  main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    quicksort(0,n-1,v);
    // for(auto it:v)cout<<it<<" ";
    
}