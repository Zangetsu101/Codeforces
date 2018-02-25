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
#include <bitset>

#define endl "\n"
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
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

#define N 100001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

ll power(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res*=a,res%=mod;
        a*=a;
        a%=mod;
        b>>=1;
    }
    return res;
}

ll modInverse(ll a)
{
    return power(a,mod-2);
}

int a[N],b[N];
ll dp[N];
int n,m;

ll func(int pos)
{
    if(pos==n+1)
        return 0;
    ll &ans=dp[pos];
    if(ans!=-1)
        return dp[pos];
    if(a[pos]&&b[pos])
    {
        if(a[pos]<b[pos])
            return ans=0;
        else if(a[pos]>b[pos])
            return ans=1;
        else
            return ans=func(pos+1);
    }
    if(!a[pos]&&!b[pos])
        return ans=((modInverse(m)*func(pos+1))%mod+(((m-1)*modInverse(2*m))%mod))%mod;
    if(!a[pos])
        return ans=((modInverse(m)*func(pos+1))%mod+((m-b[pos])*modInverse(m))%mod)%mod;
    if(!b[pos])
        return ans=((modInverse(m)*func(pos+1))%mod+((a[pos]-1)*modInverse(m))%mod)%mod;
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    cin>>n>>m;
    ms(dp,-1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    cout<<func(1)<<endl;
    return 0;
}
