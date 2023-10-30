#include<bits/stdc++.h>
using namespace std;
typedef long long l2;
const int nmax=1e6+9;
int n,k,a[nmax];
bool check(l2 sum)
{
    l2 s=0;
    int grp=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>sum) return false;
        if(s+a[i]>sum)
        {
            grp++;
            s=0;
        }
        s+=a[i];
    }
    grp+=s>0;
    return grp<=k;
}
signed main ()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    l2 dau=0,cuoi=1e18,ans=0;
    while(dau<=cuoi)
    {
        l2 mid=(dau+cuoi)>>1;
        if(check(mid))
        {
            ans=mid,cuoi=mid-1;
        }
        else dau=mid+1;
    }
    cout<<ans;
}