#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr,int l,int mid,int h)
{
    vector<int>a;
    int l1=l,l2=mid+1;
    while(l1<=mid && l2<=h)
    {
        if(arr[l1]>=arr[l2])
        {
            a.push_back(arr[l2]);
            l2++;
        }
        else
        {
            a.push_back(arr[l1]);
            l1++;
        }
    }
    if(l1<=mid)
    {
        for(int i=l1;i<=mid;i++)a.push_back(arr[i]);
    }
    if(l2<=h)
    {
        for(int i=l2;i<=h;i++)a.push_back(arr[i]);
    }
    for(int i=l;i<=h;i++)
    {
        arr[i]=a[i-l];
    }
}
void mergeSort(vector<int>& arr, int l, int r)
{
   if(l==r)return ;
   int mid=(l+r)>>1;
   mergeSort(arr,l,mid);
   mergeSort(arr,mid+1,r);
   merge(arr,l,mid,r); 
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    mergeSort(arr,0,n-1);
}