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
#define M 2000
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int dp[N][M+1];
struct something
{
	int t,d,p,id;
	bool operator<(something b)
	{
		return d<b.d;
	}
}item[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>item[i].t>>item[i].d>>item[i].p,item[i].id=i;
	sort(item+1,item+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=M;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=item[i].d)
				continue;
			if(j>=item[i].t)
				dp[i][j]=max(dp[i][j],dp[i-1][j-item[i].t]+item[i].p);
		}
	}
	int ans=0,idx=0;
	for(int i=0;i<=M;i++)
	{
		if(ans<dp[n][i])
			ans=dp[n][i],idx=i;
	}
	cout<<ans<<endl;
	stack<int> s;
	while(idx)
	{
		if(dp[n][idx]==dp[n-1][idx])
			n--;
		else
			s.push(item[n].id),idx-=item[n].t,n--;
	}
	cout<<s.size()<<endl;
	while(!s.empty())
		cout<<s.top()<<' ',s.pop();
	cout<<endl;
	return 0;
}
/*
3
3 9 4
2 3 5
3 6 6
 */
