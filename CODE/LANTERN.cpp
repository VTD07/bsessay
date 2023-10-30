#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll nmax=1e6+9;
ll n,m,a[nmax],dau=1,cuoi=1e18,kq=0;
bool kt(ll k)
{
    ll t=0;
    for(int i=1;i<=m;i++)
    {
        if(a[i]%k==0) t+=a[i]/k;
        else t+=(a[i]/k)+1;
    }
    return t<=n;
}
signed main ()
{
    fast;
    cin>>n>>m;
    for(int i=1;i<=m;i++) 
    {
        cin>>a[i];
    }
    while(dau<=cuoi)
    {
        ll mid=dau+cuoi>>1;
        if(kt(mid))
        {
            kq=mid;
            cuoi=mid-1;
        }
        else dau=mid+1;
    }
    cout<<kq;
}