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

#define N 1001
#define mod 998244353
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

ll dp[N];
int data[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("Input.txt","r",stdin); 
	//freopen("Output.txt","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>data[i];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+dp[1])%mod;
		ll temp=dp[0];
		for(int j=0;j<n;j++)
			dp[j]=(dp[j]+dp[j+1])%mod;
		if(data[i]>0&&data[i]<N)
			dp[data[i]]+=(temp+1)%mod;	
	}
	cout<<ans<<endl;
	return 0;
}