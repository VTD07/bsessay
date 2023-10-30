#include<bits/stdc++.h>
#define cbit(n,i) ((n>>i)&1)
using namespace std;
typedef long long l2;
const int nmax=1e6+9;
int n,dem[nmax][3];
l2 kq=0;
string s;
int check(char s)
{
    if('0'<=s && s<='9') return 0;
    if('a'<=s && s<='z') return 1;
    if('A'<=s && s<='Z') return 2;
    return -1;
}
int get(int l,int r,int chiso)
{
    return dem[r][chiso]-dem[l-1][chiso];
}
bool check(int pos,int mid)
{
    if(mid-pos+1<6) return false;
    for(int i=0;i<3;i++)
    {
        if(get(pos,mid,i)==0) return false;
    }
    return true;
}
int chat(int l,int r,int pos)
{
    int ans=-1;
    while(l<=r) 
    {
        int m=l+r>>1;
        if(check(pos,m))
        {
            ans=m,r=m-1;
        }
        else l=m+1;
    }
    return ans;
}
signed main ()
{
    cin>>s;
    n=s.size(),s=' '+s;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++) dem[i][j]=dem[i-1][j];
        dem[i][check(s[i])]=dem[i-1][check(s[i])]+1;
    }
    for(int i=1;i<=n-5;i++)
    {
        int x=chat(i,n,i);
        if(x!=-1)
        {
            kq+=n-x+1ll;
        }
        else break;
    }
    cout<<kq;
}