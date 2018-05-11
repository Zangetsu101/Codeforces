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

#define N 31
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int dp[N][N][55];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n=30,m=30,c=50;
    ms(dp,63);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            dp[i][j][0]=0;
    }
    dp[1][1][1]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=min(c,i*j);k++)
            {
                if(i*j==k)
                {
                    dp[i][j][k]=0;
                    break;
                }
                for(int l=1;l<i;l++)
                {
                    for(int m=0;m<=k;m++)
                        dp[i][j][k]=min(dp[i][j][k],dp[l][j][m]+dp[i-l][j][k-m]+j*j);
                }
                for(int l=1;l<j;l++)
                {
                    for(int m=0;m<=k;m++)
                        dp[i][j][k]=min(dp[i][j][k],dp[i][l][m]+dp[i][j-l][k-m]+i*i);
                }
            }
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>c;
        cout<<dp[n][m][c]<<endl;
    }
    return 0;
}
