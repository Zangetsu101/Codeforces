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

#define N 21
#define mod 1000000007
#define inf 2139062143

typedef long long ll;
typedef unsigned long long ull;
typedef vector< vi > matrix;
int dp[2][N][N];
int a[N],b[N];
int n,m;

int add(int a,int b)
{
	if(a==inf||b==inf)
		return inf;
	return a+b;
}

void multiply(matrix &a,matrix b)
{
	matrix temp(n+1,vi(n+1,inf));
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
//				temp[i][j]=min(temp[i][j],a[i][k]+b[k][j]);
				for(int l=0;l<=n;l++)
				{
					if(k>=l&&j+k-l>=0&&j+k-l<=n)
						temp[i][j+k-l]=min(temp[i][j+k-l],add(a[i][k],b[l][j]));
					if(l>=k&&i+l-k>=0&&i+l-k<=n)
						temp[i+l-k][j]=min(temp[i+l-k][j],add(a[i][k],b[l][j]));
				}
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			a[i][j]=temp[i][j];
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	int v=0;
	ms(dp[0],127);
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		v=i&1;
		ms(dp[v],127);
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=i;k++)
			{
				if(k+1<=i)
					dp[v][j][k+1]=min(dp[v][j][k+1],add(dp[v^1][j][k],a[i]));
				if(k)
					dp[v][j][k-1]=min(dp[v][j][k-1],add(dp[v^1][j][k],b[i]));
				else
					dp[v][j+1][k]=min(dp[v][j+1][k],add(dp[v^1][j][k],b[i]));
			}
		}
	}
	matrix a(n+1,vi(n+1,inf));
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			a[i][j]=dp[v][i][j];
	}
	matrix res(n+1,vi(n+1,inf));
	res[0][0]=0;
	while(m)
	{
		if(m&1)
			multiply(res,a);
		multiply(a,a);
		m>>=1;
	}
	cout<<res[0][0]<<endl;
}
