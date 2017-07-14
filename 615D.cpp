#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <queue>
#include <stack>

#define endl "\n"
#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d %d",&a,&b)
#define sfff(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b)
#define pf printf
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define all(c) c.begin(),c.end()
#define ms(a,c) memset(a,c,sizeof(a))
#define tr(c,i) for(decltype((c).begin()) i=(c).begin();i!=(c).end();i++)
#define trr(c,i) for(decltype((c).rbegin()) i=(c).rbegin();i!=(c).rend();i++)

using namespace std;

#define N 200001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

ll data[N];
ll value[4*N];

ll modPower(ll a,ll b,ll m)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res*=a,res%=m;
        a*=a;
        a%=m;
        b>>=1;
    }
    return res;
}

void build(int node,int l,int r)
{
    int mid=(l+r)>>1;
    if(l==r)
    {
        value[node]=1;
        return;
    }
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    value[node]=1;
}

void update(int node,int l,int r,int pos,int v)
{
    int mid=(l+r)>>1;
    if(pos<l||pos>r)
        return;
    if(pos<=l&&pos>=r)
    {
        value[node]=v;
        return;
    }
    update(node*2,l,mid,pos,v);
    update(node*2+1,mid+1,r,pos,v);
    value[node]=(value[node*2]*value[node*2+1])%(mod-1);
}

ll query(int node,int l,int r,int i,int j)
{
    int mid=(l+r)>>1;
    if(i>r||j<l)
        return 1;
    if(i<=l&&j>=r)
        return value[node];
    return (query(node*2,l,mid,i,j)*query(node*2+1,mid+1,r,i,j))%(mod-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    build(1,1,N-1);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        data[a]++;
    }
    for(int i=2;i<N;i++)
    {
        if(data[i])
            update(1,1,N-1,i,data[i]+1);
    }
    ll ans=1;
    for(int i=2;i<N;i++)
    {
        if(data[i])
        {
            ll p=query(1,1,N-1,1,i-1)*query(1,1,N-1,i+1,N-1);
            p%=mod-1;
            p*=(data[i]*(data[i]+1)/2)%(mod-1);
            p%=mod-1;
            ans*=modPower(i,p,mod);
            ans%=mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
