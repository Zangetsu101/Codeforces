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

struct node
{
	ll a;
	ll t;

	bool operator<(node x)
	{
		return t<x.t;
	}
}data[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	int n,t;
	cin>>n>>t;
	double av=0;
	for(int i=0;i<n;i++)
		cin>>data[i].a;
	for(int i=0;i<n;i++)
	{
		cin>>data[i].t,data[i].t-=t;
		if(data[i].t>0)
			av+=data[i].a*data[i].t;
	}
	sort(data,data+n);
	double taken=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(data[i].t>=0)
			break;
	}
	int tt=i;
	double ans=0;
	for(i=tt-1;i>=0;i--)
	{
		double d=av/(abs(data[i].t));
		double temp=abs(min(d,(double)data[i].a)*data[i].t);
		ans+=min(d,(double)data[i].a);
		av-=temp;
		taken+=temp;
	}
	for(i=tt;i<n;i++)
	{
		if(data[i].t==0)
		{
			ans+=data[i].a;
			continue;
		}
		double d=taken/data[i].t;
		double temp=min(d,(double)data[i].a)*data[i].t;
		ans+=min(d,(double)data[i].a);
		taken-=temp;
	}
	cout<<fixed<<setprecision(8)<<ans<<endl;
	return 0;
}

