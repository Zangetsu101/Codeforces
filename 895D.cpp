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

ll fact[N],invFact[N];
int cnt[26];
int n;
string down,up,str;

ll modPower(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)
			res*=a,res%=mod;
		a*=a;
		a%=mod;
		b>>=1;
	}
	return res;
}

ll modInverse(ll a)
{
	return modPower(a,mod-2);
}

ll solve(int idx,ll value,bool isLower)
{
	ll ans=0;
	if(idx==n)
	{
		if(isLower)
			return 1;
		return 0;
	}
	if(isLower)
		return (fact[n-idx]*value)%mod;
	int high=str[idx]-'a';
	ll temp=value;
	for(int i=0;i<=high;i++)
	{
		if(cnt[i])
		{
			temp=(temp*fact[cnt[i]])%mod;
			temp=(temp*invFact[cnt[i]-1])%mod;
			cnt[i]--;
			ans+=solve(idx+1,temp,i<high);
			ans%=mod;
			cnt[i]++;
			temp=value;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	fact[0]=invFact[0]=1;
	for(int i=1;i<N;i++)
		fact[i]=(i*fact[i-1])%mod,invFact[i]=modInverse(fact[i]);
	cin>>down>>up;
	n=down.size();
	for(int i=0;i<n;i++)
		cnt[down[i]-'a']++;
	ll value=1;
	for(int i=0;i<26;i++)
		value=(value*invFact[cnt[i]])%mod;
	str=down;
	ll ans=solve(0,value,false);
	str=up;
	ans=solve(0,value,false)-ans;
	cout<<(ans-1+mod)%mod<<endl;
	return 0;
}
