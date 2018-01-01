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

#define N 5005
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

const int p=29;

ll Hash[N],rHash[N];
ll pr[N];
string str;

int getHash(int i,int j)
{
	if(i<=j)
	{
		ll ans=Hash[j];
		ans-=(Hash[i-1]*pr[j-i+1])%mod;
		ans=(ans+mod)%mod;
		return ans;
	}
	ll ans=rHash[j];
	ans-=(rHash[i+1]*pr[i-j+1])%mod;
	ans=(ans+mod)%mod;
	return ans;
}

int preCal()
{
	pr[0]=1;
	for(int i=1;i<N;i++)
		pr[i]=(pr[i-1]*p)%mod;
	int n=str.size();
	for(int i=1;i<=n;i++)
		Hash[i]=(Hash[i-1]*p+str[i-1]-'a'+1)%mod;
	for(int i=n;i>0;i--)
		rHash[i]=(rHash[i+1]*p+str[i-1]-'a'+1)%mod;
	return n;
}

bool isPalindrome(int i,int j)
{
	return getHash(i,j)==getHash(j,i);
}

int dp[N][N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	cin>>str;
	int n=preCal();
	for(int i=1;i<=n;i++)
		dp[i][i]=1;
	for(int i=n-1;i>0;i--)
	{
		for(int j=i+1;j<=n;j++)
			dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1]+isPalindrome(i,j);
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int a,b;
		cin>>a>>b;
		cout<<dp[a][b]<<endl;
	}
	return 0;
}
