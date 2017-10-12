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

#define N 101
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

double dp[N][N][N][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int r,s,p;
    cin>>r>>s>>p;
    for(int i=1;i<=p;i++)
        dp[0][0][i][2]=1;
    for(int i=1;i<=r;i++)
    {
        dp[i][0][0][0]=1;
        for(int j=1;j<=s;j++)
            dp[i][j][0][0]=1;
        for(int j=1;j<=p;j++)
            dp[i][0][j][2]=1;
    }
    for(int i=1;i<=s;i++)
    {
        dp[0][i][0][1]=1;
        for(int j=1;j<=p;j++)
            dp[0][i][j][1]=1;
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=s;j++)
        {
            for(int k=1;k<=p;k++)
            {
                dp[i][j][k][0]=(2.0*i/(i+j+k)*j/(i+j+k-1)*dp[i][j-1][k][0]+2.0*i/(i+j+k)*k/(i+j+k-1)*dp[i-1][j][k][0]+2.0*j/(i+j+k)*k/(i+j+k-1)*dp[i][j][k-1][0])/(1-(1.0*i*(i-1)+j*(j-1)+k*(k-1))/((i+j+k)*(i+j+k-1)));
                dp[i][j][k][1]=(2.0*i/(i+j+k)*j/(i+j+k-1)*dp[i][j-1][k][1]+2.0*i/(i+j+k)*k/(i+j+k-1)*dp[i-1][j][k][1]+2.0*j/(i+j+k)*k/(i+j+k-1)*dp[i][j][k-1][1])/(1-(1.0*i*(i-1)+j*(j-1)+k*(k-1))/((i+j+k)*(i+j+k-1)));
                dp[i][j][k][2]=(2.0*i/(i+j+k)*j/(i+j+k-1)*dp[i][j-1][k][2]+2.0*i/(i+j+k)*k/(i+j+k-1)*dp[i-1][j][k][2]+2.0*j/(i+j+k)*k/(i+j+k-1)*dp[i][j][k-1][2])/(1-(1.0*i*(i-1)+j*(j-1)+k*(k-1))/((i+j+k)*(i+j+k-1)));
            }
        }
    }
    cout<<fixed<<setprecision(9)<<dp[r][s][p][0]<<' '<<dp[r][s][p][1]<<' '<<dp[r][s][p][2]<<endl;
    return 0;
}
