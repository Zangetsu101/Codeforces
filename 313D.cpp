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

#define N 301
#define mod 1000000007
#define inf 1e15

typedef long long ll;
typedef unsigned long long ull;

ll dp[N][N];
ll cost[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cost[i][j]=inf;
	}
	for(int i=0;i<N;i++)
		dp[0][i]=inf;
	int n,m,k;
	cin>>n>>m>>k;
	dp[0][0]=0;
	for(int i=1;i<=m;i++)
	{
		int l,r;
		ll c;
		cin>>l>>r>>c;
		for(int j=l;j<=r;j++)
			cost[l][j]=min(cost[l][j],c);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=dp[i-1][j];
			for(int l=1;l<=i;l++)
			{
				if(j>=(i-l+1))
					dp[i][j]=min(dp[i][j],dp[l-1][j-(i-l+1)]+cost[l][i]);
			}
		}
	}
	ll ans=inf;
	for(int i=k;i<=n;i++)
		ans=min(ans,dp[n][i]);
	if(ans!=inf)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
