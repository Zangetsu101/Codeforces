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

#define N 1001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int white[N],black[N];
int dp[N][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    ms(dp,63);
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='.')
                white[j+1]++;
            else
                black[j+1]++;
        }
    }
    for(int i=1;i<=m;i++)
        white[i]=n-white[i],black[i]=n-black[i];
    int wcnt=0,bcnt=0;
//    for(int i=1;i<=x;i++)
//        wcnt+=white[i],bcnt+=black[i];
//    dp[x][0]=wcnt,dp[x][1]=bcnt;
    dp[0][0]=dp[0][1]=0;
    for(int i=x;i<=m;i++)
    {
        wcnt=0,bcnt=0;
        for(int j=1;j<=x;j++)
            wcnt+=white[i-j+1],bcnt+=black[i-j+1];
        for(int j=i-x;j>=0;j--)
        {
            if(i-j>y)
                break;
            dp[i][0]=min(dp[i][0],wcnt+dp[j][1]);
            dp[i][1]=min(dp[i][1],bcnt+dp[j][0]);
            wcnt+=white[j],bcnt+=black[j];
        }
    }
    cout<<min(dp[m][0],dp[m][1])<<endl;
    return 0;
}
