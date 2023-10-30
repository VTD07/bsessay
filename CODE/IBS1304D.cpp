#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
using namespace std;
typedef long long l2;
l2 n,d;
l2 legendre(l2 a,l2 n)
{
    l2 kq=0;
    while(n>0)
    {
        kq+=n/a;
        n/=a;
    }
    return kq;
}
l2 result(l2 n)
{
    l2 l=0,r=n*5,ans=0;
    while(l<=r)
    {
        l2 m=l+r>>1;
        if(legendre(5,m)>=n)
        {
            ans=m,r=m-1;
        }
        else l=m+1;
    }
    return ans;
}
signed main ()
{
    cin.tie(NULL),cout.tie(NULL) -> sync_with_stdio(false);
    cin>>n;
    while(n--)
    {
        cin>>d;
        cout<<result(d)<<'\n';
    }
}
