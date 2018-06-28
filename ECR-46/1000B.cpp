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

ll lvalue[N],rvalue[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("Input.txt","r",stdin); 
	//freopen("Output.txt","w",stdout);
	vector<ll> v;
	v.push_back(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		if(!a)
			continue;
		v.push_back(a);
	}	
	if(v.back()<m)
		v.push_back(m);
	ll ans=0;
	for(int i=1;i<v.size();i++)
	{
		if(i%2)
			ans+=v[i]-v[i-1];
		if(i%2)
			lvalue[i]=lvalue[i-1]+v[i]-v[i-1];
		else
			lvalue[i]=lvalue[i-1];
	}
	for(int i=v.size()-2;i>=0;i--)
	{
		if(i%2)
			rvalue[i]=rvalue[i+1]+v[i+1]-v[i];
		else
			rvalue[i]=rvalue[i+1];
	}
	for(int i=1;i<v.size();i++)
		ans=max(ans,lvalue[i]-1+rvalue[i]);
	cout<<ans<<endl;
	return 0;
}
		
