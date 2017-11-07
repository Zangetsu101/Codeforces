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

#define N 200001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

vector< vi > adj(N);
int start[N],finish[N];
int st[8*N];
int lazy[8*N];
int value[N];
int t=1,n;

void update(int node,int l,int r,int i,int j)
{
	int mid=(l+r)>>1;
	lazy[node]%=2;
	if(lazy[node])
	{
		st[node]=r-l+1-st[node];
		if(l!=r)
			lazy[node*2]++,lazy[node*2+1]++;
		lazy[node]=0;
	}
	if(i>r||j<l)
		return;
	if(i<=l&&j>=r)
	{
		st[node]=r-l+1-st[node];
		if(l!=r)
			lazy[node*2]++,lazy[node*2+1]++;
		return;
	}
	update(node*2,l,mid,i,j);
	update(node*2+1,mid+1,r,i,j);
	st[node]=st[node*2]+st[node*2+1];
}

int query(int node,int l,int r,int i,int j)
{
	int mid=(l+r)>>1;
	lazy[node]%=2;
	if(lazy[node])
	{
		st[node]=r-l+1-st[node];
		if(l!=r)
			lazy[node*2]++,lazy[node*2+1]++;
		lazy[node]=0;
	}
	if(i>r||j<l)
		return 0;
	if(i<=l&&j>=r)
		return st[node];
	return query(node*2,l,mid,i,j)+query(node*2+1,mid+1,r,i,j);
}

void dfs(int node,int p)
{
	start[node]=t;
	if(value[node])
		update(1,1,2*n,t,t);
	t++;
	for(int i=0;i<adj[node].size();i++)
	{
		if(adj[node][i]!=p)
			dfs(adj[node][i],node);
	}
	finish[node]=t;
	if(value[node])
		update(1,1,2*n,t,t);
	t++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int a;
		cin>>a;
		adj[a].push_back(i+1);
		adj[i+1].push_back(a);
	}
	for(int i=1;i<=n;i++)
		cin>>value[i];
	dfs(1,0);
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		string str;
		int a;
		cin>>str>>a;
		if(str=="get")
			cout<<query(1,1,2*n,start[a],finish[a])/2<<endl;
		else
			update(1,1,2*n,start[a],finish[a]);
	}
	return 0;
}
