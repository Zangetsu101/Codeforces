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

ll dp[65][2];
vi s,x;

ll solve(int idx,bool carryNeeded)
{
	ll& res=dp[idx][carryNeeded];
	if(res!=-1)
		return res;
	if(idx==sizeof(ll)*8)
	{
		if(carryNeeded)
			res=0;
		else
			res=1;
		return res;
	}
	ll a=solve(idx+1,true);
	ll b=solve(idx+1,false);
	if(carryNeeded)
	{
		if(!s[idx]&&!x[idx])
			res=b;
		else if(s[idx]&&!x[idx])
			res=a;
		else if(!s[idx]&&x[idx])
			res=2*a;
		else
			res=0;
	}
	else
	{
		if(!s[idx]&&!x[idx])
			res=b;
		else if(!s[idx]&&x[idx])
			res=0;
		else if(s[idx]&&!x[idx])
			res=a;
		else
			res=2*b;
	}
	return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	ms(dp,-1);
	ll a,b,ans;
	cin>>a>>b;
	if(a==b)
		ans=-2;
	else
		ans=0;
	for(int i=0;i<sizeof(a)*8;i++)
		s.push_back(a%2),a/=2;
	for(int i=0;i<sizeof(b)*8;i++)
		x.push_back(b%2),b/=2;
	reverse(all(s)),reverse(all(x));
	ans+=solve(0,false);
	cout<<ans<<endl;
	return 0;
}
