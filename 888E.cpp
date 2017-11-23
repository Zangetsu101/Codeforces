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
#define tr(c,i) for(auto i=(c).begin();i!=(c).end();i++)
#define trr(c,i) for(decltype((c).rbegin()) i=(c).rbegin();i!=(c).rend();i++)

using namespace std;

#define N 36
//#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int n,mod;
int data[N];
vector<int> v1,v2;

void gen(int idx,int v)
{
	if(idx==(n+1)/2)
	{
		v1.push_back(v);
		return;
	}
	gen(idx+1,v);
	gen(idx+1,(v+data[idx])%mod);
}

void gen2(int idx,int v)
{
	if(idx==n)
	{
		v2.push_back(v);
		return;
	}
	gen2(idx+1,v);
	gen2(idx+1,(v+data[idx])%mod);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	cin>>n>>mod;
	for(int i=0;i<n;i++)
		cin>>data[i],data[i]%=mod;
	gen(0,0);
	gen2((n+1)/2,0);
	sort(all(v1));
	auto itr=unique(all(v1));
	v1.resize(itr-v1.begin());
	int ans=0;
	tr(v2,it)
	{
		ans=max(ans,*it);
		int idx=upper_bound(all(v1),(mod-1)-*it)-v1.begin();
		idx--;
        ans=max(ans,*it+v1[idx]);
		idx=upper_bound(all(v1),(2*mod-1)-*it)-v1.begin();
		idx--;
        ans=max(ans,(*it+v1[idx])%mod);
	}
	cout<<ans<<endl;
	return 0;
}
