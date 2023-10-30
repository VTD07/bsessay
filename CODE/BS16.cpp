#include<bits/stdc++.h>
#define cbit(n,i) ((n>>i)&1)
using namespace std;
typedef long long l2;
const int nmax=1e6+9;
int n,d;
bool nt[nmax];
vector<int> prime;
void setup()
{
    memset(nt,true,sizeof(nt));
    nt[0]=nt[1]=false;
    for(int i=2;i<=sqrt(nmax-9);i++)
    {
        if(nt[i]==true) 
        {
            for(int j=i*i;j<=nmax-9;j+=i) 
            {
                nt[j]=false;
            }
        }
    }
    for(int i=2;i<=nmax-9;i++) if(nt[i]) prime.emplace_back(i);
}
l2 result(int d)
{
    int l=0,r=prime.size()-1;
    int pos1=0,pos2=0;
    while(l<=r)
    {
        int m=l+r>>1;
        if(prime[m]>d)
        {
            pos1=m,r=m-1;
        }
        else l=m+1;
    }
    l=0,r=prime.size()-1;
    while(l<=r)
    {
        int m=l+r>>1;
        if(prime[m]>=prime[pos1]+d)
        {
            pos2=m,r=m-1;
        }
        else l=m+1;
    }
    return (1ll*prime[pos2]*prime[pos1]);
}
signed main ()
{
    setup();
    n=1;
    while(n--)
    {
        cin>>d;
        cout<<result(d)<<'\n';
    }
}