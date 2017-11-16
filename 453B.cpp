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

#define N 101
#define mod 1000000007
#define inf 1061109567

typedef long long ll;
typedef unsigned long long ull;

int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int primeDivisors[61];
int data[N];
int dp[N][1<<17];
int pre[N][1<<17];
int value[N][1<<17];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	ms(dp,63);
	for(int i=2;i<60;i++)
	{
		for(int j=0;j<17&&primes[j]<=i;j++)
		{
			if(i%primes[j]==0)
				primeDivisors[i]|=1<<j;
		}
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>data[i];
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<60;j++)
		{
			int mask=~primeDivisors[j]&((1<<17)-1);
			for(int k=mask;;k=(k-1)&mask)
			{
				if(dp[i][k|primeDivisors[j]]>dp[i-1][k]+abs(data[i]-j))
				{
					dp[i][k|primeDivisors[j]]=dp[i-1][k]+abs(data[i]-j);
					pre[i][k|primeDivisors[j]]=k;
					value[i][k|primeDivisors[j]]=j;
				}
				if(!k)
					break;
			}
		}
	}
	stack<int> ans;
	int mask=0,v=inf;
	for(int i=0;i<(1<<17);i++)
	{
		if(dp[n][i]<v)
			v=dp[n][i],mask=i;
	}
	for(int i=n;i>0;i--)
	{
		ans.push(value[i][mask]);
		mask=pre[i][mask];
	}
	while(!ans.empty())
		cout<<ans.top()<<' ',ans.pop();
	cout<<endl;
	return 0;
}
