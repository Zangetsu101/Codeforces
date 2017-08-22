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

#define N 100001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

const int maxi=5200;

int dp[2][201][5201];
bool flag[2][201][5201];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    int f;
    flag[0][0][0]=true;
    for(int i=1;i<=n;i++)
    {
        f=i&1;
        ll v;
        cin>>v;
        int a=0,b=0;
        while(v%2==0)
            v/=2,a++;
        while(v%5==0)
            v/=5,b++;
        for(int j=0;j<=min(i,m);j++)
        {
            for(int k=0;k<=maxi;k++)
            {
                dp[f][j][k]=dp[f^1][j][k];
                flag[f][j][k]=flag[f^1][j][k];
                if(j&&k>=b&&flag[f^1][j-1][k-b])
                    dp[f][j][k]=max(dp[f][j][k],dp[f^1][j-1][k-b]+a),flag[f][j][k]=true;
            }
        }
    }
    int ans=0;
    for(int i=maxi;i>0;i--)
        ans=max(ans,min(i,dp[f][m][i]));
    cout<<ans<<endl;
    return 0;
}
