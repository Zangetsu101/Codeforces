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

int modPower(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=(1LL*res*a)%mod;
		a=(1LL*a*a)%mod;
		b>>=1;
	}
	return res;
}

int modInverse(int a)
{
	return modPower(a,mod-2);
}

int fact[N],inv[N];
int ways[2001];

int nCr(int n,int r)
{
	return (((1LL*fact[n]*inv[r])%mod)*inv[n-r])%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	fact[0]=1,inv[0]=1;
	for(int i=1;i<N;i++)
		fact[i]=(1LL*i*fact[i-1])%mod,inv[i]=modInverse(fact[i]);
	int h,w;
	cin>>h>>w;
	int n;
	cin>>n;
	vii v;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v.push_back(pii(a,b));
	}
	int ans=nCr(h+w-2,h-1);
	sort(all(v));
	for(int i=0;i<n;i++)
		ways[i]=nCr(v[i].first+v[i].second-2,v[i].first-1);
	for(int i=0;i<n;i++)
	{
		ans=(ans-(1LL*ways[i]*nCr(h+w-v[i].first-v[i].second,h-v[i].first))%mod)%mod;
		for(int j=i+1;j<n;j++)
		{
			if(v[j].second>=v[i].second)
				ways[j]=(ways[j]-(1LL*ways[i]*nCr(v[j].first+v[j].second-v[i].first-v[i].second,v[j].first-v[i].first))%mod)%mod;
		}
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}
