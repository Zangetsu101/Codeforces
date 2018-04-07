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

#define N 51
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

double fact[N];
double dp[2][2*N][N][N];
int data[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    fact[0]=1;
    for(int i=1;i<N;i++)
        fact[i]=i*fact[i-1];
    int n,l;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
        cin>>data[i],sum+=data[i];
    cin>>l;
    if(sum<=l)
    {
        cout<<n<<endl;
        return 0;
    }
    dp[0][0][0][0]=1;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        int v=i&1;
        memcpy(dp[v],dp[v^1],sizeof(dp[v]));
        mx=max(mx,data[i]);
        for(int j=0;j<2*N;j++)
        {
            for(int k=0;k<=mx;k++)
            {
                for(int m=0;m<=i;m++)
                {
                    if(j+data[i]<2*N)
                    {
                        dp[v][j+data[i]][data[i]][m+1]+=dp[v^1][j][k][m];
                        dp[v][j+data[i]][k][m+1]+=m*dp[v^1][j][k][m];
                    }
                }
            }
        }
    }
    int v=n&1;
    double ans=0;
    for(int i=l+1;i<2*N;i++)
    {
        for(int j=1;j<=mx;j++)
        {
            for(int m=1;m<=n;m++)
            {
                if(i-j<=l)
                    ans+=(1.0*dp[v][i][j][m]*(m-1)*fact[n-m]);
            }
        }
    }
    cout<<fixed<<setprecision(6)<<ans/fact[n]<<endl;
    return 0;
}
