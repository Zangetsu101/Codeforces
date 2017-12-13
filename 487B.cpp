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
#define inf 1000000009

typedef long long ll;
typedef unsigned long long ull;

int value[4*N][2];
int data[N],lvalue[N];
int n,s,l;

void build(int node,int l,int r)
{
	int mid=(l+r)>>1;
	if(l==r)
	{
		value[node][0]=inf;
		value[node][1]=-inf;
		return;
	}
	build(node<<1,l,mid);
	build(node<<1^1,mid+1,r);
	value[node][0]=inf;
	value[node][1]=-inf;
}

void update(int node,int l,int r,int pos,int v)
{
	int mid=(l+r)>>1;
	if(pos<l||pos>r)
		return;
	if(pos<=l&&pos>=r)
	{
		value[node][0]=value[node][1]=v;
		return;
	}
	update(node<<1,l,mid,pos,v);
	update(node<<1^1,mid+1,r,pos,v);
	value[node][0]=min(value[node<<1][0],value[node<<1^1][0]);
	value[node][1]=max(value[node<<1][1],value[node<<1^1][1]);
}

int query(int node,int i,int j,int lim,int mini,int maxi)
{
	int mid=(i+j)>>1;
	if(i>lim)
		return n+1;
	if(i==j)
	{
		mini=min(mini,value[node][0]);
		maxi=max(maxi,value[node][1]);
		if(maxi-mini<=s)
			return i;
		return n+1;
	}
	if(max(maxi,value[node<<1^1][1])-min(mini,value[node<<1^1][0])<=s)
	{
		int ans=n+1;
		if(mid<=lim)
			ans=mid+1;
		return min(ans,query(node<<1,i,mid,lim,min(mini,value[node<<1^1][0]),max(maxi,value[node<<1^1][1])));
	}
	return query(node<<1^1,mid+1,j,lim,mini,maxi);
}

int query2(int node,int l,int r,int i,int j)
{
	int mid=(l+r)>>1;
	if(i>r||j<l)
		return inf;
	if(i<=l&&j>=r)
		return value[node][0];
	return min(query2(node<<1,l,mid,i,j),query2(node<<1^1,mid+1,r,i,j));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	cin>>n>>s>>l;
	for(int i=1;i<=n;i++)
		cin>>data[i];
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		update(1,1,n,i,data[i]);
		lvalue[i]=query(1,1,n,i,inf,-inf);
	}
	build(1,0,n);
	update(1,0,n,0,0);
	for(int i=l;i<=n;i++)
	{
		int f=lvalue[i];
		int s=i-l;
		if(f-1>s)
			continue;
		int q=query2(1,0,n,f-1,s);
		if(q!=inf)
			update(1,0,n,i,q+1);
	}
	int ans=query2(1,0,n,n,n);
	if(ans==inf)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
