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

vi top,bottom;
ll power[19];

ll dp[19][2][2][2];
string ans;

void getdigits(ll a,ll b)
{
	top.clear(),bottom.clear();
	while(a)
		top.push_back(a%10),a/=10;
	while(b)
		bottom.push_back(b%10),b/=10;
	while(bottom.size()<top.size())
		bottom.push_back(0);
	reverse(all(top));
	reverse(all(bottom));
}

ll func(int idx,bool greater,bool lower,bool started)
{
	if(dp[idx][greater][lower][started]!=-1)
		return dp[idx][greater][lower][started];
	if(idx==top.size())
	{
		if(started)
			return dp[idx][greater][lower][started]=1;
		return dp[idx][greater][lower][started]=0;
	}
	if(greater&&lower)
		return dp[idx][greater][lower][started]=power[top.size()-idx];
	int low=greater?0:bottom[idx];
	int high=lower?9:top[idx];
	ll ans=0;
	for(int i=low;i<=high;i++)
		ans=max(ans,(started?i:max(1,i))*func(idx+1,greater||i>bottom[idx],lower||i<top[idx],started||i));
	return dp[idx][greater][lower][started]=ans;
}

void getAnswer(int idx,bool greater,bool lower,bool started)
{
	if(idx==top.size())
		return;
	if(greater&&lower)
	{
		while(idx<top.size())
			ans.push_back('9'),idx++;
		return;
	}
	int high=lower?9:top[idx];
	int low=greater?0:bottom[idx];
	for(int i=low;i<=high;i++)
	{
		if((started?i:max(1,i))*dp[idx+1][greater||i>bottom[idx]][lower||i<top[idx]][started||i]==dp[idx][greater][lower][started])
		{
			ans.push_back(i+'0');
			getAnswer(idx+1,greater||i>bottom[idx],lower||i<top[idx],started||i);
			return;
		}
	}
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	power[0]=1;
	for(int i=1;i<=18;i++)
	power[i]=9*power[i-1];
	ms(dp,-1);
	ll a,b;
	cin>>a>>b;
	getdigits(b,a);
	func(0,false,false,false);
	getAnswer(0,false,false,false);
	int i=0;
	while(ans[i]=='0')
		i++;
	int n=ans.size();
	while(i<n)
		cout<<ans[i++];
	cout<<endl;
	return 0;
}
