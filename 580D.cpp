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

#define N 20
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

ll dp[1<<N][N];
ll sat[N];
ll ext[N][N];

int cnt(int a)
{
    int res=0;
    while(a)
    {
        if(a&1)
            res++;
        a>>=1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>sat[i];
    for(int i=0;i<k;i++)
    {
        int a,b;
        ll c;
        cin>>a>>b>>c;
        ext[a][b]=c;
    }
    int mask=0;
    for(int i=0;i<n;i++)
        dp[mask|1<<i][i+1]=sat[i];
    for(int i=1;i<(1<<n);i++)
    {
        mask=i;
        if(cnt(mask)>=m)
            continue;
        for(int j=0;j<n;j++)
        {
            if(!((mask>>j)&1))
            {
                for(int l=1;l<=n;l++)
                {
                    if((mask>>(l-1))&1)
                        dp[mask|1<<j][j+1]=max(dp[mask|1<<j][j+1],dp[mask][l]+sat[j]+ext[l][j+1]);
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=1;j<=n;j++)
            ans=max(dp[i][j],ans);
    }
    cout<<ans<<endl;
    return 0;
}
