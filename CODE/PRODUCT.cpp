#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll nmax=1e6+9;
ll n,m,a[nmax],z=1,b[nmax],h,k,dem=0;pair<ll,ll> c[nmax];
ll tknp(ll dau,ll cuoi,ll x)
{
    while(dau<=cuoi)
    {
        ll mid=(dau+cuoi)/2;
        if(c[mid].first==x) return mid;
        if(c[mid].first<x) dau=mid+1;
        else cuoi=mid-1;
    }
    return 0;
}
signed main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    sort(a+1,a+m+1);sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
    {
        if(b[i]==b[i+1])
        {
            z++;
        }
        else
        {
            c[++h].first=b[i];
            c[h].second=z;
            z=1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(a[i]==0 && k==0) dem+=n;
        else if(a[i]!=0 && k%a[i]==0) dem+=c[tknp(1,h,k/a[i])].second;
    }
    cout<<dem;
}
