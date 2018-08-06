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

#define N 5500
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int a[N];
int dp[N];

void kmp(string str)
{
	int n=str.size();
	int j=0;
	a[0]=0;
	for(int i=1;i<n;i++)
	{
		if(str[i]==str[j])
			a[i]=++j;
		else if(j)
			i--,j=a[j-1];
		else
			a[i]=0;
	}
	j=0;
	while(str[j]!='*')
		j++;
	j++;
	for(int i=0;j<n;i++,j++)
		a[i]=a[j];
}

pii ans[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("Input.txt","r",stdin); 
	//freopen("Output.txt","w",stdout);
	ms(dp,63);
	string s,t,sr;
	cin>>sr>>t;
	s=sr;
	reverse(all(sr));
	int n=s.size();
	int m=t.size();
	dp[0]=0;
	for(int i=0;i<m;i++)
	{
		string str;
		for(int j=i;j>=0;j--)
			str.push_back(t[j]);
		kmp(str+'*'+s);
		for(int j=0;j<n;j++)
		{
			if(dp[i+1]>1+dp[i+1-a[j]])
				dp[i+1]=1+dp[i+1-a[j]],ans[i+1]=pii(j+2-a[j],j+1);
		}
		kmp(str+'*'+sr);
		for(int j=0;j<n;j++)
		{
			if(dp[i+1]>1+dp[i+1-a[j]])
				dp[i+1]=1+dp[i+1-a[j]],ans[i+1]=pii(n+1-(j+2-a[j]),n+1-(j+1));
		}
	}
	if(dp[m]<inf)
		cout<<dp[m]<<endl;
	else
	{
		cout<<-1<<endl;
		return 0;
	}
	int i=m;
	stack<pii> st;
	while(i>0)
	{
		st.push(pii(ans[i].second,ans[i].first));
		i=i-(abs(ans[i].first-ans[i].second)+1);
	}
	while(!st.empty())
		cout<<st.top().first<<' '<<st.top().second<<endl,st.pop();
	return 0;
}