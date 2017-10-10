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

#define N 5010
//#define mod 1000000000
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int ans[N];
int dp[N][N/2];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("twothree.in","r",stdin);
//    freopen("twothree.out","w",stdout);
    int n,mod;
    cin>>n>>mod;
    for(int i=1;i<=4;i++)
        ans[i]=1%mod;
    dp[1][2]=dp[1][3]=1%mod;
    dp[2][4]=1%mod;
    for(int i=5;i<=n;i++)
    {
        for(int j=i/3;j<=i/2;j++)
            dp[j][i]=(1LL*dp[j-1][i-2]+dp[j-1][i-3])%mod;
        for(int j=i/3;j<=i/2;j++)
            ans[i]=(ans[i]+1LL*dp[j][i]*ans[j])%mod;
    }
    cout<<ans[n]<<endl;
    return 0;
}
