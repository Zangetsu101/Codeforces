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

#define N 1000001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int n;
vector< vi > value(N);
vector< vector< ll > > sum(N);
int w[N];

void build(int node)
{
	vi l,r;
	if(node*2<=n)
	{
		build(node*2);
		for(int i=0;i<value[node*2].size();i++)
			l.push_back(value[node*2][i]+w[node*2]);
	}
	if(node*2+1<=n)
	{
		build(node*2+1);
		for(int i=0;i<value[node*2+1].size();i++)
			r.push_back(value[node*2+1][i]+w[node*2+1]);
	}
	value[node].resize(l.size()+r.size()+1);
	value[node][0]=0;
	merge(all(l),all(r),value[node].begin()+1);
	sum[node].resize(value[node].size());
	sum[node][0]=0;
	for(int i=1;i<value[node].size();i++)
		sum[node][i]=sum[node][i-1]+value[node][i];
}

ll query(int node,ll h,ll d)
{
	if(d>h)
		return 0;
	int idx=upper_bound(all(value[node]),h-d)-value[node].begin();
	idx--;
	return 1LL*(h-d)*(idx+1)-sum[node][idx];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	int m;
	cin>>n>>m;
	for(int i=2;i<=n;i++)
		cin>>w[i];
	build(1);
	for(int i=0;i<m;i++)
	{
		int node;
		ll h;
		cin>>node>>h;
		ll ans=query(node,h,0);
		ll d=0;
		while(node>1)
		{
			d+=w[node];
			if(d<h)
				ans+=h-d;
			if((node^1)<=n)
				ans+=query(node^1,h,d+w[node^1]);
			node>>=1;
		}
		cout<<ans<<endl;
	}
    return 0;
}
