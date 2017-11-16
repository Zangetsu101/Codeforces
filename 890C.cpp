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

int n;
int data[N];
int cnt[N];

bool isPossible(int x)
{
	ms(cnt,0);
	x--;
	cnt[0]=1;
	for(int i=0;i<n;i++)
	{
		if(cnt[data[i]])
			cnt[data[i]]--,cnt[i+1]++;
		else if(x)
			x--,cnt[i+1]++;
		else
			return false;
	}
	return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>data[i];
	int low=1,high=n,mid;
	while(low<high)
	{
		mid=(low+high)>>1;
		if(isPossible(mid))
			high=mid;
		else
			low=mid+1;
	}
	cout<<low<<endl;
	return 0;
}
