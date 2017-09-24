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

int power(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}

int data[N];
int dp[N][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    ms(dp,63);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>data[i];
    if(data[1]>=0)
        dp[1][0]=1;
    else
        dp[1][0]=0;
    for(int i=2;i<=n;i++)
    {
        if(data[i]<0)
        {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
        }
        else if(data[i]>0)
        {
            dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
            dp[i][0]=dp[i-1][0]+1;
        }
        else
            dp[i][0]=dp[i-1][0]+1,dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
    }
    cout<<dp[n][1]<<endl;
    return 0;
}
