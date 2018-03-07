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

#define N 501
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int power(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}

vector< vi > v(N);
int dp[N][N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	ms(dp,63);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		for(int j=0;j<m;j++)
		{
			if(str[j]=='1')
				v[i].push_back(j);
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		int temp[k+1];
		ms(temp,63);
		for(int j=0;j<=k;j++)
		{
			int start=0,end=start+v[i].size()-1-j;
			while(start<=end&&end<v[i].size())
				temp[j]=min(temp[j],v[i][end]-v[i][start]+1),start++,end++;
			if(start>end)
				temp[j]=0;
		}
		for(int j=0;j<=k;j++)
		{
			for(int l=0;l<=j;l++)
				dp[i][j]=min(dp[i][j],temp[l]+dp[i-1][j-l]);
		}
	}
	int ans=inf;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=k;j++)
//			cout<<dp[i][j]<<' ';
//		cout<<endl;
//	}
	for(int i=0;i<=k;i++)
		ans=min(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}
