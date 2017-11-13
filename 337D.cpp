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

vector< vi > adj(N);
bool flag[N];
int subTree[N][2],outerTree[N],p[N];

int dfs(int node,int parent)
{
	subTree[node][0]=subTree[node][1]=-inf;
	p[node]=parent;
	for(int i=0;i<adj[node].size();i++)
	{
		if(adj[node][i]!=parent)
		{
			int temp=dfs(adj[node][i],node)+1;
			if(temp>subTree[node][0])
				subTree[node][1]=subTree[node][0],subTree[node][0]=temp;
			else if(temp>subTree[node][1])
				subTree[node][1]=temp;
		}
	}
	if(flag[node])
	{
		if(subTree[node][0]<0)
			subTree[node][0]=0;
		else
			subTree[node][1]=max(subTree[node][1],0);
	}
	return subTree[node][0];
}

void dfs2(int node,int parent)
{
	outerTree[node]=-inf;
	if(parent)
	{
		if(subTree[parent][0]==subTree[node][0]+1)
			outerTree[node]=subTree[parent][1]+1;
		else
			outerTree[node]=subTree[parent][0]+1;
		outerTree[node]=max(outerTree[node],outerTree[parent]+1);
	}
	for(int i=0;i<adj[node].size();i++)
	{
		if(adj[node][i]!=parent)
			dfs2(adj[node][i],node);
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	int n,m,d;
	cin>>n>>m>>d;
	for(int i=0;i<m;i++)
	{
		int a;
		cin>>a;
		flag[a]=true;
	}
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0),dfs2(1,0);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(subTree[i][0]<=d&&outerTree[i]<=d)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
