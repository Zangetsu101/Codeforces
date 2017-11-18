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
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

const int shift=50000;

int dp[N][100001];
int taste[N],calorie[N];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	ms(dp,-1);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>taste[i];
	for(int i=0;i<n;i++)
		cin>>calorie[i],calorie[i]*=k;
	dp[0][shift]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0; j<=2*shift; j++)
		{
			if(dp[i][j]==-1)
				continue;
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			if(j+taste[i]-calorie[i]>=0&&j+taste[i]-calorie[i]<=2*shift)
				dp[i+1][j+taste[i]-calorie[i]]=max(dp[i+1][j+taste[i]-calorie[i]],dp[i][j]+taste[i]);
		}
	}
	int ans=dp[n][shift];
	if(!ans)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
