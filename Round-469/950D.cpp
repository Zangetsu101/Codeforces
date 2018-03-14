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

ll func(ll a,ll d,bool first,ll n,ll k,ll at)
{
	if(n==1)
		return at;
	if(first)
	{
		ll t=((k-a)/d+2)/2;
		if(a+(2*t-2)*d==k)
			return at+t-1;
		if(n%2)
			return func(a+d,d*2,false,n/2,k,at+(n-n/2));
		else
			return func(a+d,d*2,true,n/2,k,at+n/2);
	}
	ll t=((k-a)/d+1)/2;
	if(a+(2*t-1)*d==k)
		return at+t-1;
	if(n%2)
		return func(a,d*2,true,n-n/2,k,at+n/2);
	else
		return func(a,d*2,false,n/2,k,at+n/2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	ll n;
	int q;
	cin>>n>>q;
	for(int i=0;i<q;i++)
	{
		ll a;
		cin>>a;
		cout<<func(1,1,true,n,a,1)<<endl;
	}
	return 0;
}
