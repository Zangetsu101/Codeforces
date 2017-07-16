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

#define N 1005
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int data[N][N];
int dp1[N][N];
int dp2[N][N],dp3[N][N],dp4[N][N];
int n,m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    cin>>n>>m;
    int mini=inf,ix,iy;
    int midx=ix,midy=iy;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>data[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            dp1[i][j]=data[i][j]+max(dp1[i-1][j],dp1[i][j-1]);
    }
    for(int i=n;i>0;i--)
    {
        for(int j=m;j>0;j--)
            dp2[i][j]=data[i][j]+max(dp2[i][j+1],dp2[i+1][j]);
    }
    for(int i=n;i>0;i--)
    {
        for(int j=1;j<=m;j++)
            dp3[i][j]=data[i][j]+max(dp3[i][j-1],dp3[i+1][j]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>0;j--)
            dp4[i][j]=data[i][j]+max(dp4[i-1][j],dp4[i][j+1]);
    }
    int ans=0;
    for(int i=2;i<n;i++)
    {
        for(int j=2;j<m;j++)
        {
            ans=max(ans,dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1]);
            ans=max(ans,dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
