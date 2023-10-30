#include<bits/stdc++.h>
#define cbit(n,i) ((n>>i)&1)
using namespace std;
typedef long long l2;
const int nmax=1e6+9;
string s;
int n;
bool check(int k)
{
    for(int i=n-k;i<k-1;i++)
    {
        if(s[i]!=s[i+1]) return false;
    }
    return true;
}
int chat(int dau,int cuoi)
{
    int ans=-1;
    while(dau<=cuoi)
    {
        int mid=(dau+cuoi)>>1;
        if(check(mid))
        {
            ans=mid,dau=mid+1;
        }
        else cuoi=mid-1;
    }
    return ans;
}
signed main ()
{
    cin>>s;
    n=s.size();
    cout<<chat(1,n);
}
