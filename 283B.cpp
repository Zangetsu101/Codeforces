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

#define N 200001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

bool visited[N][2];
ll ans[N][2];
ll data[N];
int n;

ll dfs(int node,bool flag)
{
	if(visited[node][flag]&&!ans[node][flag])
		return -1;
	else if(visited[node][flag])
		return ans[node][flag];
	visited[node][flag]=true;
	if(flag)
	{
		if(node+data[node]>n)
			return ans[node][flag]=data[node];
		ans[node][flag]+=dfs(node+data[node],!flag);
	}
	else
	{
		if(node-data[node]<=0)
			return ans[node][flag]=data[node];
		if(node-data[node]==1)
			return ans[node][flag]=-1;
		ans[node][flag]+=dfs(node-data[node], !flag);
	}
	if(ans[node][flag]<0)
		return ans[node][flag]=-1;
	else
		return ans[node][flag]=data[node]+ans[node][flag];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	cin>>n;
	for(int i=2;i<=n;i++)
		cin>>data[i];
	for(int i=2;i<=n;i++)
	{
		if(!visited[i][false])
			dfs(i,false);
	}
	for(int i=2;i<=n;i++)
	{
		if(ans[i][false]==-1)
			cout<<-1<<endl;
		else
			cout<<i-1+ans[i][false]<<endl;
	}
	return 0;
}
