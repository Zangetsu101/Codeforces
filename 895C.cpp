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

#define N 71
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int dp[N][1<<19];
int primeDivisors[N];
int data[N];

int power(int x)
{
	int res=1;
	int a=2;
	while(x)
	{
		if(x&1)
			res=(1LL*res*a)%mod;
		a=(1LL*a*a)%mod;
		x>>=1;
	}
	return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	for(int i=2;i<N;i++)
	{
		for(int j=0;j<19&&primes[j]<=i;j++)
		{
			int temp=i;
			int cnt=0;
			while(temp%primes[j]==0)
				temp/=primes[j],cnt++;
			if(cnt&1)
				primeDivisors[i]|=1<<j;
		}
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		data[a]++;
	}
	dp[0][0]=1;
	for(int i=1;i<N;i++)
	{
		int x=0;
		if(data[i])
			x=power(data[i]-1);
		for(int j=0;j<(1<<19);j++)
		{
			dp[i][j]=dp[i-1][j];
			if(x)
			{
				dp[i][j]=(dp[i][j]+(1LL*dp[i-1][j^primeDivisors[i]]*x)%mod)%mod;
				dp[i][j]=(dp[i][j]+(1LL*dp[i-1][j]*(x-1))%mod)%mod;
			}
		}
	}
	cout<<dp[N-1][0]-1<<endl;
	return 0;
}
