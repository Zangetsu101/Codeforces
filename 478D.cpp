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

int dp[2][200001];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int r,g;
    cin>>r>>g;
    dp[0][0]=1;
    int lim=1;
    int sum=0;
    while(sum<=r+g)
        sum+=lim,lim++;
    lim-=2;
    int v;
    for(int i=1;i<=lim;i++)
    {
        v=i&1;
        for(int j=0;j<=min(r,i*(i+1)/2);j++)
        {
            dp[v][j]=0;
            if(i+i*(i-1)/2-j<=g)
                dp[v][j]=dp[v^1][j];
            if(j>=i)
                dp[v][j]=(1LL*dp[v][j]+dp[v^1][j-i])%mod;
        }
    }
    int ans=0;
    for(int i=0;i<=r;i++)
        ans=(1LL*ans+dp[v][i])%mod;
    cout<<(1LL*ans+mod)%mod<<endl;
    return 0;
}
