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

#define N 100
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int dp[2][20001];
int t[N+1],w[N+1];
const int offset=10000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	ms(dp[0],63);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i]>>w[i];
	int v=0;
	dp[0][offset]=0;
	for(int i=1;i<=n;i++)
	{
		v=i&1;
		ms(dp[v],63);
		for(int j=0;j<=2*offset;j++)
		{
			if(j+t[i]<=2*offset)
				dp[v][j+t[i]]=min(dp[v][j+t[i]],dp[v^1][j]+t[i]);
			if(j-w[i]>=0)
				dp[v][j-w[i]]=min(dp[v][j-w[i]],dp[v^1][j]);
		}
	}
	int ans=inf;
	for(int i=offset;i<=2*offset;i++)
		ans=min(ans,dp[v][i]);
	cout<<ans<<endl;
	return 0;
}
