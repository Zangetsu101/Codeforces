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

#define N 3001
#define mod 1000000007
#define inf 1e15

typedef long long ll;
typedef unsigned long long ull;

ll s[N],c[N],dp[N][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
        cin>>c[i];
    ms(dp,63);
    dp[0][0]=c[0];
    ll ans=inf;
    for(int i=1;i<n;i++)
    {
        dp[i][0]=c[i];
        for(int j=0;j<i;j++)
        {
            if(s[j]<s[i])
            {
                dp[i][1]=min(dp[i][1],dp[j][0]+c[i]);
                dp[i][2]=min(dp[i][2],dp[j][1]+c[i]);
            }
        }
        ans=min(ans,dp[i][2]);
    }
    if(ans==inf)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}