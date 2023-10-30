#include<bits/stdc++.h>
using namespace std;
typedef long long l2;
const l2 nmax=1e5+9;
l2 n,m,a[nmax];
l2 xuli(l2 x)
{
    l2 sobo=1,cl=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]-cl>=x)
        {
            cl=a[i],sobo++;
        }
    }
    return sobo;
}
l2 chat(l2 dau,l2 cuoi)
{
    l2 ans=0-1;
    while(dau<=cuoi)
    {
        l2 mid=(dau+cuoi)>>1;
        l2 dem=xuli(mid);
        if(dem>=m)
        {
            ans=mid,dau=mid+1;
        }
        else cuoi=mid-1;
    }
    return ans;
}
signed main ()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<chat(1,1e9);
}
