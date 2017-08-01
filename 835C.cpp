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

#define N 100001
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

ll dp[101][101][11];
ll temp[11];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,q,mod;
    cin>>n>>q>>mod;
    mod++;
    for(int i=0;i<n;i++)
    {
        int x,y,b;
        cin>>x>>y>>b;
        dp[x][y][b]++;
    }
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            for(int k=0;k<=10;k++)
                dp[i][j][k]=dp[i][j][k]+dp[i-1][j][k]+dp[i][j-1][k]-dp[i-1][j-1][k];
        }
    }
    for(int i=0;i<q;i++)
    {
        ll t;
        int x1,y1,x2,y2;
        cin>>t>>x1>>y1>>x2>>y2;
        for(int j=0;j<=10;j++)
            temp[j]=dp[x2][y2][j]-dp[x1-1][y2][j]-dp[x2][y1-1][j]+dp[x1-1][y1-1][j];
        ll ans=0;
        for(int j=0;j<=10;j++)
            ans+=temp[j]*((j+t)%mod);
        cout<<ans<<endl;
    }
    return 0;
}
