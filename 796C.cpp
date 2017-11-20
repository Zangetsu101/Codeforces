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

#define N 300001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int st[4*N];
int data[N];

void build(int node,int l,int r)
{
	int mid=(l+r)>>1;
	if(l==r)
	{
		st[node]=data[l];
		return;
	}
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	st[node]=max(st[node*2],st[node*2+1]);
}

void update(int node,int l,int r,int pos,int x)
{
	int mid=(l+r)>>1;
	if(pos>r||pos<l)
		return;
	if(pos<=l&&pos>=r)
	{
		st[node]+=x;
		return;
	}
	update(node*2,l,mid,pos,x);
	update(node*2+1,mid+1,r,pos,x);
	st[node]=max(st[node*2],st[node*2+1]);
}

vector< vi > adj(N);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>data[i],data[i]+=2;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build(1,1,n);
	int ans=2*inf;
	for(int i=1;i<=n;i++)
	{
		update(1,1,n,i,-2);
		for(int j=0;j<adj[i].size();j++)
			update(1,1,n,adj[i][j],-1);
		ans=min(ans,st[1]);
		for(int j=0;j<adj[i].size();j++)
			update(1,1,n,adj[i][j],+1);
		update(1,1,n,i,+2);
	}
	cout<<ans<<endl;
    return 0;
}
