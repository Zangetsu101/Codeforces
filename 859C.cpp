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

#define N 51
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int data[N];
int sum[N];
int dp[N][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>data[i],sum[i]=sum[i-1]+data[i];
    dp[n][0]=data[n];
    for(int i=n-1;i>0;i--)
    {
        dp[i][0]=max(dp[i+1][0],data[i]+dp[i+1][1]);
        dp[i][1]=min(dp[i+1][0],data[i]+dp[i+1][1]);
    }
    cout<<sum[n]-dp[1][0]<<' '<<dp[1][0]<<endl;
    return 0;
}
