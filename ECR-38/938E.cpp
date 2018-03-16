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

ll fact[N];
int data[N];
map<int,int> mp;

ll power(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}

ll modInverse(ll a)
{
	return power(a,mod-2);
}

ll nPr(int n,int r)
{
	return (fact[n]*modInverse(fact[n-r]))%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	fact[0]=1;
	for(int i=1;i<N;i++)
		fact[i]=(i*fact[i-1])%mod;
	int n;
	cin>>n;
	int maxi=0;
	for(int i=1;i<=n;i++)
		cin>>data[i],mp[data[i]]++,maxi=max(maxi,data[i]);
	sort(data+1,data+n+1);
	ll ans=0;
	int last=0;
	for(int i=1;i<=n;i++)
	{
		if(data[i]==last)
			continue;
		if(data[i]!=maxi)
		{
			ll temp=(mp[data[i]]*fact[n-i])%mod;
			temp=(temp*nPr(n,i-1))%mod;
			temp=(temp*data[i])%mod;
			ans=(ans+temp)%mod;
		}
		last=data[i];
	}
	cout<<ans<<endl;
	return 0;
}
