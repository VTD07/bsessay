#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const ll nmax=1e6+9;
ll n,a[nmax];
ll t,l,r;
ll tknp1(ll dau,ll cuoi,ll x)
{
    ll ans=0;
    while(dau<=cuoi)
    {
        ll mid=(dau+cuoi)>>1;
        if(a[mid]>=x)
        {
            ans=mid;cuoi=mid-1;
        }
        else dau=mid+1;
    }
    return ans;
}
ll tknp2(ll dau,ll cuoi,ll x)
{
    ll ans=0;
    while(dau<=cuoi)
    {
        ll mid=(dau+cuoi)>>1;
        if(a[mid]<=x)
        {
            ans=mid;dau=mid+1;
        }
        else cuoi=mid-1;
    }
    return ans;
}
signed main ()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        ll x=tknp1(1,n,l);ll y=tknp2(1,n,r);
        cout<<y-x+1<<endl;
    }
}
