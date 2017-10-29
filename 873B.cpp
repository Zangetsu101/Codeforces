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

int dp[2*N];
const int shift=N-1;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ms(dp,63);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	int n;
	cin>>n;
	string str;
	cin>>str;
	dp[0+shift]=0;
	int cnt=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,i-dp[cnt-(i-cnt)+shift]);
		cnt+=str[i]-'0';
		dp[cnt-(i+1-cnt)+shift]=min(dp[cnt-(i+1-cnt)+shift],i+1);
	}
	ans=max(ans,n-dp[cnt-(n-cnt)+shift]);
	cout<<ans<<endl;
	return 0;
}
