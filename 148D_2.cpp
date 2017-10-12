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

#define N 1001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

double dp[N][N][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int w,b;
    cin>>w>>b;
    dp[0][0][1]=dp[0][0][0]=0;
    for(int i=1;i<=w;i++)
        dp[i][0][0]=1,dp[i][0][1]=0;
    for(int i=1;i<=b;i++)
        dp[0][i][0]=0,dp[0][i][1]=0;
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=b;j++)
        {
            dp[i][j][0]=1.0*i/(i+j)+1.0*j/(i+j)*dp[i][j-1][1];
            dp[i][j][1]=1.0*j/(i+j)*i/(i+j-1)*dp[i-1][j-1][0];
            if(j>=2)
                dp[i][j][1]+=1.0*j/(i+j)*(j-1)/(i+j-1)*dp[i][j-2][0];
        }
    }
    cout<<fixed<<setprecision(9)<<dp[w][b][0]<<endl;
    return 0;
}
