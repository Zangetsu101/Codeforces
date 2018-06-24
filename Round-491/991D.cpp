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

int power(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
            ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}

int dp[150][4];
char board[2][150];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    scanf("%s",&board[0][1]);
    scanf("%s",&board[1][1]);
    int n=strlen(&board[0][1]);
    for(int i=1;i<=n;i++)
        board[0][i]-='0',board[1][i]-='0';
    for(int i=2;i<=n;i++)
    {
        int mx=0;
        for(int j=0;j<4;j++)
            mx=max(mx,dp[i-2][j]);
        for(int j=0;j<4;j++)
            dp[i][j]=max(dp[i][j],mx);
        mx=0;
        for(int j=0;j<4;j++)
            mx=max(mx,dp[i][j]);
        dp[i+1][0]=max(dp[i+1][0],mx);
        if(board[0][i]+board[0][i-1]==0&&board[1][i]==0)
            dp[i+1][3]=max(dp[i+1][3],max(dp[i][0],dp[i][1])+1);
        if(board[1][i]+board[1][i-1]==0&&board[0][i]==0)
            dp[i+1][3]=max(dp[i+1][3],max(dp[i][0],dp[i][2])+1);
        if(board[0][i]+board[0][i-1]==0&&board[1][i-1]==0)
            dp[i+1][2]=max(dp[i+1][2],dp[i][0]+1);
        if(board[1][i]+board[1][i-1]==0&&board[0][i-1]==0)
            dp[i+1][1]=max(dp[i+1][1],dp[i][0]+1);
    }
    int ans=0;
    for(int i=0;i<4;i++)
        ans=max(ans,dp[n+1][i]);
    cout<<ans<<endl;
    return 0;
}