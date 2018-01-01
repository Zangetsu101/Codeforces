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

#define N 500010
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int dp[N][4];
int value[N][4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,l;
    cin>>n>>l;
    string str,t;
    str.push_back('*');
    cin>>t;
    str+=t;
    ms(dp,63);
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        if(str[i]!=str[i-1])
            dp[i][0]=dp[i-1][0],value[i][0]=0;
        for(int j=1;j<=min(3,l);j++)
        {
            if(str[i]!='A'+j-1&&dp[i-1][j]<dp[i][0])
                dp[i][0]=dp[i-1][j],value[i][0]=j;
        }
        for(int j=1;j<=min(3,l);j++)
        {
            if(str[i-1]!='A'+j-1)
                dp[i][j]=dp[i-1][0]+1,value[i][j]=0;
            for(int k=1;k<=min(3,l);k++)
            {
                if(j!=k&&dp[i-1][k]+1<dp[i][j])
                    dp[i][j]=dp[i-1][k]+1,value[i][j]=k;
            }
        }
    }
    int ans=inf,idx=-1;
    for(int i=0;i<min(4,1+l);i++)
    {
        if(ans>dp[n][i])
            ans=dp[n][i],idx=i;
    }
    cout<<ans<<endl;
    for(int i=n;i>0;i--)
    {
        if(idx)
            str[i]='A'+idx-1;
        idx=value[i][idx];
    }
    for(int i=1;i<=n;i++)
        cout<<str[i];
//    cout<<str;
    cout<<endl;
    return 0;
}
