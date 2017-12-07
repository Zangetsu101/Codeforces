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

int children[N];
int depth[N];
vector< vi > adj(N);
int dp[N][18];
int n;

void dfs(int node,int parent)
{
	dp[node][0]=parent;
	depth[node]=depth[parent]+1;
	for(int i=0;i<adj[node].size();i++)
	{
		if(adj[node][i]!=parent)
			dfs(adj[node][i],node),children[node]+=1+children[adj[node][i]];
	}
}

void preCal()
{
	for(int i=1;(1<<i)<=n;i++)
	{
		for(int j=1;j<=n;j++)
			dp[j][i]=dp[dp[j][i-1]][i-1];
	}
}

int lca(int a,int b)
{
	if(depth[b]>depth[a])
		swap(a,b);
	for(int i=17;i>=0;i--)
	{
		if(depth[dp[a][i]]>=depth[b])
			a=dp[a][i];
	}
	if(a==b)
		return a;
	for(int i=17;i>=0;i--)
	{
		if(dp[a][i]==dp[b][i])
			continue;
		a=dp[a][i],b=dp[b][i];
	}
	return dp[a][0];
}

int lift(int a,int x)
{
	int i=17;
	while(x)
	{
		if((1<<i)<=x)
			x-=(1<<i),a=dp[a][i];
		i--;
	}
	return a;
}

int distance(int a,int b)
{
	return depth[a]+depth[b]-2*depth[lca(a,b)];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);
	preCal();
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int a,b;
		cin>>a>>b;
		if(depth[b]>depth[a])
			swap(a,b);
		int c=lca(a,b);
		int dis=distance(a,b);
		if(dis&1)
			cout<<0<<endl;
		else if(!dis)
			cout<<n<<endl;
		else
		{
			int x=lift(a,dis/2);
			int ans=0;
			if(x==c)
			{
				int l=lift(a,dis/2-1);
				int r=lift(b,dis/2-1);
				ans=n-children[l]-children[r]-2;
			}
			else
			{
				int l=lift(a,dis/2-1);
				ans=children[x]-children[l];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
10
1 2
1 3
2 4
2 5
3 6
3 7
4 8
6 9
6 10
 */
