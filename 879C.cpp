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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	char arr[]={'|','&','^'};
	int n;
	cin>>n;
	int a=0,b=1023;
	for(int i=0;i<n;i++)
	{
		char ch;
		int c;
		cin>>ch>>c;
		if(ch=='|')
			a|=c,b|=c;
		else if(ch=='&')
			a&=c,b&=c;
		else
			a^=c,b^=c;
	}
	int ans[3];
	ans[0]=0,ans[1]=1023,ans[2]=0;
	for(int i=0;i<10;i++)
	{
		if((a&1)==(b&1)&&(a&1))
			ans[0]|=1<<i;
		else if((a&1)==(b&1))
			ans[1]&=~(1<<i);
		else if(a&1)
			ans[2]|=1<<i;
		a>>=1,b>>=1;
	}
	cout<<3<<endl;
	for(int i=0;i<3;i++)
		cout<<arr[i]<<' '<<ans[i]<<endl;
	return 0;
}
