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

#define N 1000001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int dp[N];
int data[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	int n;
	cin>>n;
	int maxn=0;
	for(int i=0;i<n;i++)
		cin>>data[i];
	maxn=data[n-1];
	int ans=0;
	for(int i=n-1;i>=0;i--)
	{
		dp[data[i]]=1;
		int j=2;
		while(data[i]*j<=maxn)
			dp[data[i]]=max(dp[data[i]],1+dp[data[i]*j]),j++;
		ans=max(ans,dp[data[i]]);
	}
	cout<<ans<<endl;
	return 0;
}
