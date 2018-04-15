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

#define N 5005
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int data[N];
int nodes[N];
int dp[N][2*N];
int ans[2*N];

ll power(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    nodes[1]=1;
    for(int i=1;i<n;i++)
        cin>>data[i],nodes[i+1]=((1LL*nodes[i])*data[i])%mod;
    int i=n-1;
    dp[n][0]=1;
    while(i)
    {
        dp[i][0]=1;
        for(int j=1;j<=2*n;j++)
            dp[i][j]=((1LL*data[i])*dp[i+1][j-1])%mod;
        i--;
    }
    for(i=1;i<=n;i++)
    {
        for(int j=1;j<=2*n;j++)
            ans[j]=(ans[j]+(1LL*nodes[i])*dp[i][j])%mod,dp[i][j]=((1LL*dp[i][j])-dp[i+1][j-1])%mod;
        for(int j=1;j<=2*n;j++)
            dp[i+1][j]=((1LL*dp[i+1][j])+dp[i][j-1])%mod;
    }
    ll p=power(2,mod-2);
    for(i=1;i<=2*n-2;i++)
    {
        ans[i]=((1LL*ans[i])+mod)%mod;
        ans[i]=(ans[i]*p)%mod;
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}
